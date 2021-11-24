#include "mini_core/main_core.h"
#include "Teensy.h"

const char file_name[] = __FILE__;
const char compile_date[] = __DATE__;
const char compile_time[] = __TIME__;



int main() {
  init();
  Serial.println(String("Thank you for using my custom core for Teensy 4.x!\nCompilation Informations:\n") +"File Name: " + String(file_name) + "\n" + "Compilation Date: " + String(compile_date) + "\n" + "Compilation Time: " + String(compile_time));
  for (;;) {
    loop();
  }
  return 0;
}