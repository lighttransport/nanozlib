CXXFLAGS := -O2 -g

all:
	clang++ -fsanitize=fuzzer,address $(CXXFLAGS) -I../ -o fuzz_zenc fuzz-zenc.cc
	clang++ -fsanitize=fuzzer,address $(CXXFLAGS) -I../ -o fuzz_zdec fuzz-zdec.cc
