#include "ofApp.h"

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
  cout << "Load font\n";
  {
    ofTrueTypeFontSettings fontsetting("Cica.ttf", 32);
    fontsetting.addRanges(ofAlphabet::Latin);
    fontsetting.addRanges(ofAlphabet::Japanese);

    buttonfont.load(fontsetting);
  }

  /*button vars set*/
  buttonset();
}

//--------------------------------------------------------------
void ofApp::buttonset() {
  welcome.set(100, 100, 200, 200, ofColor(200, 200, 200), ofColor(50, 50, 50), buttonfont, u8"‚ ‚¢‚¤‚¦‚¨");
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  if (welcome.run()) {
    cout << "isclick\n";
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

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
