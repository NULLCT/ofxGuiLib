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
  btn[2].resize(29);

  btn[2][0].button_beginx = 0 + 25;
  btn[2][0].button_beginy = 0 + 25;
  btn[2][0].button_endx = ofGetWidth()*4 / 8 - 50;
  btn[2][0].button_endy = ofGetHeight()*2 / 8 - 50;
  btn[2][0].button_r = 0xFF;
  btn[2][0].button_g = 0xCB;
  btn[2][0].button_b = 0x6F;
  btn[2][0].button_word = u8"バーコードをスキャンしてね!!";
  btn[2][0].button_enablesimplebox = true;

  btn[2][1].button_beginx = 0 + 10;
  btn[2][1].button_beginy = ofGetHeight()*2 / 8 + 10;
  btn[2][1].button_endx = ofGetWidth() / 8 - 20;
  btn[2][1].button_endy = ofGetHeight() / 8 - 20;
  btn[2][1].button_r = 255;
  btn[2][1].button_g = 155;
  btn[2][1].button_b = 84;
  btn[2][1].button_word = u8"No#";
  btn[2][1].button_enablesimplebox = true;

  btn[2][2].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][2].button_beginy = ofGetHeight()*2 / 8 + 10;
  btn[2][2].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][2].button_endy = ofGetHeight() / 8 - 20;
  btn[2][2].button_r = 255;
  btn[2][2].button_g = 155;
  btn[2][2].button_b = 84;
  btn[2][2].button_word = u8"バーコード";
  btn[2][2].button_enablesimplebox = true;

  btn[2][3].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][3].button_beginy = ofGetHeight()*2 / 8 + 10;
  btn[2][3].button_endx = ofGetWidth() / 8 - 20;
  btn[2][3].button_endy = ofGetHeight() / 8 - 20;
  btn[2][3].button_r = 255;
  btn[2][3].button_g = 155;
  btn[2][3].button_b = 84;
  btn[2][3].button_word = u8"クーポン";
  btn[2][3].button_enablesimplebox = true;

  btn[2][4].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][4].button_beginy = ofGetHeight()*2 / 8 + 10;
  btn[2][4].button_endx = ofGetWidth() / 8 - 20;
  btn[2][4].button_endy = ofGetHeight() / 8 - 20;
  btn[2][4].button_r = 237;
  btn[2][4].button_g = 142;
  btn[2][4].button_b = 84;
  btn[2][4].button_word = u8"価格";
  btn[2][4].button_enablesimplebox = true;

  //---------↓isbnlist----------

  btn[2][5].button_beginx = 0 + 10;
  btn[2][5].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][5].button_endx = ofGetWidth() / 8 - 20;
  btn[2][5].button_endy = ofGetHeight() / 8 - 10;
  btn[2][5].button_r = 0xFF;
  btn[2][5].button_g = 0xCB;
  btn[2][5].button_b = 0x6F;
  btn[2][5].button_word = u8"";
  btn[2][5].button_enablesimplebox = true;

  btn[2][6].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][6].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][6].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][6].button_endy = ofGetHeight() / 8 - 10;
  btn[2][6].button_r = 0xFF;
  btn[2][6].button_g = 0xCB;
  btn[2][6].button_b = 0x6F;
  btn[2][6].button_word = u8"";
  btn[2][6].button_enablesimplebox = true;

  btn[2][7].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][7].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][7].button_endx = ofGetWidth() / 8 - 20;
  btn[2][7].button_endy = ofGetHeight() / 8 - 10;
  btn[2][7].button_r = 0xff;
  btn[2][7].button_g = 0xcb;
  btn[2][7].button_b = 0x6f;
  btn[2][7].button_word = u8"";
  btn[2][7].button_enablesimplebox = true;

  btn[2][8].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][8].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][8].button_endx = ofGetWidth() / 8 - 20;
  btn[2][8].button_endy = ofGetHeight() / 8 - 10;
  btn[2][8].button_r = 0xff;
  btn[2][8].button_g = 0xcb;
  btn[2][8].button_b = 0x6f;
  btn[2][8].button_word = u8"";
  btn[2][8].button_enablesimplebox = true;

  btn[2][9].button_beginx = 0 + 10;
  btn[2][9].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][9].button_endx = ofGetWidth() / 8 - 20;
  btn[2][9].button_endy = ofGetHeight() / 8 - 10;
  btn[2][9].button_r = 0xFF;
  btn[2][9].button_g = 0xCB;
  btn[2][9].button_b = 0x6F;
  btn[2][9].button_word = u8"";
  btn[2][9].button_enablesimplebox = true;

  btn[2][10].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][10].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][10].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][10].button_endy = ofGetHeight() / 8 - 10;
  btn[2][10].button_r = 0xFF;
  btn[2][10].button_g = 0xCB;
  btn[2][10].button_b = 0x6F;
  btn[2][10].button_word = u8"";
  btn[2][10].button_enablesimplebox = true;

  btn[2][11].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][11].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][11].button_endx = ofGetWidth() / 8 - 20;
  btn[2][11].button_endy = ofGetHeight() / 8 - 10;
  btn[2][11].button_r = 0xff;
  btn[2][11].button_g = 0xcb;
  btn[2][11].button_b = 0x6f;
  btn[2][11].button_word = u8"";
  btn[2][11].button_enablesimplebox = true;

  btn[2][12].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][12].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][12].button_endx = ofGetWidth() / 8 - 20;
  btn[2][12].button_endy = ofGetHeight() / 8 - 10;
  btn[2][12].button_r = 0xff;
  btn[2][12].button_g = 0xcb;
  btn[2][12].button_b = 0x6f;
  btn[2][12].button_word = u8"";
  btn[2][12].button_enablesimplebox = true;


  btn[2][13].button_beginx = 0 + 10;
  btn[2][13].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][13].button_endx = ofGetWidth() / 8 - 20;
  btn[2][13].button_endy = ofGetHeight() / 8 - 10;
  btn[2][13].button_r = 0xFF;
  btn[2][13].button_g = 0xCB;
  btn[2][13].button_b = 0x6F;
  btn[2][13].button_word = u8"";
  btn[2][13].button_enablesimplebox = true;

  btn[2][14].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][14].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][14].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][14].button_endy = ofGetHeight() / 8 - 10;
  btn[2][14].button_r = 0xFF;
  btn[2][14].button_g = 0xCB;
  btn[2][14].button_b = 0x6F;
  btn[2][14].button_word = u8"";
  btn[2][14].button_enablesimplebox = true;

  btn[2][15].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][15].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][15].button_endx = ofGetWidth() / 8 - 20;
  btn[2][15].button_endy = ofGetHeight() / 8 - 10;
  btn[2][15].button_r = 0xff;
  btn[2][15].button_g = 0xcb;
  btn[2][15].button_b = 0x6f;
  btn[2][15].button_word = u8"";
  btn[2][15].button_enablesimplebox = true;

  btn[2][16].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][16].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][16].button_endx = ofGetWidth() / 8 - 20;
  btn[2][16].button_endy = ofGetHeight() / 8 - 10;
  btn[2][16].button_r = 0xff;
  btn[2][16].button_g = 0xcb;
  btn[2][16].button_b = 0x6f;
  btn[2][16].button_word = u8"";
  btn[2][16].button_enablesimplebox = true;

  btn[2][17].button_beginx = 0 + 10;
  btn[2][17].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][17].button_endx = ofGetWidth() / 8 - 20;
  btn[2][17].button_endy = ofGetHeight() / 8 - 10;
  btn[2][17].button_r = 0xFF;
  btn[2][17].button_g = 0xCB;
  btn[2][17].button_b = 0x6F;
  btn[2][17].button_word = u8"";
  btn[2][17].button_enablesimplebox = true;

  btn[2][18].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][18].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][18].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][18].button_endy = ofGetHeight() / 8 - 10;
  btn[2][18].button_r = 0xFF;
  btn[2][18].button_g = 0xCB;
  btn[2][18].button_b = 0x6F;
  btn[2][18].button_word = u8"";
  btn[2][18].button_enablesimplebox = true;

  btn[2][19].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][19].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][19].button_endx = ofGetWidth() / 8 - 20;
  btn[2][19].button_endy = ofGetHeight() / 8 - 10;
  btn[2][19].button_r = 0xff;
  btn[2][19].button_g = 0xcb;
  btn[2][19].button_b = 0x6f;
  btn[2][19].button_word = u8"";
  btn[2][19].button_enablesimplebox = true;

  btn[2][20].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][20].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][20].button_endx = ofGetWidth() / 8 - 20;
  btn[2][20].button_endy = ofGetHeight() / 8 - 10;
  btn[2][20].button_r = 0xff;
  btn[2][20].button_g = 0xcb;
  btn[2][20].button_b = 0x6f;
  btn[2][20].button_word = u8"";
  btn[2][20].button_enablesimplebox = true;

  btn[2][21].button_beginx = 0 + 10;
  btn[2][21].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][21].button_endx = ofGetWidth() / 8 - 20;
  btn[2][21].button_endy = ofGetHeight() / 8 - 10;
  btn[2][21].button_r = 0xFF;
  btn[2][21].button_g = 0xCB;
  btn[2][21].button_b = 0x6F;
  btn[2][21].button_word = u8"";
  btn[2][21].button_enablesimplebox = true;

  btn[2][22].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][22].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][22].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][22].button_endy = ofGetHeight() / 8 - 10;
  btn[2][22].button_r = 0xFF;
  btn[2][22].button_g = 0xCB;
  btn[2][22].button_b = 0x6F;
  btn[2][22].button_word = u8"";
  btn[2][22].button_enablesimplebox = true;

  btn[2][23].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][23].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][23].button_endx = ofGetWidth() / 8 - 20;
  btn[2][23].button_endy = ofGetHeight() / 8 - 10;
  btn[2][23].button_r = 0xff;
  btn[2][23].button_g = 0xcb;
  btn[2][23].button_b = 0x6f;
  btn[2][23].button_word = u8"";
  btn[2][23].button_enablesimplebox = true;

  btn[2][24].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][24].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][24].button_endx = ofGetWidth() / 8 - 20;
  btn[2][24].button_endy = ofGetHeight() / 8 - 10;
  btn[2][24].button_r = 0xff;
  btn[2][24].button_g = 0xcb;
  btn[2][24].button_b = 0x6f;
  btn[2][24].button_word = u8"";
  btn[2][24].button_enablesimplebox = true;

