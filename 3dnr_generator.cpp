#include <Halide.h>
#include <stdio.h>
#include <stdlib.h>

using namespace Halide;

class TDNRGenerator : public Halide::Generator<TDNRGenerator> {
public:
    Input<Buffer<uint8_t>[8]> input{"input", 3};
    Input<int> num{"number_of_input"};
    Input<int> width{"width"};
    Input<int> height{"height"};
    Output<Buffer<uint8_t>> output{"output", 3};

    Var n, x, y, c;
    Var i, j, ii, jj, ti, tj; 
    Var xt, yt, xid, yid;

    void generate() {

        Func inputs;
        inputs(n, x, y, c) = 0.f;
        for (int i = 0; i < 8; i++) {
            Func im = BoundaryConditions::repeat_edge(input[i], {{0,width}, {0,height}});
            inputs(i, x, y, c) = cast<float>(im(x, y, c)) / 255.f;
        }

        Func blocks("blocks");
        blocks(n, i, j, ii, jj, c) = inputs(n, 4*i+ii, 4*j+jj, c);

        Func dist("dist"), mag("mag"), avg("avg"), weight("weight");
        Func res_block("res_block");
        RDom r1(0, 4, 0, 4);
        RDom r2(0, 8, -1, 3, -1, 3);

        // Calculate distance between last image with others
        dist(n, ti, tj, xt, yt, c) = sum(pow(blocks(n    , ti, tj, r1.x, r1.y, c) - 
                                             blocks(num-1, xt, yt, r1.x, r1.y, c), 2));

        // Calculate magitude of center block to average of blocks
        avg(n, ti, tj ,c) = sum(blocks(n, ti, tj, r1.x, r1.y, c)); 
        mag(n, ti, tj ,c) = abs(16.f * blocks(n, ti, tj, 1, 1, c) - 
                                avg(n, ti, tj, c)) / 15.f; 
        
        // If the difference is larger, the weight is smaller
        weight(n, ti, tj, xt, yt, c) = exp(-3.f * dist(n, ti, tj, xt, yt, c) * 
                                        select(mag(n, ti, tj, c) < 0.5f, 1.f, 2.f));
        
        // Combine each blocks with their weights
        res_block(xt, yt, xid, yid, c) = sum(blocks(r2.x, xt+r2.y, yt+r2.z, xid, yid, c) * 
                                             weight(r2.x, xt+r2.y, yt+r2.z, xt, yt, c)) / 
                                         sum(weight(r2.x, xt+r2.y, yt+r2.z, xt, yt, c));
                               
        output(x, y, c) = cast<uint8_t>(res_block(x/4, y/4, x%4, y%4, c)*255.f);
        
        // Schedule
        blocks.compute_root().parallel(n);
        res_block.compute_root().parallel(yt).vectorize(xt, 16).bound(xid,0,4).bound(yid,0,4);
        output.compute_root().parallel(y).vectorize(x, 16).bound(c,0,3);
    }

};
HALIDE_REGISTER_GENERATOR(TDNRGenerator, threednr)