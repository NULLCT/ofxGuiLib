#include "ofApp.h"
#define ALPHA
//デバック機能を呼び出すのに必要。
//あとでdefineに依存しない機構を作る
//--------------------------------------------------------------
void ofApp::setup(){
  test.xb=100;
  test.yb=100;
  test.xe=500;
  test.ye=500;
  test.r=0xFF;
  test.g=0x8C;
  test.b=0x75;
  ofSetBackgroundColor(222,222,222);
}

//--------------------------------------------------------------
void ofApp::update(){
#ifdef ALPHA //色々表示
    ofSetWindowTitle(to_string(ofGetMouseX())+"."+to_string(ofGetMouseY())+" "+to_string(ofGetWindowWidth())+"×"+to_string(ofGetWindowHeight())+" "+to_string(ofGetWindowPositionX())+","+to_string(ofGetWindowPositionY()));
#endif
}

//--------------------------------------------------------------
void ofApp::draw(){
  test.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  test.check(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  if(test.moused()){
      ofSetWindowTitle("mouse clicked on test!!");
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
