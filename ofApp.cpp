#include "ofApp.h"
/*view closstile*/
#define ALPHA
//--------------------------------------------------------------
void ofApp::setup() {

  /*load logo*/
  ifstream logo("logo.txt");
  if (logo.fail()) {
    cout << "ERROR:fail load logo." << endl;
  }
  else {
    /*print logo and hogehoge*/
    string logostr = "";
    while (getline(logo, logostr)) {
      cout << logostr << endl;
    }
  }

  printf("%-32s", "loaded logo...");
  printf("10\%");
  printf("\n");

  printf("%-32s", "load isbnrawlist.txt...");
  printf("20\%");
  printf("\n");

  /*load isbnrawlist*/
  ifstream rawlist("isbnrawlist.txt");
  if (rawlist.fail()) {
    cout << "ERROR:fail load isbnrawlist.txt" << endl;
  }
  else {
    string rawliststr = "";
    while (getline(rawlist, rawliststr)) {
      isbnrawlist.push_back(rawliststr);
    }
  }

  printf("%-32s", "load isbnsoldlist.txt...");
  printf("30\%");
  printf("\n");

  /*load isbnrawlist*/
  ifstream soldlist("isbnsoldlist.txt");
  if (soldlist.fail()) {
    cout << "ERROR:fail load isbnsoldlist.txt" << endl;
  }
  else {
    string soldliststr = "";
    while (getline(soldlist, soldliststr)) {
      isbnsoldlist.push_back(soldliststr);
    }
  }

  printf("%-32s", "load Piyohiko.png...");
  printf("40\%");
  printf("\n");

  /*summoning piyohiko!!!*/
  piyohiko.load("Piyohiko.png");

  /*load expmovie.mp4*/
  expmovie.load("expmovie.mp4");

  printf("%-32s", "setting openframeworks...");
  printf("50\%");
  printf("\n");
  /*of setting*/
  ofSetBackgroundColor(222, 222, 222);
  ofSetFrameRate(60);
  ofSetWindowTitle("ISBNCTRLSYSv0.0");
  ofSetLineWidth(5);
  ofSetEscapeQuitsApp(false);

  printf("%-32s", "loading font([JKGM.ttf])...");
  printf("60\%");
  printf("\n");
  /*font setting*/
  ofTrueTypeFontSettings fontsettings("JKGM.ttf", 24);
  printf("%-32s", "loading rang([Latin])...");
  printf("70\%");
  printf("\n");
  fontsettings.addRanges(ofAlphabet::Latin);
  printf("%-32s", "loading rang([Japanese])...");
  printf("80\%");
  printf("\n");
  fontsettings.addRanges(ofAlphabet::Japanese);
  font.load(fontsettings);

  printf("%-32s", "setting screen...");
  printf("90\%");
  printf("\n");
  /*screen setting*/
  screen = 0;

  /*button setup*/
  printf("%-32s", "setting class::button...");
  printf("99\%");
  printf("\n");
  btnsetup();

  for (int scrn = 0; scrn < btn.size(); scrn++) {
    for (int count = 0; count < btn[scrn].size(); count++) {
      cout << "  determined: |" << scrn << "/" << count << "|" << endl;
    }
  }
  cout << "ISBNCTRLSYS has started. " << isbnsoldlist.size() << "/" << isbnrawlist.size() << " time: " << time(NULL) << endl;
}

