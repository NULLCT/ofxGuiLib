#include "Button.h"
void Button::check(int mousex,int mousey){//checkにはマウスの座標を入れること
  if(((xb < mousex && yb < mousey )&& xe > mousex) && ye > mousey){//ボタン内か？
      tr=true;//trはカーソルがボタンの中に入ってるかどうかを示す
    }else{
      tr=false;
    }
}
void Button::draw(){//ボタン描画
  if(tr){//カーソルが入ってきたらちょっと大きめに描画
      ofSetColor(20,20,20,130);
      ofDrawRectangle(xb-20,yb-20,xe+40,ye+40);
      ofSetColor(r,g,b);
      ofDrawRectangle(xb-10,yb-10,xe+20,ye+20);
    }else{
      ofSetColor(20,20,20,100);
      ofDrawRectangle(xb-10,yb-10,xe+20,ye+20);
      ofSetColor(r,g,b);
      ofDrawRectangle(xb,yb,xe,ye);
    }
}
bool Button::moused(){//マウス入ってる？
  return tr;
}
