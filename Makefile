include Makefile.inc

.PHONY: build test clean

export LD_LIBRARY_PATH=/mnt/d/Software/Halide-12/distrib/lib

build:$(BIN)/${HL_TARGET}/3dnr.a

$(GENERATOR_BIN)/3dnr.generator: 3dnr_generator.cpp $(GENERATOR_DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -g $(filter %.cpp,$^) -o $@ $(LIBHALIDE_LDFLAGS) -ljpeg -lpng

$(BIN)/%/threednr.a: $(GENERATOR_BIN)/3dnr.generator
	@mkdir -p $(@D)
	$^ -g threednr -o $(@D) -f threednr target=$*

$(BIN)/%/main: main.cpp $(BIN)/%/threednr.a
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(BIN)/$* -Wall -O3 $^ -o $@ $(LDFLAGS) $(IMAGE_IO_FLAGS)

$(BIN)/%/output.png: $(GENERATOR_BIN)/main 
	@mkdir -p $(@D)
	$< 1

test: $(BIN)/${HL_TARGET}/output.png

clean:
	rm -rf $(BIN)