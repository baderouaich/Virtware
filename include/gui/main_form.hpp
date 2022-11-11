/// @file
/// @brief Contains form1 class.
#pragma once
#include <xtd/xtd.forms>
#include <recorder/recorder.hpp>
#include <executor/executor.hpp>

/// @brief Represents the namespace that contains application objects.
namespace Virtware {
  /// @brief Represents the main form.
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the form1 class.
    main_form();
    ~main_form();
    /// @brief The main entry point for the application.
    static void main();

  private:
      std::unique_ptr<Recorder> m_recorder;
      std::unique_ptr<Executor> m_executor;
      std::unique_ptr<xtd::forms::button> m_start_recording_btn;
      std::unique_ptr<xtd::forms::button> m_stop_recording_btn;
      std::unique_ptr<xtd::forms::button> m_play_recording;
      std::unique_ptr<xtd::forms::button> m_save_recording;
      std::unique_ptr<xtd::forms::button> m_load_recording;
      std::unique_ptr<xtd::forms::list_box> m_events_lst;
  };
}
