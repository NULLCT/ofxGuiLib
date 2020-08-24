#pragma once

#include "ofMain.h"
#include <time.h>
#include <random>

class Piyo {
public:
  Piyo();
  void run();

private:
  ofImage piyoimage;
  int x, y, w, h;
};