//--------------------------------------------------------------
void ofApp::btnsetup() {
  screen = 0;
  /*
    Why btnsetup has "screen=0"?:
    btnsetup is rewrite all vector btn settings.
    so if it draw "hogehoge",and run btnsetup(),
    "hogehoge" will be changed.
    that's why.
  */

  /*screen size*/
  btn.resize(7);

  /*screen 0*/
  btn[0].resize(2);

  btn[0][0].button_beginx = 0 + 25;
  btn[0][0].button_beginy = 0 + 25;
  btn[0][0].button_endx = ofGetWidth() / 2 - 50;
  btn[0][0].button_endy = ofGetHeight() - 50;
  btn[0][0].button_word = u8"管理者としてログイン";

  btn[0][1].button_beginx = ofGetWidth() / 2 + 25;
  btn[0][1].button_beginy = 25;
  btn[0][1].button_endx = ofGetWidth() / 2 - 50;
  btn[0][1].button_endy = ofGetHeight() - 50;
  btn[0][1].button_word = u8"委員としてログイン";

  /*screen 1*/
  btn[1].resize(4);

  btn[1][0].button_beginx = 0 + 25;
  btn[1][0].button_beginy = 0 + 25;
  btn[1][0].button_endx = ofGetWidth() / 2 - 50;
  btn[1][0].button_endy = ofGetHeight() / 2 - 50;
  btn[1][0].button_word = u8"本売却";

  btn[1][1].button_beginx = 0 + 25;
  btn[1][1].button_beginy = ofGetHeight() / 2 + 25;
  btn[1][1].button_endx = ofGetWidth() / 4 - 50;
  btn[1][1].button_endy = ofGetHeight() / 2 - 50;
  btn[1][1].button_word = u8"本一覧/検索\nこの機能は使えません";
  btn[1][1].button_enablesimplebox = true;

  btn[1][2].button_beginx = ofGetWidth() / 4 + 25;
  btn[1][2].button_beginy = ofGetHeight() / 2 + 25;
  btn[1][2].button_endx = ofGetWidth() / 8 - 50;
  btn[1][2].button_endy = ofGetHeight() / 2 - 50;
  btn[1][2].button_word = u8"使い方";

  btn[1][3].button_beginx = ofGetWidth() / 4 + 25 + ofGetWidth() / 8;
  btn[1][3].button_beginy = ofGetHeight() / 2 + 25;
  btn[1][3].button_endx = ofGetWidth() / 8 - 50;
  btn[1][3].button_endy = ofGetHeight() / 2 - 50;
  btn[1][3].button_word = u8"何かあったら";

  /*screen 2*/
  btn[2].resize(7);

  btn[2][0].button_beginx = 0 + 25;
  btn[2][0].button_beginy = 0 + 25;
  btn[2][0].button_endx = ofGetWidth() / 2 - 50;
  btn[2][0].button_endy = ofGetHeight() / 4 - 50;
  btn[2][0].button_r = 0xFF;
  btn[2][0].button_g = 0xCB;
  btn[2][0].button_b = 0x6F;
  btn[2][0].button_word = u8"バーコードをスキャンしてね!!";
  btn[2][0].button_enablesimplebox = true;

  btn[2][1].button_beginx = 0 + 25;
  btn[2][1].button_beginy = ofGetHeight() / 4 + 25;
  btn[2][1].button_endx = ofGetWidth() / 2 - 50;
  btn[2][1].button_endy = ofGetHeight() / 4 - 50;
  btn[2][1].button_word = u8"(クーポンを使うなら右のボタンをクリック)\n(標準だとクーポンは使わない設定です)";
  btn[2][1].button_enableonlyword = true;

  btn[2][2].button_beginx = 0 + 25;
  btn[2][2].button_beginy = ofGetHeight() / 2 + 25;
  btn[2][2].button_endx = ofGetWidth() / 2 - 50;
  btn[2][2].button_endy = ofGetHeight() / 2 - 50;
  btn[2][2].button_word = u8"ISBNを入力してください...";
  btn[2][2].button_enablesimplebox = true;

  btn[2][3].button_beginx = ofGetWidth() / 2 + 25;
  btn[2][3].button_beginy = 0 + 25;
  btn[2][3].button_endx = ofGetWidth() / 2 - 50;
  btn[2][3].button_endy = ofGetHeight() / 4 * 3 - 50;
  btn[2][3].button_word = u8"クーポンを使わない";

  btn[2][4].button_beginx = ofGetWidth() / 2 + 25;
  btn[2][4].button_beginy = ofGetHeight() / 4 * 3 + 25;
  btn[2][4].button_endx = ofGetWidth() / 2 - 50;
  btn[2][4].button_endy = ofGetHeight() / 4 - 50;
  btn[2][4].button_r = 0xE8;
  btn[2][4].button_g = 0x5A;
  btn[2][4].button_b = 0x5E;
  btn[2][4].button_word = u8"確定";

  btn[2][5].button_beginx = 0 + 100;
  btn[2][5].button_beginy = 0 + 100;
  btn[2][5].button_endx = ofGetWidth() - 200;
  btn[2][5].button_endy = ofGetHeight() - 200;
  btn[2][5].button_r = 0xE8;
  btn[2][5].button_g = 0x5A;
  btn[2][5].button_b = 0x5E;
  btn[2][5].button_word = u8"アラートボタン";
  btn[2][5].button_enable = false;

  btn[2][6].button_beginx = 0 + 25;
  btn[2][6].button_beginy = ofGetHeight() / 4*3 + 25;
  btn[2][6].button_endx = ofGetWidth() / 4 - 50;
  btn[2][6].button_endy = ofGetHeight() / 4 - 50;
  btn[2][6].button_word = u8"入力を削除";

  /*screen 3*/
  btn[3].resize(1);
  
  btn[3][0].button_beginx = 0 + 25;
  btn[3][0].button_beginy = 0 + 25;
  btn[3][0].button_endx = ofGetWidth() - 50;
  btn[3][0].button_endy = ofGetHeight() - 50;
  btn[3][0].button_word = u8"動画を再生";

  /*set button pos*/
  for (int scrn = 0; scrn < btn.size(); scrn++) {
    for (int count = 0; count < btn[scrn].size(); count++) {
      btn[scrn][count].button_fontx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) - (font.stringWidth(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_fonty = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) + (font.stringHeight(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinebeginx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) - (font.stringWidth(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinebeginy = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) + (font.stringHeight(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinelenght = font.stringWidth(btn[scrn][count].button_word);
      if (btn[scrn][count].button_enableonlyword) {
        btn[scrn][count].button_enablesimplebox = true;
      }
    }
  }
}


//--------------------------------------------------------------
void ofApp::update() {
  /*set button shadow length*/
  for (int count = 0; count < btn[screen].size(); count++) {
    if (!btn[screen][count].button_enablesimplebox) {
      if ((btn[screen][count].button_beginx <= ofGetMouseX() && btn[screen][count].button_beginy <= ofGetMouseY()) && (btn[screen][count].button_beginx + btn[screen][count].button_endx >= ofGetMouseX() && btn[screen][count].button_beginy + btn[screen][count].button_endy >= ofGetMouseY())) {
        if (btn[screen][count].button_shadowlenght < 10) {
          btn[screen][count].button_shadowlenght += 2;
        }
      }
      else {
        if (btn[screen][count].button_shadowlenght > 0) {
          btn[screen][count].button_shadowlenght--;
        }
      }
    }
  }

  frame++;
  if (frame % 60 == 0) piyohikoy = ofRandom(ofGetHeight());
  expmovie.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  /*Draw closstile*/
#ifdef ALPHA
  ofSetColor(200, 200, 200);
  ofDrawLine(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
  ofDrawLine(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2);
#endif
  /*draw button*/
  for (int count = 0; count < btn[screen].size(); count++) {
    if (btn[screen][count].button_enable) {
      if (!btn[screen][count].button_enablesimplebox) {
        ofSetColor(0, 0, 0, 100);//shadow
        ofDrawRectangle(btn[screen][count].button_beginx + 5, btn[screen][count].button_beginy + 5, btn[screen][count].button_endx + btn[screen][count].button_shadowlenght, btn[screen][count].button_endy + btn[screen][count].button_shadowlenght);

        ofSetColor(btn[screen][count].button_r - 10 - btn[screen][count].button_shadowlenght, btn[screen][count].button_g - 10 - btn[screen][count].button_shadowlenght, btn[screen][count].button_b - 10 - btn[screen][count].button_shadowlenght);//button outsidebox
        ofDrawRectangle(btn[screen][count].button_beginx, btn[screen][count].button_beginy, btn[screen][count].button_endx, btn[screen][count].button_endy);
      }

      if (!btn[screen][count].button_enableonlyword) {
        ofSetColor(btn[screen][count].button_r + btn[screen][count].button_shadowlenght, btn[screen][count].button_g + btn[screen][count].button_shadowlenght, btn[screen][count].button_b + btn[screen][count].button_shadowlenght);//button insidebox
        ofDrawRectangle(btn[screen][count].button_beginx + 10, btn[screen][count].button_beginy + 10, btn[screen][count].button_endx - 20, btn[screen][count].button_endy - 20);
      }

      ofSetColor(btn[screen][count].button_wordr - 100, btn[screen][count].button_wordg - 100, btn[screen][count].button_wordb - 100);//buttonword shadow 0
      font.drawString(btn[screen][count].button_word, btn[screen][count].button_fontx + 2, btn[screen][count].button_fonty + 2);

      ofSetColor(btn[screen][count].button_wordr - 50, btn[screen][count].button_wordg - 50, btn[screen][count].button_wordb - 50);//buttonword shadow 1
      font.drawString(btn[screen][count].button_word, btn[screen][count].button_fontx + 1, btn[screen][count].button_fonty + 1);

      ofSetColor(btn[screen][count].button_wordr, btn[screen][count].button_wordg, btn[screen][count].button_wordb);//buttonword 
      font.drawString(btn[screen][count].button_word, btn[screen][count].button_fontx, btn[screen][count].button_fonty);

      ofSetColor(255, 255, 255, 200);//buttonword underline
      ofDrawLine(btn[screen][count].button_underlinebeginx, btn[screen][count].button_underlinebeginy + 5, btn[screen][count].button_underlinebeginx + btn[screen][count].button_underlinelenght, btn[screen][count].button_underlinebeginy + 5);
    }
  }

  /*draw piyohiko*/
  piyohiko.draw(ofGetWidth() * sin(frame / 128.0), piyohikoy);
  if (expmovie.isFrameNew()) {
    expmovie.draw(0, 0, ofGetWidth(), ofGetHeight());
  }

  /*draw path*/
  ofSetColor(0, 0, 0,100);
  switch (screen) {
  case 0:
    font.drawString(u8"/", 0, 30);
    break;
  case 1:
    font.drawString(u8"/委員でログイン", 0, 30);
    break;
  case 2:
    font.drawString(u8"/委員でログイン/本売却", 0, 30);
    break;
  case 3:
    font.drawString(u8"/委員でログイン/使い方", 0, 30);
    break;
  case 4:
    font.drawString(u8"/委員でログイン/何かあったら...", 0, 30);
    break;
  case 5:
    font.drawString(u8"/管理でログイン", 0, 30);
    break;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 'f') {
    ofSetWindowShape(1280, 720);
  }
  if (key == 'h') {
    screen = 0;
  }
  /*if screen is 2: begin isbn input system...*/
  if (screen != 2) {
    inputisbn = "";
  }
  else {
    switch (key) {
    case '0':
      inputisbn += "0";
      break;
    case '1':
      inputisbn += "1";
      break;
    case '2':
      inputisbn += "2";
      break;
    case '3':
      inputisbn += "3";
      break;
    case '4':
      inputisbn += "4";
      break;
    case '5':
      inputisbn += "5";
      break;
    case '6':
      inputisbn += "6";
      break;
    case '7':
      inputisbn += "7";
      break;
    case '8':
      inputisbn += "8";
      break;
    case '9':
      inputisbn += "9";
      break;
    }
    btn[2][2].button_word = "ISBN: " + inputisbn;
    /*set button pos*/
    for (int scrn = 0; scrn < btn.size(); scrn++) {
      for (int count = 0; count < btn[scrn].size(); count++) {
        btn[scrn][count].button_fontx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) - (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_fonty = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) + (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) - (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginy = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) + (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinelenght = font.stringWidth(btn[scrn][count].button_word);
        if (btn[scrn][count].button_enableonlyword) {
          btn[scrn][count].button_enablesimplebox = true;
        }
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  for (int count = 0; count < btn[screen].size(); count++){
    if ((btn[screen][count].button_beginx <= x && btn[screen][count].button_beginy <= y) && (btn[screen][count].button_beginx + btn[screen][count].button_endx >= x && btn[screen][count].button_beginy + btn[screen][count].button_endy >= y)) {
      switch (screen) {
      case 0:
        switch (count) {
        case 0:
          screen = 6;
          break;
        case 1:
          screen = 1;
          break;
        }
        break;
      case 1:
        switch (count) {
        case 0:
          screen = 2;
          break;
        case 1:
          break;
        case 2:
          screen = 3;
          break;
        case 3:
          screen = 4;
          break;
        }
        break;
      case 2:
        switch (count) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          if (btn[2][3].button_word == u8"クーポンを使う") {
            btn[2][3].button_word = u8"クーポンを使わない";
            btn[2][3].button_r = 141;
            btn[2][3].button_g = 235;
            btn[2][3].button_b = 208;
            cout << "btn[2][3].disable => enable" << endl;
          }
          else {
            btn[2][3].button_word = u8"クーポンを使う";
            btn[2][3].button_r = 0xE8;
            btn[2][3].button_g = 0x5A;
            btn[2][3].button_b = 0x5E;
            cout << "btn[2][3].enable => disable" << endl;
          }
          break;
        case 4:
          for (int count = 0; count < isbnsoldlist.size(); count++) {
            if (isbnsoldlist[count] == inputisbn) {
              btn[2][5].button_word = u8"ISBN: " + inputisbn + u8"は既に売れています。";
              btn[2][5].button_enable = true;
              return;
            }
          }
          for (int count = 0; count < isbnrawlist.size(); count++) {
            if (isbnrawlist[count] == inputisbn) {
              ofstream file_isbnsoldlist,file_isbncouponlist;
              file_isbnsoldlist.open("isbnsoldlist.txt",ios::app);
              file_isbncouponlist.open("isbncouponlist.txt",ios::app);
              if (file_isbnsoldlist.fail() or file_isbncouponlist.fail()) {/*fail load file*/
                btn[2][5].button_word = u8"ファイルの読み込みに失敗しました。:(";
                btn[2][5].button_enable = true;
                file_isbnsoldlist.close();
                file_isbncouponlist.close();
                return;
              }
              else {/*did load file*/
                file_isbnsoldlist << inputisbn << "\n";
                if (btn[2][3].button_word == u8"クーポンを使う") {
                  file_isbncouponlist << inputisbn << "\n";
                }
                isbnsoldlist.push_back(inputisbn);
                btn[2][5].button_word = u8"ISBN: " + inputisbn + u8"の売却しました。";
                btn[2][5].button_enable = true;
                file_isbnsoldlist.close();
                file_isbncouponlist.close();
                return;
              }
            }
          }
          btn[2][5].button_word = u8"ISBN: " + inputisbn + u8"は見つかりませんでした。入力ミス??";
          btn[2][5].button_enable = true;
          break;
        case 5:
          btn[2][5].button_enable = false;
          break;
        case 6:
          inputisbn = "";
          btn[2][2].button_word = "ISBN: " + inputisbn;
          break;
        }
        break;
      case 3:
        break;
      }
    }
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
  btnsetup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}
