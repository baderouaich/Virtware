/// @file
/// @brief Contains form1 class.
#pragma once
#include <xtd/xtd.forms>

/// @brief Represents the namespace that contains application objects.
namespace virtware {
  /// @brief Represents the main form.
  class form1 : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the form1 class.
    form1();

    /// @brief The main entry point for the application.
    static void main();
  };
}
