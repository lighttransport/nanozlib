/* SPDX-License-Identifier: Apache 2.0 */

/* TODO:
 *
 * - [ ] Stream decoding API
 * - [ ] Encoding API
 *   - [ ] Stream encoding API
 *
 *
 */

#ifndef NANOZDEC_H_
#define NANOZDEC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum nanoz_status {
  NANOZ_SUCCESS = 0,
  NANOZ_ERROR = -1, // general error code.
  NANOZ_ERROR_INVALID_ARGUMENT = -2,
} nanoz_status_t;

nanoz_status_t nanoz_uncompress(const unsigned char *src_addr,
                                const uint64_t src_size,
                                unsigned char *dst_addr,
                                uint64_t *uncompressed_size);


#ifdef __cplusplus
}
#endif

#if defined(NANOZDEC_IMPLEMENTATION)

#define WUFFS_IMPLEMENTATION

#define WUFFS_CONFIG__STATIC_FUNCTIONS

#define WUFFS_CONFIG__MODULES
#define WUFFS_CONFIG__MODULE__BASE
#define WUFFS_CONFIG__MODULE__CRC32
#define WUFFS_CONFIG__MODULE__ADLER32
#define WUFFS_CONFIG__MODULE__DEFLATE
#define WUFFS_CONFIG__MODULE__ZLIB

#include "wuffs-v0.3.c"

nanoz_status_t nanoz_uncompress(const unsigned char *src_addr,
                                const uint64_t src_size,
                                unsigned char *dst_addr,
                                uint64_t *uncompressed_size) {

  if (!src_addr) {
    return NANOZ_ERROR_INVALID_ARGUMENT;
  }

  if (src_size < 4) {
    return NANOZ_ERROR_INVALID_ARGUMENT;
  }

  if (!dst_addr) {
    return NANOZ_ERROR_INVALID_ARGUMENT;
  }

  if (!uncompressed_size) {
    return NANOZ_ERROR_INVALID_ARGUMENT;
  }

  // TODO
  return NANOZ_ERROR;
}

#endif  // NANOZDEC_IMPLEMENTATION

#endif /* NANOZDEC_H_ */