//-----------------↑isbnlist----------------------
//-----------------↓sumlist-----------------------

  btn[2][25].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][25].button_beginy = ofGetHeight()*3 / 8 + 10;
  btn[2][25].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][25].button_endy = ofGetHeight() / 8 - 20;
  btn[2][25].button_r = 0xff;
  btn[2][25].button_g = 0xcb;
  btn[2][25].button_b = 0x6f;
  btn[2][25].button_word = u8"小計:0円";
  btn[2][25].button_enablesimplebox = true;

  btn[2][26].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][26].button_beginy = ofGetHeight()*4 / 8 + 10;
  btn[2][26].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][26].button_endy = ofGetHeight() / 8 - 20;
  btn[2][26].button_r = 0xff;
  btn[2][26].button_g = 0xcb;
  btn[2][26].button_b = 0x6f;
  btn[2][26].button_word = u8"クーポン:0個";
  btn[2][26].button_enablesimplebox = true;

  btn[2][27].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][27].button_beginy = ofGetHeight()*5 / 8 + 10;
  btn[2][27].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][27].button_endy = ofGetHeight() / 8 - 20;
  btn[2][27].button_r = 255;
  btn[2][27].button_g = 136;
  btn[2][27].button_b = 122;
  btn[2][27].button_word = u8"合計:0円";
  btn[2][27].button_enablesimplebox = true;

