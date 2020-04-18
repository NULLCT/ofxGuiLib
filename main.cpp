#include "ofMain.h"
#include "ofApp.h"
int main() {
  ofSetupOpenGL(1280, 720, OF_WINDOW);//OF_FULLSCREEN
  ofRunApp(new ofApp());
}
//以下私的なメモ
//TODO:
/*
  - 売却した際に諸々をファイルに書き込む設定を作る
  - screen[2]のUIをわかりやすくする
*/
/*
  データ保持構造は以下のとおりです
    - すべての本のISBNを行ごとに記録したファイル...isbnrawlist.txt(読み書き)
    - 売却した本のISBNを行ごとに記録したファイル...isbnsoldlist.txt(読み書き)
    - 売却した本の中でも、クーポンを適用した本のISBNを行ごとに記録したファイル...isbncouponlist.txt(読み書き)
    
    これらをすべてまとめた物を...result.csv
    - 一行目: 本のISBN
    - 二行目: その本が売れているかどうかをTrue/Falseで記す
    - 三行目: その本がクーポンを使って買われたのかをTrue/Falseで記す
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
  0:[本売却]
  1:[本一覧/検索]
  2:[使い方]
  3:[何かあったら] [テキストボックス(色々かける)]
seet 2:本売却
  0:[バーコードをスキャンしてね!!!]
  1:[クーポンを使うなら右のボックスをクリック]
  2:[(ここにISBNを表示)]
  3:[チェックボックス]
  4:[確定]
  5:[アラート(この本はもう売れているはず...とか)]
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

