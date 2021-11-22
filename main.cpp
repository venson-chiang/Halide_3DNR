#include <Halide.h>
#include <halide_image_io.h>
#include <iostream>
#include "bin/host/threednr.h"

using namespace Halide;
using namespace Halide::Tools;

#define unroll_array_of_8_buffers(buff_name) \
    buff_name[0],\
    buff_name[1],\
    buff_name[2],\
    buff_name[3],\
    buff_name[4],\
    buff_name[5],\
    buff_name[6],\
    buff_name[7]

int main(int argc, char** argv) {

    int num = std::stoi(argv[1]);
    std::cout << "base image = " << num << std::endl;
    Halide::Runtime::Buffer<uint8_t> images[8];
    for (int i = 0; i < 8; i++) {
        images[i] = load_image("input_images/noisy_sequence_0" + 
                                std::to_string(i+1) + ".png");
    }
    int width = images[0].width();
    int height = images[0].height();
    std::cout << "input image size = " << width << ", " << height << std::endl;

    Halide::Runtime::Buffer<uint8_t> output(width, height, 3);
    threednr(unroll_array_of_8_buffers(images), num, width, height, output);
    save_image(output, "output_images/noisy_sequence_0"+std::to_string(num)+"_3dnr.png");
    
    printf("Sucess!!\n");
    return 0;
}