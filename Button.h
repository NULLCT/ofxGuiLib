#ifndef BUTTON_H
#define BUTTON_H
#include<string>
#include "ofMain.h"
using namespace std;

class Button
{
public:
  int xb,yb,xe,ye;
  int r,g,b;
  int frames=-1;
  string text;
  bool tr=false;//トリガー。ボタンが押されたらtrueに
  void check(int mousex,int mousey);//当たり判定とか
  void draw();//ボタン描画
  bool moused();
};

#endif // BUTTON_H
