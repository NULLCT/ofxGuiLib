#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  using namespace std;
  /*Load files*/
  //Put logo
  {
    ofBuffer buf = ofBufferFromFile("logo.txt");
    for (auto line : buf.getLines()) { cout << line << "\n"; }
  }

  //isbnraw
  {
    ofBuffer buf = ofBufferFromFile("isbnraw.txt");
    for (auto line : buf.getLines()) { isbnraw.push_back(line); }
  }
  //isbnsold
  {
    ofBuffer buf = ofBufferFromFile("isbnsold.txt");
    for (auto line : buf.getLines()) { isbnsold.push_back(line); }
  }
  //isbnsoldtime
  {
    ofBuffer buf = ofBufferFromFile("isbnsoldtime.txt");
    for (auto line : buf.getLines()) { isbnsoldtime.push_back(line); }
  }

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

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
