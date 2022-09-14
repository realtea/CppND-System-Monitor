#include <string>
#include <cmath>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hh = floor(seconds / 3600);
  int sec_left = seconds - (hh * 3600);
  int mm = floor(sec_left / 60);
  int ss = sec_left - (mm * 60);

  char elapsedTime[16];
  sprintf(elapsedTime, "%02d:%02d:%02d", hh, mm, ss);

  return string(elapsedTime);
}
