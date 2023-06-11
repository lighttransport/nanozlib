#define NANOZDEC_IMPLEMENTATION
#include "nanozdec.h"

#include <cstdio>
#include <cstdlib>

#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "test compressed_data.bin uncompresed_size (dump_uncompressed_data)\n";
  }

  bool dump = false;

  // TODO: Use string -> uint64
  std::string filename = argv[1];
  uint64_t uncompressed_size = atoi(argv[2]);

  std::vector<char> uncompressed_data;
  uncompressed_data.resize(uncompressed_size);

  if (argc > 3) {
    dump = true;
  }

  std::ifstream f(filenme.c_str(), std::ifstream::binary);
  if (!f) {
    std::cerr << "File not found or invalid.\n";
    return EXIT_FAILURE;
  }

  f.peek();
  if (!f) {
    std::cerr << "Invalid file.\n";
    return EXIT_FAILURE;
  }

  f.seekg(0, f.end);
  size_t sz = static_cast<size_t>(f.tellg());
  f.seekg(0, f.beg);

  std::vector<unsigned char> src_buf;
  src_buf.resize(sz);

  f.read(src_buf.data(), static_cast<std::streamsize>(sz));

  if (!f) {
    std::cerr << "Failed to read file.\n";
    return EXIT_FAILURE;
  }

  nanoz_status_t ret = nanoz_uncompress(src_buf.data(), sz, uncompresed_size, uncompressed_data.data());
  if (ret != NANOZ_SUCCESS) {
    std::cerr << "nanoz error: " << int(ret) << "\n";
    return EXIT_FAILURE;
  }

  if (dump) {
    std::string s(uncompressed_data.begin(), uncompressed_data.end());
    std::cout << s << "\n";
  }


  return EXIT_SUCCESS;
}
