#pragma once

#include "ui/window.h"

namespace simulation {

class control_window : public ui::window {
 public:
  control_window();

  void render(cv::Mat &img) override;

  void on_start() override;
  void on_stop() override;
  void on_closed() override;

  void do_exit();

  void toggle_modes(bool active, ui::button &me);

 private:
  ui::button exit{ui::box{0, 0.1, 1, 0.1}, "Exit", ui::colour{1, 0.75, 0.75}, ui::colour{1, 0.5, 0.5}};

  std::vector<ui::button> mode_buttons;
};

}  // namespace simulation