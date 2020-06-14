#include "ofApp.h"
/*view closstile*/
#define ALPHA
#define BOOKCOST 100
//--------------------------------------------------------------
void ofApp::setup() {

  /*load logo*/
  cout<<"LOAD FILES:"<<endl;
  ifstream logo("logo.txt");
  if (logo.fail()) {
    cout << "  ERROR:fail load logo." << endl;
  }
  else {
    /*print logo and hogehoge*/
    string logostr = "";
    while (getline(logo, logostr)) {
      cout << logostr << endl;
    }
  }

  cout<<"  isbnrawlist.txt"<<endl;
  /*load isbnrawlist*/
  ifstream rawlist("isbnrawlist.txt");
  if (rawlist.fail()) {
    cout << "ERROR:fail load isbnrawlist.txt" << endl;
    exit();
  }
  else {
    string rawliststr = "";
    while (getline(rawlist, rawliststr)) {
      isbnrawlist.push_back(rawliststr);
    }
  }


  cout<<"  isbnsoldlist.txt"<<endl;
  /*load isbnsoldlist*/
  ifstream soldlist("isbnsoldlist.txt");
  if (soldlist.fail()) {
    cout << "ERROR:fail load isbnsoldlist.txt" << endl;
    exit();
  }
  else {
    string soldliststr = "";
    while (getline(soldlist, soldliststr)) {
      isbnsoldlist.push_back(soldliststr);
    }
  }

  cout<<"  picture"<<endl;
  /*summoning piyohiko!!!*/
  piyohiko.load("Piyohiko.png");

  cout<<"  openframeworks_settings"<<endl;
  /*of setting*/
  ofSetBackgroundColor(222, 222, 222);
  ofSetFrameRate(60);
  ofSetWindowTitle("ISBNCTRLSYSv0.0");
  ofSetLineWidth(5);
  ofSetEscapeQuitsApp(false);

  cout<<"  font(Cica.ttf)"<<endl;
  /*font setting*/
  ofTrueTypeFontSettings fontsettings("Cica.ttf", 24);
  cout<<"  load_Latin"<<endl;
  fontsettings.addRanges(ofAlphabet::Latin);
  cout<<"  load_Japanese"<<endl;
  fontsettings.addRanges(ofAlphabet::Japanese);
  cout<<"  load_fontsettings"<<endl;
  font.load(fontsettings);

  cout<<"  set_screen"<<endl;
  /*screen setting*/
  screen = 0;

  /*button setup*/
  cout<<"  class_button_setup"<<endl;
  screen2_isbndates.clear();
  btnsetup();
  btn[2][30].button_enable = false;

  for (int scrn = 0; scrn < int(btn.size()); scrn++) {
    for (int count = 0; count < int(btn[scrn].size()); count++) {
      cout << "  determined: |" << scrn << "/" << count << "|" << endl;
    }
  }
  cout << "ISBNCTRLSYS has started. "
       << isbnsoldlist.size()
       << "/"
       << isbnrawlist.size()
       << " time: "
       << time(NULL)
       << endl;
  cout << "isbnrawlist:" << endl;
  for (int i = 0; i < isbnrawlist.size(); i++) {
    cout << "  " << isbnrawlist[i] << endl;
  }
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
  screen2_switcherror = 0;

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
  btn[2].resize(31);

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
  btn[2][3].button_r = 237;
  btn[2][3].button_g = 142;
  btn[2][3].button_b = 84;
  btn[2][3].button_word = u8"価格";
  btn[2][3].button_enablesimplebox = true;

  //---------↓isbnlist----------

  btn[2][4].button_beginx = 0 + 10;
  btn[2][4].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][4].button_endx = ofGetWidth() / 8 - 20;
  btn[2][4].button_endy = ofGetHeight() / 8 - 10;
  btn[2][4].button_r = 0xFF;
  btn[2][4].button_g = 0xCB;
  btn[2][4].button_b = 0x6F;
  btn[2][4].button_word = u8"";
  btn[2][4].button_enablesimplebox = true;

  btn[2][5].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][5].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][5].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][5].button_endy = ofGetHeight() / 8 - 10;
  btn[2][5].button_r = 0xFF;
  btn[2][5].button_g = 0xCB;
  btn[2][5].button_b = 0x6F;
  btn[2][5].button_word = u8"";
  btn[2][5].button_enablesimplebox = true;

  btn[2][6].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][6].button_beginy = ofGetHeight()*3 / 8 + 5;
  btn[2][6].button_endx = ofGetWidth() / 8 - 20;
  btn[2][6].button_endy = ofGetHeight() / 8 - 10;
  btn[2][6].button_r = 0xff;
  btn[2][6].button_g = 0xcb;
  btn[2][6].button_b = 0x6f;
  btn[2][6].button_word = u8"";
  btn[2][6].button_enablesimplebox = true;

  btn[2][7].button_beginx = 0 + 10;
  btn[2][7].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][7].button_endx = ofGetWidth() / 8 - 20;
  btn[2][7].button_endy = ofGetHeight() / 8 - 10;
  btn[2][7].button_r = 0xFF;
  btn[2][7].button_g = 0xCB;
  btn[2][7].button_b = 0x6F;
  btn[2][7].button_word = u8"";
  btn[2][7].button_enablesimplebox = true;

  btn[2][8].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][8].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][8].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][8].button_endy = ofGetHeight() / 8 - 10;
  btn[2][8].button_r = 0xFF;
  btn[2][8].button_g = 0xCB;
  btn[2][8].button_b = 0x6F;
  btn[2][8].button_word = u8"";
  btn[2][8].button_enablesimplebox = true;

  btn[2][9].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][9].button_beginy = ofGetHeight()*4 / 8 + 5;
  btn[2][9].button_endx = ofGetWidth() / 8 - 20;
  btn[2][9].button_endy = ofGetHeight() / 8 - 10;
  btn[2][9].button_r = 0xff;
  btn[2][9].button_g = 0xcb;
  btn[2][9].button_b = 0x6f;
  btn[2][9].button_word = u8"";
  btn[2][9].button_enablesimplebox = true;

  btn[2][10].button_beginx = 0 + 10;
  btn[2][10].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][10].button_endx = ofGetWidth() / 8 - 20;
  btn[2][10].button_endy = ofGetHeight() / 8 - 10;
  btn[2][10].button_r = 0xFF;
  btn[2][10].button_g = 0xCB;
  btn[2][10].button_b = 0x6F;
  btn[2][10].button_word = u8"";
  btn[2][10].button_enablesimplebox = true;

  btn[2][11].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][11].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][11].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][11].button_endy = ofGetHeight() / 8 - 10;
  btn[2][11].button_r = 0xFF;
  btn[2][11].button_g = 0xCB;
  btn[2][11].button_b = 0x6F;
  btn[2][11].button_word = u8"";
  btn[2][11].button_enablesimplebox = true;

  btn[2][12].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][12].button_beginy = ofGetHeight()*5 / 8 + 5;
  btn[2][12].button_endx = ofGetWidth() / 8 - 20;
  btn[2][12].button_endy = ofGetHeight() / 8 - 10;
  btn[2][12].button_r = 0xff;
  btn[2][12].button_g = 0xcb;
  btn[2][12].button_b = 0x6f;
  btn[2][12].button_word = u8"";
  btn[2][12].button_enablesimplebox = true;

  btn[2][13].button_beginx = 0 + 10;
  btn[2][13].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][13].button_endx = ofGetWidth() / 8 - 20;
  btn[2][13].button_endy = ofGetHeight() / 8 - 10;
  btn[2][13].button_r = 0xFF;
  btn[2][13].button_g = 0xCB;
  btn[2][13].button_b = 0x6F;
  btn[2][13].button_word = u8"";
  btn[2][13].button_enablesimplebox = true;

  btn[2][14].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][14].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][14].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][14].button_endy = ofGetHeight() / 8 - 10;
  btn[2][14].button_r = 0xFF;
  btn[2][14].button_g = 0xCB;
  btn[2][14].button_b = 0x6F;
  btn[2][14].button_word = u8"";
  btn[2][14].button_enablesimplebox = true;

  btn[2][15].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][15].button_beginy = ofGetHeight()*6 / 8 + 5;
  btn[2][15].button_endx = ofGetWidth() / 8 - 20;
  btn[2][15].button_endy = ofGetHeight() / 8 - 10;
  btn[2][15].button_r = 0xff;
  btn[2][15].button_g = 0xcb;
  btn[2][15].button_b = 0x6f;
  btn[2][15].button_word = u8"";
  btn[2][15].button_enablesimplebox = true;

  btn[2][16].button_beginx = 0 + 10;
  btn[2][16].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][16].button_endx = ofGetWidth() / 8 - 20;
  btn[2][16].button_endy = ofGetHeight() / 8 - 10;
  btn[2][16].button_r = 0xFF;
  btn[2][16].button_g = 0xCB;
  btn[2][16].button_b = 0x6F;
  btn[2][16].button_word = u8"";
  btn[2][16].button_enablesimplebox = true;

  btn[2][17].button_beginx = ofGetWidth() / 8 + 10;
  btn[2][17].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][17].button_endx = ofGetWidth()*3 / 8 - 20;
  btn[2][17].button_endy = ofGetHeight() / 8 - 10;
  btn[2][17].button_r = 0xFF;
  btn[2][17].button_g = 0xCB;
  btn[2][17].button_b = 0x6F;
  btn[2][17].button_word = u8"";
  btn[2][17].button_enablesimplebox = true;

  btn[2][18].button_beginx = ofGetWidth()*4 / 8 + 10;
  btn[2][18].button_beginy = ofGetHeight()*7 / 8 + 5;
  btn[2][18].button_endx = ofGetWidth() / 8 - 20;
  btn[2][18].button_endy = ofGetHeight() / 8 - 10;
  btn[2][18].button_r = 0xff;
  btn[2][18].button_g = 0xcb;
  btn[2][18].button_b = 0x6f;
  btn[2][18].button_word = u8"";
  btn[2][18].button_enablesimplebox = true;

  //-----------------↑isbnlist----------------------
  //-----------------↓sumlist-----------------------

  btn[2][19].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][19].button_beginy = ofGetHeight()*3 / 8 + 10;
  btn[2][19].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][19].button_endy = ofGetHeight() / 8 - 20;
  btn[2][19].button_r = 0xff;
  btn[2][19].button_g = 0xcb;
  btn[2][19].button_b = 0x6f;
  btn[2][19].button_word = u8"小計:0";
  btn[2][19].button_enablesimplebox = true;

  btn[2][20].button_beginx = ofGetWidth()*7 / 8 + 10;
  btn[2][20].button_beginy = ofGetHeight()*1 / 8 + 10;
  btn[2][20].button_endx = ofGetWidth() / 8 - 20;
  btn[2][20].button_endy = ofGetHeight() / 8 - 20;
  btn[2][20].button_r = 0xff;
  btn[2][20].button_g = 0xcb;
  btn[2][20].button_b = 0x6f;
  btn[2][20].button_word = u8"0個";
  btn[2][20].button_enablesimplebox = true;

  btn[2][21].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][21].button_beginy = ofGetHeight()*5 / 8 + 10;
  btn[2][21].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][21].button_endy = ofGetHeight() / 8 - 20;
  btn[2][21].button_r = 255;
  btn[2][21].button_g = 136;
  btn[2][21].button_b = 122;
  btn[2][21].button_word = u8"合計:0";
  btn[2][21].button_enablesimplebox = true;

  //----------------↓okbutton---------------------

  btn[2][22].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][22].button_beginy = ofGetHeight()*6 / 8 + 10;
  btn[2][22].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][22].button_endy = ofGetHeight()*2 / 8 - 20;
  btn[2][22].button_r = 255;
  btn[2][22].button_g = 84;
  btn[2][22].button_b = 84;
  btn[2][22].button_word = u8"確定";

  btn[2][23].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][23].button_beginy = ofGetHeight()*6 / 8 + 10;
  btn[2][23].button_endx = ofGetWidth()*1 / 8 - 20;
  btn[2][23].button_endy = ofGetHeight()*1 / 8 - 20;
  btn[2][23].button_r = 200;
  btn[2][23].button_g = 84;
  btn[2][23].button_b = 84;
  btn[2][23].button_word = u8"上";

  btn[2][24].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][24].button_beginy = ofGetHeight()*7 / 8 + 10;
  btn[2][24].button_endx = ofGetWidth()*1 / 8 - 20;
  btn[2][24].button_endy = ofGetHeight()*1 / 8 - 20;
  btn[2][24].button_r = 200;
  btn[2][24].button_g = 84;
  btn[2][24].button_b = 84;
  btn[2][24].button_word = u8"下";

  btn[2][25].button_beginx = ofGetWidth()*5 / 8 + 10;
  btn[2][25].button_beginy = ofGetHeight()*5 / 8 + 10;
  btn[2][25].button_endx = ofGetWidth()*1 / 8 - 20;
  btn[2][25].button_endy = ofGetHeight()*1 / 8 - 20;
  btn[2][25].button_word = u8"全消去";

  btn[2][26].button_beginx = ofGetWidth()*7 / 8 + 10;
  btn[2][26].button_beginy = 0 + 10;
  btn[2][26].button_endx = ofGetWidth()*1 / 8 - 20;
  btn[2][26].button_endy = ofGetHeight()*1 / 8 - 20;
  btn[2][26].button_word = u8"一枚追加";

  btn[2][27].button_beginx = ofGetWidth()*7 / 8 + 10;
  btn[2][27].button_beginy = ofGetHeight()*2 / 8 + 10;
  btn[2][27].button_endx = ofGetWidth()*1 / 8 - 20;
  btn[2][27].button_endy = ofGetHeight()*1 / 8 - 20;
  btn[2][27].button_word = u8"一枚削除";

  btn[2][28].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][28].button_beginy = 0 + 10;
  btn[2][28].button_endx = ofGetWidth() / 8 - 20;
  btn[2][28].button_endy = ofGetHeight()*3 / 8 - 20;
  btn[2][28].button_enablesimplebox=true;
  btn[2][28].button_word = u8"クーポン";

  btn[2][29].button_beginx = ofGetWidth()*6 / 8 + 10;
  btn[2][29].button_beginy = ofGetHeight()*4 / 8 + 10;
  btn[2][29].button_endx = ofGetWidth()*2 / 8 - 20;
  btn[2][29].button_endy = ofGetHeight() / 8 - 20;
  btn[2][29].button_enablesimplebox=true;
  btn[2][29].button_word = u8"クーポン割引:0";

  btn[2][30].button_beginx = 0 + 10;
  btn[2][30].button_beginy = 0 + 10;
  btn[2][30].button_endx = ofGetWidth() - 20;
  btn[2][30].button_endy = ofGetHeight() - 20;
  btn[2][30].button_r = 255;
  btn[2][30].button_g = 136;
  btn[2][30].button_b = 122;
  btn[2][30].button_word = u8"ERROR";

  /*screen 3*/
  btn[3].resize(1);

  btn[3][0].button_beginx = 0 + 25;
  btn[3][0].button_beginy = 0 + 25;
  btn[3][0].button_endx = ofGetWidth() - 50;
  btn[3][0].button_endy = ofGetHeight() - 50;
  btn[3][0].button_word = u8"デスクトップにある動画を見てね！";

  /*set button pos*/
  for (int scrn = 0; scrn < int(btn.size()); scrn++) {
    for (int count = 0; count < int(btn[scrn].size()); count++) {
      btn[scrn][count].button_fontx =
          ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) - (font.stringWidth(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_fonty = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) +
          (font.stringHeight(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinebeginx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) -
          (font.stringWidth(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinebeginy = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) +
          (font.stringHeight(btn[scrn][count].button_word) / 2);
      btn[scrn][count].button_underlinelenght = font.stringWidth(btn[scrn][count].button_word);
      if (btn[scrn][count].button_enableonlyword) {
        btn[scrn][count].button_enablesimplebox = true;
      }
    }
  }
}


//--------------------------------------------------------------
void ofApp::update() {
  if (btn[2][30].button_enable) {
    if (screen2_counterrorbutton == 0) {
      screen2_saveerrortext = btn[2][30].button_word+"\n";
    }
    screen2_counterrorbutton++;
    btn[2][30].button_word = screen2_saveerrortext + to_string(60 - screen2_counterrorbutton)+"f";
    if (screen2_counterrorbutton > 60) {
      btn[2][30].button_enable = false;
      screen2_counterrorbutton = 0;
    }
  }
  /*set button shadow length*/
  for (int count = 0; count < int(btn[screen].size()); count++) {
    if (!btn[screen][count].button_enablesimplebox) {
      if ((btn[screen][count].button_beginx <=
           ofGetMouseX() &&
           btn[screen][count].button_beginy <=
           ofGetMouseY()) &&
          (btn[screen][count].button_beginx + btn[screen][count].button_endx >=
           ofGetMouseX() &&
           btn[screen][count].button_beginy + btn[screen][count].button_endy >=
           ofGetMouseY())) {
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
  if (frame % 60 == 0) {
    piyohikoy = ofRandom(ofGetHeight());
  }

  if (screen == 2) {
    btn[2][4].button_word = "";
    btn[2][7].button_word = "";
    btn[2][10].button_word = "";
    btn[2][13].button_word = "";
    btn[2][16].button_word = "";

    btn[2][6].button_word = "";
    btn[2][9].button_word = "";
    btn[2][12].button_word = "";
    btn[2][15].button_word = "";
    btn[2][18].button_word = "";

    btn[2][19].button_word = u8"小計:"+
        to_string(screen2_isbndates.size()*BOOKCOST)+u8"";
    if(int(screen2_isbndates.size())<screen2_coupon){
      btn[2][21].button_word = u8"総計:ERROR";
      screen2_switcherror = 1;
    }else{
      btn[2][21].button_word = u8"総計:"+to_string((screen2_isbndates.size()-screen2_coupon)*BOOKCOST);
      screen2_switcherror = 0;
    }
    if (int(screen2_isbndates.size()) > screen2_scrool_begin) {
      btn[2][5].button_word = screen2_isbndates[screen2_scrool_begin];
      btn[2][4].button_word = to_string(screen2_scrool_begin + 1);
      btn[2][6].button_word = to_string(BOOKCOST);
    }
    if (int(screen2_isbndates.size()) > screen2_scrool_begin + 1) {
      btn[2][8].button_word = screen2_isbndates[screen2_scrool_begin + 1];
      btn[2][7].button_word = to_string(screen2_scrool_begin + 2);
      btn[2][9].button_word = to_string(BOOKCOST);
    }
    if (int(screen2_isbndates.size()) > screen2_scrool_begin + 2) {
      btn[2][11].button_word = screen2_isbndates[screen2_scrool_begin + 2];
      btn[2][10].button_word = to_string(screen2_scrool_begin + 3);
      btn[2][12].button_word = to_string(BOOKCOST);
    }
    if (int(screen2_isbndates.size()) > screen2_scrool_begin + 3) {
      btn[2][14].button_word = screen2_isbndates[screen2_scrool_begin + 3];
      btn[2][13].button_word = to_string(screen2_scrool_begin + 4);
      btn[2][15].button_word = to_string(BOOKCOST);
    }
    if (int(screen2_isbndates.size()) > screen2_scrool_begin + 4) {
      btn[2][17].button_word = screen2_isbndates[screen2_scrool_begin + 4];
      btn[2][16].button_word = to_string(screen2_scrool_begin + 5);
      btn[2][18].button_word = to_string(BOOKCOST);
    }

    /*resize shadow and underline*/
    for (int scrn = 0; scrn < int(btn.size()); scrn++) {
      for (int count = 0; count < int(btn[scrn].size()); count++) {
        btn[scrn][count].button_fontx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) -
            (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_fonty = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) +
            (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginx = ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) -
            (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginy = ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) +
            (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinelenght = font.stringWidth(btn[scrn][count].button_word);
        if (btn[scrn][count].button_enableonlyword) {
          btn[scrn][count].button_enablesimplebox = true;
        }
      }
    }
  }
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
  if (screen == 2) {//draw partation
    ofSetColor(240, 240, 240, 200);
    ofDrawLine(
      ofGetWidth() * 1 / 8,
      ofGetHeight() * 2 / 8,
      ofGetWidth() * 1 / 8,
      ofGetHeight() * 8 / 8 - 10
    );
    ofDrawLine(
      ofGetWidth() * 4 / 8,
      ofGetHeight() * 2 / 8,
      ofGetWidth() * 4 / 8,
      ofGetHeight() * 8 / 8 - 10
    );
    ofDrawLine(
      ofGetWidth() * 5 / 8,
      ofGetHeight() * 2 / 8,
      ofGetWidth() * 5 / 8,
      ofGetHeight() * 8 / 8 - 10
    );
    ofDrawLine(
      0,
      ofGetHeight() * 2 / 8,
      0,
      ofGetHeight() * 6 / 8
    );
  }
  for (int count = 0; count < int(btn[screen].size()); count++) {
    if (btn[screen][count].button_enable) {
      if (!btn[screen][count].button_enablesimplebox) {
        ofSetColor(0, 0, 0, 100);//shadow
        ofDrawRectangle(
              btn[screen][count].button_beginx + 5,
              btn[screen][count].button_beginy + 5,
              btn[screen][count].button_endx + btn[screen][count].button_shadowlenght,
              btn[screen][count].button_endy + btn[screen][count].button_shadowlenght
              );
        ofSetColor(
              btn[screen][count].button_r - 10 - btn[screen][count].button_shadowlenght,
              btn[screen][count].button_g - 10 - btn[screen][count].button_shadowlenght,
              btn[screen][count].button_b - 10 - btn[screen][count].button_shadowlenght
              );//button outsidebox
        ofDrawRectangle(
              btn[screen][count].button_beginx,
              btn[screen][count].button_beginy,
              btn[screen][count].button_endx,
              btn[screen][count].button_endy
              );
      }
      if (!btn[screen][count].button_enableonlyword) {
        ofSetColor(
              btn[screen][count].button_r + btn[screen][count].button_shadowlenght,
              btn[screen][count].button_g + btn[screen][count].button_shadowlenght,
              btn[screen][count].button_b + btn[screen][count].button_shadowlenght
              );//button insidebox
        ofDrawRectangle(btn[screen][count].button_beginx + 10,
                        btn[screen][count].button_beginy + 10,
                        btn[screen][count].button_endx - 20,
                        btn[screen][count].button_endy - 20
                        );
      }

      ofSetColor(btn[screen][count].button_wordr - 150,
                 btn[screen][count].button_wordg - 150,
                 btn[screen][count].button_wordb - 150
                 );//buttonword shadow 0
      font.drawString(btn[screen][count].button_word,
                      btn[screen][count].button_fontx + 2,
                      btn[screen][count].button_fonty + 2
                      );

      ofSetColor(btn[screen][count].button_wordr - 75,
                 btn[screen][count].button_wordg - 75,
                 btn[screen][count].button_wordb - 75
                 );//buttonword shadow 1
      font.drawString(btn[screen][count].button_word,
                      btn[screen][count].button_fontx + 1,
                      btn[screen][count].button_fonty + 1
                      );

      ofSetColor(btn[screen][count].button_wordr,
                 btn[screen][count].button_wordg,
                 btn[screen][count].button_wordb
                 );//buttonword
      font.drawString(btn[screen][count].button_word,
                      btn[screen][count].button_fontx,
                      btn[screen][count].button_fonty
                      );

      ofSetColor(255, 255, 255, 200);//buttonword underline
      ofDrawLine(btn[screen][count].button_underlinebeginx,
                 btn[screen][count].button_underlinebeginy + 5,
                 btn[screen][count].button_underlinebeginx + btn[screen][count].button_underlinelenght,
                 btn[screen][count].button_underlinebeginy + 5
                 );
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
    font.drawString(u8"/委員でログイン/本売却:"+ofToString(screen2_switcherror), 0, 30);
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
    screen2_isbndates.clear();
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
    case OF_KEY_RETURN:
      if (inputisbn != "") {
        screen2_isbndates.push_back(inputisbn);
        inputisbn = "";
        if (screen2_isbndates.size() > 5) {
          screen2_scrool_begin=screen2_isbndates.size()-5;
        }
      }
    }

    /*set button pos*/
    for (int scrn = 0; scrn < int(btn.size()); scrn++) {
      for (int count = 0; count < int(btn[scrn].size()); count++) {
        btn[scrn][count].button_fontx =
            ((btn[scrn][count].button_beginx * 2 + btn[scrn][count].button_endx) / 2) -
            (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_fonty =
            ((btn[scrn][count].button_beginy * 2 + btn[scrn][count].button_endy) / 2) +
            (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginx =
            ((btn[scrn][count].button_beginx * 2 +
              btn[scrn][count].button_endx) / 2) -
            (font.stringWidth(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinebeginy =
            ((btn[scrn][count].button_beginy * 2 +
              btn[scrn][count].button_endy) / 2) +
            (font.stringHeight(btn[scrn][count].button_word) / 2);
        btn[scrn][count].button_underlinelenght =
            font.stringWidth(btn[scrn][count].button_word);
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

  for (int count = 0; count < int(btn[screen].size()); count++){
    if ((btn[screen][count].button_beginx <= x &&
         btn[screen][count].button_beginy <= y) &&
        (btn[screen][count].button_beginx + btn[screen][count].button_endx >= x &&
         btn[screen][count].button_beginy + btn[screen][count].button_endy >= y))
    {
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
        case 22:
        {
            cout<<"pushed \"KAKUTEI\""<<endl;
            bool noerror = false;
            {
              for (int counter_0 = 0; counter_0<int(screen2_isbndates.size()); counter_0++) {
                for (int counter_1 = 0; counter_1<int(isbnrawlist.size()); counter_1++) {
                  if (screen2_isbndates[counter_0] == isbnrawlist[counter_1]) {
                    noerror = true;
                  }
                }
                if (noerror) {//found num in isbnrawlist
                    /*search in inbnsoldlist*/
                  for (int counter_1 = 0; counter_1<int(isbnsoldlist.size()); counter_1++) {
                    if (screen2_isbndates[counter_0] == isbnsoldlist[counter_1]) {
                      noerror = false;
                      screen2_switcherror = 3;
                    }
                  }
                }
                else {
                  screen2_switcherror = 2;
                }
              }
            }
            if (!noerror) {
              cout << "Erororororor:" << screen2_switcherror << endl;
              switch (screen2_switcherror) {
              case 0:
                btn[2][30].button_word = u8"なんかよく分からんエラーです";
                break;
              case 1:
                btn[2][30].button_word = u8"クーポン多すぎ";
                break;
              case 2:
                btn[2][30].button_word = u8"元データに本が存在しません\n推奨:これどうしようもないんで\n紙にでも書いといてください";
                break;
              case 3:
                btn[2][30].button_word = u8"もうこの本は売れてるはずです\n推測:二回スキャンした";
                break;
              }
              btn[2][30].button_enable=true;
              cout << "changed" << endl;
            }
            bool tr=false;
            /*search in isbnrawlist*/
            for(int counter_0=0;counter_0<int(screen2_isbndates.size());counter_0++){
                tr=false;
                for(int counter_1=0;counter_1<int(isbnrawlist.size());counter_1++){
                    if(screen2_isbndates[counter_0]==isbnrawlist[counter_1]){
                        tr=true;
                    }
                }
                if(tr){//found num in isbnrawlist
                    /*search in inbnsoldlist*/
                    tr=false;
                    for(int counter_1=0;counter_1<int(isbnsoldlist.size());counter_1++){
                        if(screen2_isbndates[counter_0]==isbnsoldlist[counter_1]){
                            tr=true;
                        }
                    }
                    if(tr){//found num in isbnsoldlist(error)
                      cout<<"found num in isbnsoldlist(error)"<<endl;
                    }else{//not found(true)
                      cout<<"found"<<endl;
                      //write to isbnsoldlist
                      ofstream ofs_sold("isbnsoldlist.txt",std::ios::app);
                      ofs_sold << screen2_isbndates[counter_0] << endl;
                      ofs_sold.close();
                      isbnsoldlist.push_back(screen2_isbndates[counter_0]);
                    }
                }else{//not found(error)
                  cout<<"not found"<<endl;
                }
            }
            ifstream ifs("isbncouponlist.txt");
            string str = "";
            getline(ifs, str);
            ifs.close();
            ofstream ofs_coup("isbncouponlist.txt", std::ios::trunc);
            ofs_coup << ofToString(atoi(str.c_str()) + screen2_coupon) << endl;
            ofs_coup.close();
        }
          break;
        case 23:
          if(screen2_scrool_begin != 0){
              screen2_scrool_begin--;
          }
          break;
        case 24:
          if(screen2_scrool_begin < int(screen2_isbndates.size())-5){
              screen2_scrool_begin++;
          }
          break;
        case 25:
          screen2_scrool_begin = 0;
          screen2_coupon = 0;
          screen2_isbndates.clear();

          btn[2][5].button_word = "";
          btn[2][8].button_word = "";
          btn[2][11].button_word = "";
          btn[2][14].button_word = "";
          btn[2][17].button_word = "";

          break;
        case 26:
          screen2_coupon++;
          cout << "coupon: " <<screen2_coupon<< endl;
          btn[2][20].button_word = u8"" + to_string(screen2_coupon) + u8"個";
          btn[2][29].button_word = u8"クーポン割引:"+to_string(screen2_coupon*BOOKCOST) + u8"";
          break;
        case 27:
          if (screen2_coupon != 0) {
            screen2_coupon--;
            cout << "coupon: " <<screen2_coupon<< endl;
            btn[2][20].button_word = u8"" + to_string(screen2_coupon) + u8"個";
            btn[2][29].button_word = u8"クーポン割引:"+to_string(screen2_coupon*BOOKCOST) + u8"";
          }
          break;
        case 30:
          //btn[2][30].button_enable=false;
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
  screen2_isbndates.clear();
  screen2_scrool_begin = 0;
  screen2_coupon = 0;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}
