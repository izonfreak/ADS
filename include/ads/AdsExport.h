
// SPDX-License-Identifier: MIT

/*
 * Definitions of cross-platform defines for symbol export/import.
 */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(_WIN32) && !defined(_NODLL)
#  if defined(_AdsLibDLL)
#    define ADS_EXTERN __declspec(dllexport)
#  elif !defined(_AdsLibStatic)
#    define ADS_EXTERN __declspec(dllimport)
#  else
#    define ADS_EXTERN
#  endif
#else
#  if defined(__GNUC__) && (__GNUC__ >= 4)
#    define ADS_EXTERN __attribute__((visibility("default")))
#  else /* Any other Unix */
#    define ADS_EXTERN
#  endif /* Any other Unix */
#endif /* not _WIN32 */

#if defined(__cplusplus)
}
#endif

