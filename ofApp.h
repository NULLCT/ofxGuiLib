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
  bool button_enable = true;//button draw?
  bool button_enablesimplebox = false;//draw simply box
  bool button_enableonlyword = false;//draw only word
  int button_shadowlenght = 0;//shadow lenght
  int button_fontx = 0, button_fonty = 0;//font draw position
  int button_underlinebeginx = 0, button_underlinebeginy = 0, button_underlinelenght = 0;
};
class ofApp : public ofBaseApp {
public:
  void setup();
  void btnsetup();
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

  ofTrueTypeFont font;//font JKGM.ttf
  ofImage piyohiko;//piyohiko piyohiko.png
  vector<vector<buttondate> > btn;//button screen to button
  vector<string> isbnrawlist;//ISBNlist isbrawlist.txt
  vector<string> isbnsoldlist;//ISBNsoldlist isbnsoldlist.txt
  int screen = 0;//screen num
  int frame = 0;//count frame
  int piyohikoy = 0;//piyohiko ypos
  string inputisbn = "";//input isbn

  string screen2_saveerrortext = "";
  int screen2_scrool_begin = 0;//screen2 scrool place
  int screen2_coupon = 0;//count coupon
  int screen2_counterrorbutton = 0;//60 to desapier
  vector<bool> screen2_switcherror;
  /*
    0: 総額よりクーポン減額分のほうが多いです
    1: isbnrawlistの中に入力した物がありませんでした
    2: isbnsoldlistの中に入力した物がありました
  */
  vector<string> screen2_isbndates;//books list in screen2 has{string(isbn),int(sum)}
};
