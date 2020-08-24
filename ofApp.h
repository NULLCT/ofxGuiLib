#pragma once
#include "ofMain.h"
#include "ofxButton.h"
#include "ofxPiyo.h"
/*
TODO:
  ofApp.h:30:
    ‘‚«o‚µ‚Ìcsv‚É‚Â‚¢‚ÄéŒ¾‚·‚é‚©‚Ç‚¤‚©

*/
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

private:
  /*Date*/
  vector<string> isbnraw; // List of isbn numbers in shop (isbnraw.txt)
  vector<string> isbnsold; // List of sold book's isbn (isbnsold.txt)
  vector<string> isbnsoldtime; // List of the time when the book was sold (isbnsoldtime.txt)
  long isbncoupon; // Count how many coupon used (isbncoupon.txt)

  /*Font*/
  ofTrueTypeFont buttonfont; // Font for ofxButton
  
  /*Buttons*/
  ofxButton welcome; // "d–‚ğ‚Í‚¶‚ß‚é"

  /*Piyo*/

};
