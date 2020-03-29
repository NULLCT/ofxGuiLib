#pragma once
#include "ofMain.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
class buttondate {
public:
  int button_beginx = 0, button_beginy = 0, button_endx = 0, button_endy = 0;//button position
  int button_r = 141, button_g = 235, button_b = 208;//button color
  int button_wordr = 255, button_wordg = 255, button_wordb = 255;//word color
  string button_word = u8"ERROR!!!!\nエラーが発生しました!!!!\nERROR:class::buttondate.button_wordに\n文字が指定されていません\nCODE:(・o・)";//error message
  bool button_enable = false;//button draw?
  int button_shadowlengh = 0;
  int button_fontx = 0, button_fonty = 0;
};
class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  vector<buttondate> buttons_cluster;//in buttons
  ofTrueTypeFont font;//in font
  int screen = 0;//screen num
  int mousex = 0;
  int mousey = 0;
};
