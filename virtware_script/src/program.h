/// @file
/// @brief Contains program class.
#pragma once
#include <xtd/ustring.h>
#include <vector>

/// @brief Represents the namespace that contains application objects.
namespace vhelang {
  /// @brief Represents the main class.
  class program {
  public:
    /// @brief The main entry point for the application.
    static void main(const std::vector<xtd::ustring>& args);
  };
}
