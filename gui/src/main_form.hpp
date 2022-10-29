/// @file
/// @brief Contains form1 class.
#pragma once
#include <xtd/xtd.forms>

/// @brief Represents the namespace that contains application objects.
namespace virtware {
  /// @brief Represents the main form.
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the form1 class.
    main_form();
    ~main_form();
    /// @brief The main entry point for the application.
    static void main();

  private:
      
      std::unique_ptr<xtd::forms::button> m_new_routine_btn;
  };
}
