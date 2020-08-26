#pragma once
#include "ofMain.h"

class ofxNumSetter {
public:
  void set(int _x, int _y, int _w, int _h, ofColor _arrowcolor, ofTrueTypeFont& _font);
  void reset();
  void run();
  bool isFocusRightArrow();
  bool isFocusLeftArrow();
  int getNum();

private:
  int num = 0;
  int x, y, w, h;
  bool clicktrigger = false;
  ofColor arrowcolor;
  ofTrueTypeFont font;
};