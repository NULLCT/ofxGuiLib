#include "ofMain.h"
#include "ofApp.h"
int main() {
  ofSetupOpenGL(1280, 720, OF_WINDOW);//OF_FULLSCREEN
  ofRunApp(new ofApp());
}
//以下私的なメモ
//TODO:
/*
  -とりまα版作る。
  -塚様曰く本には学校発行のバーコードを貼るらしい...
  内容としては9桁の数字がインプットされるらしいのでint型に収まる...?
  でもstring,charのほうが管理しやすいのか。
  -実行時遅い理由として考えられる-インスタンス毎に実行に糞時間がかかる
  setting.addlanguageを実行している...
  ポインタ使ってnew Buttonとかしてフォントデータを全てのインスタンスが参照するように出来ないか..?
  分からね。アロー演算子とか使うんだろうなぁ...
  ↑インスタンスごとにsetupしないといけないからリソース消費が増えるのは当たり前なんだよなぁ....
  classからstructに変更しましたぁ
*/
//MEMO:
//色
/*
#63FFD6 brue
#BBE85A green
#FFCB6F yellow
#E85A5E red
#AA87FF purpule
*/
//以下は画面構成。screen変数を操作することによって画面切り替えをする。
//最悪データのcsvを弄る...?
//portableVSCode持ってこよう
/*
seet 0:
  0:[委員でログイン]1:[管理でログイン]
seet 1:委員でログイン
  2:[本売却]
  3:[本一覧/検索]
  4:[使い方]
  5:[何かあったらこのボタンを押そう]6:[テキストボックス(色々かける)]
seet 2:本売却
  6:[ISBNをここに入力して、「確定」ボタンを押してください]
  7:[クーポンなら右のチェックボックスを押してね]8:[ ]
seet 3:本一覧/検索
  [ISBNhogehoge]	[検索バー]
  [ISBNhogehoge]  [ヒットした本]
  [ISBNhogehoge]  [以下の本に対しての操作]
  .
seet 4:使い方
  [動画とか再生しておこう！]
seet 5:何かあったらこのボタンを押そう！
  [エラー内容をスマホで撮って図書委員LINEに送信してください。]
seet 6:管理でログイン
  [Password:(syatiku)]
  9:[GodMode]
seet 7: GodMode
  [イラストや]	10:[操作]
  [ISBN]			[hogehoge]
 */

