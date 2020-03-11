#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
  /*
   *colors
   *  90 BA FF (brue
   *  6B E8 AF (green
   *  DA FF 82 (yellow
   *  E8 C1 6B (orange
   *  FF 8C 75 (red
   *
   */
  // this kicks off the running of my app
  // can be OF_WINDOW or OF_FULLSCREEN
  // pass in width and height too:
  ofRunApp(new ofApp());

}
