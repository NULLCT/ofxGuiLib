#pragma once

#include <time.h>

#include <random>

#include "ofMain.h"

class Piyo {
 public:
  Piyo();
  void run();

 private:
  ofImage piyoimage;
  int x, y, w, h;
  int replaceframe = 60 * 10;
};