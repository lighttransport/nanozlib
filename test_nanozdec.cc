#define NANOZDEC_IMPLEMENTATION
#include "nanozdec.h"

#include <cstdio>
#include <cstdlib>

#include <iostream>

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "test compressed_data.bin uncompresed_size\n";
  }
  return EXIT_SUCCESS;
}
