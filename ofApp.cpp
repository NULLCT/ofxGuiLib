#include "ofApp.h"
/*view closstile*/
#define ALPHA
//--------------------------------------------------------------
void ofApp::setup() {
  /*of setting*/
  ofSetBackgroundColor(222, 222, 222);
  ofSetFrameRate(60);
  ofSetWindowTitle("ISBNCTRLSYSV1.0 | Made by NULLCT | MIT LICENSE");
  ofSetLineWidth(1);
  ofSetEscapeQuitsApp(false);

  /*font setting*/
  ofTrueTypeFontSettings fontsettings("JKGM.ttf", 24);
  fontsettings.addRanges(ofAlphabet::Latin);
  fontsettings.addRanges(ofAlphabet::Japanese);
  font.load(fontsettings);

  /*load logo*/
  ifstream ifs("logo.txt");
  if (ifs.fail()){
    cout << "ERROR:fail load logo." << endl;
  }

  /*screen setting*/
  screen = 0;

  /*buttons_cluster setting*/
  /*temp2
  buttons_cluster[0].button_beginx = 0;
  buttons_cluster[0].button_beginy = 0;
  buttons_cluster[0].button_endx = 0;
  buttons_cluster[0].button_endy = 0;
  buttons_cluster[0].button_r = 0;
  buttons_cluster[0].button_g = 0;
  buttons_cluster[0].button_b = 0;
  buttons_cluster[0].button_wordr = 0;
  buttons_cluster[0].button_wordg = 0;
  buttons_cluster[0].button_wordb = 0;
  buttons_cluster[0].button_word = "";
  buttons_cluster[0].button_enable=false;
  */
  buttons_cluster.resize(256);
  /*Error button*/
  buttons_cluster[0].button_beginx = 0;
  buttons_cluster[0].button_beginy = 0;
  buttons_cluster[0].button_endx = 1280;
  buttons_cluster[0].button_endy = 720;
  buttons_cluster[0].button_r = 235;
  buttons_cluster[0].button_g = 52;
  buttons_cluster[0].button_b = 52;
  buttons_cluster[0].button_wordr = 255;
  buttons_cluster[0].button_wordg = 255;
  buttons_cluster[0].button_wordb = 255;
  buttons_cluster[0].button_word = u8"ERROR!!!!\n致命的なエラーが発生しました!!!!\nERROR:エラーコードがないエラー\nCODE:_(:3」∠)_";
  buttons_cluster[0].button_enable = false;
  /*管理者としてログイン*/
  buttons_cluster[1].button_beginx = 50;
  buttons_cluster[1].button_beginy = 50;
  buttons_cluster[1].button_endx = 540;
  buttons_cluster[1].button_endy = 620;
  //buttons_cluster[1].button_r = 235;
  //buttons_cluster[1].button_g = 52;
  //buttons_cluster[1].button_b = 52;
  //buttons_cluster[1].button_wordr = 255;
  //buttons_cluster[1].button_wordg = 255;
  //buttons_cluster[1].button_wordb = 255;
  buttons_cluster[1].button_word = u8"管理者としてログイン";
  buttons_cluster[1].button_enable = false;
  /*委員としてログイン*/
  buttons_cluster[2].button_beginx = 50;
  buttons_cluster[2].button_beginy = 50;
  buttons_cluster[2].button_endx = 540;
  buttons_cluster[2].button_endy = 620;
  //buttons_cluster[2].button_r = 235;
  //buttons_cluster[2].button_g = 52;
  //buttons_cluster[2].button_b = 52;
  //buttons_cluster[2].button_wordr = 255;
  //buttons_cluster[2].button_wordg = 255;
  //buttons_cluster[2].button_wordb = 255;
  buttons_cluster[2].button_word = u8"委員としてログイン";
  buttons_cluster[2].button_enable = false;
  //1280, 720,
  /*font sentering*/
  for (int counter = 0; counter < buttons_cluster.size(); counter++) {
    buttons_cluster[counter].button_fontx = ((buttons_cluster[counter].button_beginx * 2 + buttons_cluster[counter].button_endx) / 2) - (font.stringWidth(buttons_cluster[counter].button_word) / 2);
    buttons_cluster[counter].button_fonty = ((buttons_cluster[counter].button_beginy * 2 + buttons_cluster[counter].button_endx) / 2) + (font.stringHeight(buttons_cluster[counter].button_word) / 2);
  }
  
  /*view logo and hogehoge*/
  string str = "";
  while (getline(ifs, str)) {
    cout << str << endl;
  }
  cout << "All settings complete." << "buttons_cluster:" << buttons_cluster.size() << "width:"<< to_string(ofGetWidth())<<"height:"<< to_string(ofGetHeight()) <<endl;
}

//--------------------------------------------------------------
void ofApp::update() {
  switch (screen){//screenの切り替え
  case 0:
    buttons_cluster[1].button_enable = true;
    buttons_cluster[2].button_enable = true;
    break;

  default:
    break;
  }
  mousex = ofGetMouseX();
  mousey = ofGetMouseY();
  for (int counter = 0; counter < buttons_cluster.size(); counter++) {//影の処理
    if ((buttons_cluster[counter].button_beginx <= mousex && buttons_cluster[counter].button_beginy <= mousey) && (buttons_cluster[counter].button_beginx+buttons_cluster[counter].button_endx >= mousex && buttons_cluster[counter].button_beginx+buttons_cluster[counter].button_endy >= mousey)) {
      if (buttons_cluster[counter].button_shadowlengh < 10) {
        buttons_cluster[counter].button_shadowlengh+=2;
      }
    }
    else {
      if (buttons_cluster[counter].button_shadowlengh > 0) {
        buttons_cluster[counter].button_shadowlengh--;
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
/*格子を表示*/
#ifdef ALPHA
  ofSetColor(200, 200, 200);
  ofDrawLine(640, 0, 640, 720);
  ofDrawLine(0, 360, 1280, 360);
#endif
  for (int counter = 0; counter < buttons_cluster.size(); counter++) {
    if (buttons_cluster[counter].button_enable) {
      ofSetColor(0, 0, 0, 100);
      ofDrawRectangle(buttons_cluster[counter].button_beginx + 10, buttons_cluster[counter].button_beginy + 10, buttons_cluster[counter].button_endx + buttons_cluster[counter].button_shadowlengh, buttons_cluster[counter].button_endy + buttons_cluster[counter].button_shadowlengh);
      ofSetColor(buttons_cluster[counter].button_r+10, buttons_cluster[counter].button_g+10, buttons_cluster[counter].button_b+10);
      ofDrawRectangle(buttons_cluster[counter].button_beginx, buttons_cluster[counter].button_beginy, buttons_cluster[counter].button_endx, buttons_cluster[counter].button_endy);
      ofSetColor(buttons_cluster[counter].button_r, buttons_cluster[counter].button_g, buttons_cluster[counter].button_b);
      ofDrawRectangle(buttons_cluster[counter].button_beginx+10, buttons_cluster[counter].button_beginy+10, buttons_cluster[counter].button_endx-20, buttons_cluster[counter].button_endy-20);
      ofSetColor(buttons_cluster[counter].button_wordr, buttons_cluster[counter].button_wordg, buttons_cluster[counter].button_wordb);
      font.drawString(buttons_cluster[counter].button_word, buttons_cluster[counter].button_fontx, buttons_cluster[counter].button_fonty);
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
