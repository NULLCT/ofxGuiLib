#include "Button.h"
void Button::check(int mousex,int mousey){
  if(((xb < mousex && yb < mousey )&& xe > mousex) && ye > mousey){
      tr=true;
    }else{
      tr=false;
    }
}
void Button::draw(){
  if(tr){
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
bool Button::moused(){
  return tr;
}
