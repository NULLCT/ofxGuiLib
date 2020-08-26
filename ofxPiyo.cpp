#include "ofxPiyo.h"

Piyo::Piyo() {
  srand(time(NULL));
  x = rand() % ofGetWidth();
  y = rand() % ofGetHeight();
  w = rand() % 75;
  h = rand() % 75;
  piyoimage.load("Piyo.png");
}

void Piyo::run() {
  if (ofGetFrameNum() % replaceframe == 0) {
    x = rand() % ofGetWidth();
    y = rand() % ofGetHeight();
    w = rand() % 75;
    h = rand() % 75;
  }
  piyoimage.draw(x, y, w, h);
}