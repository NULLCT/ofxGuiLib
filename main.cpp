#include "ofApp.h"
#include "ofMain.h"

int main() {
  ofGLFWWindowSettings settings;  // OpenFrameWorks setting

  settings.title = "ISBNCTRLSYS v0.1a";  // Title
  settings.setSize(1200, 600);           // Size
  settings.resizable = false;            // non resiable

  ofCreateWindow(settings);    // attach settings
  return ofRunApp(new ofApp());  // create ofApp
}
