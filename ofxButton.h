#pragma once

#include "ofMain.h"
#include <iostream>
#include <string>
#include <algorithm>

class ofxButton {
public:
  ofxButton();
  void set(int _x,int _y,int _w,int _h,ofColor& _backcolor,ofColor& _wordcolor,ofTrueTypeFont& _font,std::string _text);
  bool isfocus(void);
  bool run(void);

private:
  int x, y, w, h;
  ofColor backcolor, wordcolor;
  ofTrueTypeFont font;
  std::string text;
  
  bool clicktriger;
};