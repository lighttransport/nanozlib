#include <cstdint>
#include <cstring>
#include <memory>
#include <vector>
#include <limits>

#define NANOZLIB_IMPLEMENTATION
#include "nanozlib.h"

static int compress_fuzz_main(const uint8_t *data, size_t size) {

  if (size < 1) {
    return -1;
  }

  if (size > std::numeric_limits<int32_t>::max()) {
    return -1;
  }

  int quality = 8; // TODO: Read quality parameter from fuzz data.

  int compress_len = 0;
  void *compress = nanoz_compress(reinterpret_cast<unsigned char *>(const_cast<uint8_t *>(data)), int(size), &compress_len, quality);
  if (compress) {
    free(compress);
  }

  return 0;

}

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const* data,
                                      std::size_t size) {
  return compress_fuzz_main(data, size);
}

