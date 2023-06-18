#include <cstdint>
#include <cstring>
#include <memory>
#include <vector>

#define NANOZLIB_IMPLEMENTATION
#include "nanozlib.h"

static int uncompress_fuzz_main(const uint8_t *data, size_t size) {
  // first 8 bytes: uncompressed size
  // second 8 bytes: compressed size
  // reamaining: compressed data.

  if (size < 16) {
    return -1;
  }

  uint64_t uncompressedSize;
  uint64_t compressedSize;

  memcpy(&uncompressedSize, data, 8);
  memcpy(&compressedSize, data+8, 8);

  // FIXME: Currently up to 4GB
  if ((uncompressedSize < 1) || (uncompressedSize > 1024*1024*4)) {
    return 0;
  }

  if ((compressedSize < 4) || (compressedSize > 1024*1024*4)) {
    return 0;
  }

  if (compressedSize > (size -16)) {
    return 0;
  }

  std::vector<unsigned char> dst;
  dst.resize(uncompressedSize);

  uint64_t uncompressedSizeOut;

  nanoz_status_t s = nanoz_uncompress(reinterpret_cast<const unsigned char *>(data + 8),
                                compressedSize, dst.size(), dst.data(), &uncompressedSizeOut);

  (void)s;

  return 0;

}

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const* data,
                                      std::size_t size) {
  return uncompress_fuzz_main(data, size);
}

