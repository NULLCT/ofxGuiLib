#include "ofxNumSetter.h"

void ofxNumSetter::set(int _x, int _y, int _w, int _h, ofColor& _arrowcolor,ofTrueTypeFont& _font) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  arrowcolor = _arrowcolor;
  font = _font;
}

void ofxNumSetter::reset() {
  num = 0;
}

void ofxNumSetter::draw() {
  //draw twice triangle
  ofSetColor(arrowcolor);
  ofDrawTriangle(x, y + h / 2, x + w * 0.2, y, x + w * 0.2, y + h);//left
  ofDrawTriangle((x + w) - w * 0.2, y, (x + w) - w * 0.2, y + h, x + w, y + h / 2);//right

  //draw center box
  ofSetColor(255, 255, 255);
  ofDrawRectangle(x + w * 0.25, y, w * 0.5, h);

  //draw num
  ofSetColor(0, 0, 0);
  font.drawString(to_string(num), (w * 0.5) - font.stringWidth(to_string(num)) / 2 + x + w * 0.5,
    (h + font.stringHeight(to_string(num)) / 2 + y) );
}
