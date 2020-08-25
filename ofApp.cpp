#include "ofApp.h"
#define DEBUG_SHOWMOUSEPOS
#define DEBUG_NOLOADJAPANESE

//--------------------------------------------------------------
void ofApp::setup() {
  using namespace std;

  /*Load files*/
  // Put logo
  {
    ofBuffer buf = ofBufferFromFile("logo.txt");
    for (auto line : buf.getLines()) {
      cout << line << "\n";
    }
  }
  // isbnraw
  {
    ofBuffer buf = ofBufferFromFile("isbnraw.txt");
    for (auto line : buf.getLines()) {
      isbnraw.push_back(line);
    }
  }
  // isbnsold
  {
    ofBuffer buf = ofBufferFromFile("isbnsold.txt");
    for (auto line : buf.getLines()) {
      isbnsold.push_back(line);
    }
  }
  // isbnsoldtime
  {
    ofBuffer buf = ofBufferFromFile("isbnsoldtime.txt");
    for (auto line : buf.getLines()) {
      isbnsoldtime.push_back(line);
    }
  }
  // isbncoupon
  {
    ofBuffer buf = ofBufferFromFile("isbncoupon.txt");
    for (auto line : buf.getLines()) {
      isbncoupon = stoi(line);
      break;
      // TODO: What the heck this code. I cant use iterator
    }
    if (isbncoupon < 0) { // If isbncoupon is undefined
      isbncoupon = 0;
    }
  }

  // Put sizes
  {
    cout << "isbnraw.size: " << isbnraw.size() << "\n";
    cout << "isbnsold.size: " << isbnsold.size() << "\n";
    cout << "isbnsoldtime.size: " << isbnsoldtime.size() << "\n";
    cout << "isbncoupon: " << isbncoupon << "\n";
  }

  /*Font*/
  cout << "Load font(It may take some time. Solve maze pls)\n";
  {
    //buttonfont
    ofTrueTypeFontSettings fontsetting("Cica.ttf", 32);
    fontsetting.addRanges(ofAlphabet::Latin);
#ifndef DEBUG_NOLOADJAPANESE
    fontsetting.addRanges(ofAlphabet::Japanese);// ISSUE: This is toooooo heavy. idk light way
#endif
    font32jp.load(fontsetting);

    //showunixtimefont
    font16.load("Cica.ttf", 16);
  }

  /*button vars set*/
  buttonSet();
}


//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  if (screen == 0) { // Welcome page
    ofBackground(ofColor(0, 0, 0));
    if (welcome.run()) {
      screen = 1;
    }
  }
  if (screen == 1) { // Sold page
    ofBackground(ofColor(0, 0, 0));
    showISBNList();

  }

  showUnixTime(font16);

#ifdef DEBUG_SHOWMOUSEPOS
  showMousePos(font16);
#endif
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == '0') { isbninputbuf += "0"; }
  if (key == '1') { isbninputbuf += "1"; }
  if (key == '2') { isbninputbuf += "2"; }
  if (key == '3') { isbninputbuf += "3"; }
  if (key == '4') { isbninputbuf += "4"; }
  if (key == '5') { isbninputbuf += "5"; }
  if (key == '6') { isbninputbuf += "6"; }
  if (key == '7') { isbninputbuf += "7"; }
  if (key == '8') { isbninputbuf += "8"; }
  if (key == '9') { isbninputbuf += "9"; }

  if (key == ofKey::OF_KEY_RETURN) {
    isbnlist.push_back(isbninputbuf); // add to isbnlist
    isbninputbuf = "";                // clear isbninputbuf
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

/*Made by myself functions*/

//--------------------------------------------------------------
void ofApp::buttonSet() {
  //Screen 0
  welcome.set(ofGetWidth()/2-200, ofGetHeight()/2-100, 400, 200, ofColor(245, 245, 245), ofColor(0, 0, 0), font32jp, u8"‚¨ŽdŽ–‚ð‚Í‚¶‚ß‚é");

  //Screen 1
  isbnshowlist.resize(5);
  for (int i = 0; i < isbnshowlist.size();i++) {
    isbnshowlist[i].set(50, 50 + i * 100, 550, 64, ofColor(145, 145, 145), ofColor(0, 0, 0), font16, "");
  }

}

//--------------------------------------------------------------
void ofApp::showISBNList() {
  ofSetColor(255, 255, 255, 100);
  for (int i = 1; i < isbnshowlist.size(); i++) { // show patation
    ofDrawLine(40, 32 + i * 100, 610, 32 + i * 100);
  }

  for (auto i : isbnshowlist) { // show isbnlist
    i.run(); 
  }

  ofSetColor(255, 255, 255, 200);
  ofDrawLine(30, 532, 620, 532); // show underline of list



}

//--------------------------------------------------------------
void ofApp::showUnixTime(ofTrueTypeFont& _font) {
  ofSetColor(255, 255, 255, 100);
  _font.drawString("UnixTime: "+to_string(time(NULL)), 0, 15);
}

//--------------------------------------------------------------
void ofApp::showMousePos(ofTrueTypeFont& _font) {
  ofSetColor(255, 255, 255, 100);
  ofDrawLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());// x // line
  ofDrawLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());// y // line

  _font.drawString(to_string(ofGetMouseX()) + ":" + to_string(ofGetMouseY()), 0, ofGetHeight());
}

void ofApp::updateISBNShowList() {

}
