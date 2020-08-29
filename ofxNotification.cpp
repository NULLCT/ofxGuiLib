#include "ofxNotification.h"

void ofxNotification::set(ofColor _back, ofColor _word, ofTrueTypeFont& _font) {
  back = _back;
  word = _word;
  font = _font;
}

void ofxNotification::notice(string _text) {
  text = _text;

  drawtrigger = true;
  countframe = 0;
  ypos = -font.stringHeight(text);
  alpha = 200;
}

void ofxNotification::draw() {
  if (drawtrigger) {
    countframe++;
    if (countframe <= animelim) {
      ypos /= 1.2;
    }
    else {
      if (animelim * 1.5 < countframe) { drawtrigger = false; }
      alpha /= 1.2;
    }
    ofSetColor(back,alpha);
    ofDrawRectRounded(ofRectangle(100, ypos, ofGetWidth() - 200, 64), 16);
    ofSetColor(word);
    font.drawString(text, ((ofGetWidth()-200)-font.stringWidth(text))/2+100,(64+font.stringHeight(text))/2+ypos);
  }
}