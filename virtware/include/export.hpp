/// @file
/// @brief Contains export.
#pragma once

/// @cond
#if defined(WIN32)
#  if defined(VIRTWARE_EXPORT)
#    define virtware_export_ __declspec(dllexport)
#  else
#    define virtware_export_ __declspec(dllimport)
#  endif
#else
#  if defined(VIRTWARE_EXPORT)
#    define virtware_export_ __attribute__((visibility ("default")))
#  else
#    define virtware_export_
#  endif
#endif
/// @endcond