//----------------↓okbutton---------------------

  btn[2][28].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][28].button_beginy = ofGetHeight()*6 / 8 + 10;
  btn[2][28].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][28].button_endy = ofGetHeight()*2 / 8 - 20;
  btn[2][28].button_r = 255;
  btn[2][28].button_g = 84;
  btn[2][28].button_b = 84;
  btn[2][28].button_word = u8"確定";

  /*screen 3*/
  btn[3].resize(1);
  
  btn[3][0].button_beginx = 0 + 25;
  btn[3][0].button_beginy = 0 + 25;
  btn[3][0].button_endx = ofGetWidth() - 50;
  btn[3][0].button_endy = ofGetHeight() - 50;
  btn[3][0].button_word = u8"デスクトップにある動画を見てね！";

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
    if (screen == 2) {//draw partation
      ofSetColor(240, 240, 240, 200);
      ofDrawLine(ofGetWidth()*1 / 8, ofGetHeight()*2 / 8, ofGetWidth()*1 / 8, ofGetHeight()*8 / 8-10);
      ofDrawLine(ofGetWidth()*4 / 8, ofGetHeight()*2 / 8, ofGetWidth()*4 / 8, ofGetHeight()*8 / 8-10);
      ofDrawLine(ofGetWidth()*5 / 8, ofGetHeight()*2 / 8, ofGetWidth()*5 / 8, ofGetHeight()*8 / 8-10);
      ofDrawLine(ofGetWidth()*6 / 8, ofGetHeight()*2 / 8, ofGetWidth()*6 / 8, ofGetHeight()*8 / 8-10);
    }
  }

  /*draw piyohiko*/
  piyohiko.draw(ofGetWidth() * sin(frame / 128.0), piyohikoy);

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
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){//ボタン依存の機能はここに書く

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
