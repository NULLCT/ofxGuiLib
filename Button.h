#ifndef BUTTON_H
#define BUTTON_H
#include<string>
#include "ofMain.h"
using namespace std;
class Button//ボタンクラス。ボタンとして押された時、マウスが入ってきた時、などの関数があります
{
public:
  int xb,yb,xe,ye;//(xb,yb)から下にxe,右にyeまでのボタン
  int r,g,b;//rgb。色。
  string text;//この中に表示したい文字を。

  void check(int mousex,int mousey);//当たり判定とか
  void draw();//ボタン描画
  bool moused();//マウスがボタンの中にあるのか？
private:
  bool tr=false;//トリガー。ボタンの中にカーソルが入ってきたらtrueに
  int frames=-1;//押されたときのフィードバック用
};
#endif // BUTTON_H
