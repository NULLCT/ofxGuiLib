#pragma once

#include "ofMain.h"

class ofxNotification {
public:
  void set(ofColor _back, ofColor _word, ofTrueTypeFont& _font);
  void notice(string _text);
  void draw();


private:
  const int animelim = 60 * 2;

  bool drawtrigger = false;

  int countframe;
  int ypos;
  int alpha;

  ofColor back, word;
  ofTrueTypeFont font;
  string text;
};