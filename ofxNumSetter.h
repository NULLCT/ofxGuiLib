#pragma once
#include "ofMain.h"

class ofxNumSetter {
public:
  void set(int _x, int _y, int _w, int _h, ofColor& _arrowcolor, ofTrueTypeFont& _font);
  void reset();
  void draw();

private:
  int num = 0;
  int x, y, w, h;
  ofColor arrowcolor;
  ofTrueTypeFont font;
};