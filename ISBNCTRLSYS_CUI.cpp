/*/////////////////////////////////////////////////////////////////////////////////////
DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
Version 2, December 2019

Copyright (C) 2019 Nari Yu <cockatiel.u10++@gmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

0. You just DO WHAT THE FUCK YOU WANT TO.
(訳):どうとでも勝手にしやがれクソッタレ・公衆利用許諾(契約)書
*//////////////////////////////////////////////////////////////////////////////////////

/*
　　　　　　　　　,..-‐－-　､、　　　　　　　　＿＿＿＿＿＿＿＿＿
　　　　　　　,ィ":::::::::::::::::::;;;;;:ii>;,、　　　　／
　　　 　 　 /:::::::::::::::;;;;;;;;iii彡" :ﾔi､　　　/
　　　　 　 i::::::::::::;:"~￣　　 　 ::i||li　　＜　　３分間待ってやる
　 　 　 　 |:::::::::j'_,.ィ^' ‐､　_,,. ::iii》　　　|
　　　　　　|:::i´｀ 　`‐-‐"^{" ｀ﾘ"　　　 ＼
　　　 　 　 ヾ;Y　　　　　,.,li｀~~i　　　　　 ￣￣￣￣￣￣￣￣￣￣
　 　 　 　 　 ｀i、 　 ･=-_､,　.:/
　　　 　　　　| ヽ　　　 ''　 .:/
ー--　,,__,,,　|　　 ` ‐- ､、ノ
;;;;;;;l;;;;;;;ヽ_￣｀`''‐- ､ , -‐}
;;;;;;l;;;;;;;;;;;ヽ￣`''‐- ､l!/／{`‐-､
l;;;;;;`''=‐-　＼‐-ｯ'´　', ' ,ヽ;;;;ヽ＼_
;;;;;;;;;;;`'‐ ､;;;;;;;;;;;>'　　　',　' ,ヽ＜;;;;;;￣`'‐､
l;;;;;;;;;;;;;;;;;;;;;`'‐ /　　　　 , 　 '　ヽ/;;;;;;;;;;;;;;;;;ヽ　　　　　　
.┯━━━━━━━┯
;;i;;;;;;;;;;;;;;;;;;;;;;;;;l　　　　　
,　　　　l;;;;;;;;;;;i;;;;;;;;;;;l!　　　　　　　1∨ﾞ　/　丘 ﾉ吾〒.l
/;;;;;;;;;;;;;;;;;;;;;-‐`‐-‐i''‐-､　　 _ ,,
l;;;;;;;;;;;l::::::::::::l　　　　　　　| し /^し ﾊ .ｲヰ.｣ .|
;;;;;;;;;;;;;;;;;;‐'´-‐''' ´ {_,,r''
_,,r''-‐'';;;;;;;;;;;;;;;l;;;;;;;;;;;l　　　　　　　ヽ＿＿＿＿＿＿ノ
;;;;;;;;;;;;;;;;;;;_,,_;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;l;;;;;;;;;;l┌────┴─────┴──
*/
// MEMO↓
//何かあったら特別藩とかのpeopleに連絡取ってください。
// 99999冊までのISBNに(一応)対応しています。
//命令セットやOS、コンパイラによって変動する可能性があります。
//なお、このプログラムによって生じたありとあらゆることに対して製作者は責任を取りかねます。
//ご了承ください＼(^o^)／
//実行時に、dates.txtとdates_uttayatuが出力されます。
//絶対消すなよ！
//推奨環境↓
/*
        :コンパイラ:Clang
        :100kb程度のディスク空き容量
        :ちょっとした知識
        :やる気
        :根気
        :努力
        :ピッてやるやつがあるとなお良い
*/
//(^O^)が出てきたらエラーだと思ってください。
//ソースがクソ汚いです。多分後で直します
#include <stdio.h>  //要らない
#include <cstdlib>  //あんま要らない
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//#define DEBUG
//↑諸々のボツ機能を召喚できます。そのままだとエラー出るけど
int main(int argc, char** argv) {
  vector<string> list;           // ISBNリスト
  vector<string> list_allready;  //販売済みのISBNリスト
dateinput:                       // goto (ax)
  int i = 0;
  bool tr = false;
  cout << "データを入力してください" << endl
       << "(e) を入力すると入力が終わります" << endl;
  string word = "";
  for (i = 0;; i++) {
    cout << ":";
    cin >> word;
    if (word == "e") {
      break;
    } else {
      list.push_back(word);
    }
  }

  while (true) {
    tr = false;
    cout << "\n本販売:(d)\n本追加:(a)\n本検索:(s)\nISBN表示:(v)\nhelp:(h)"
         << endl
         << "どれかを入力してください" << endl;
    cout << ":";
    cin >> word;
    cout << endl;
    if (word == "d") {  //削除
      cout << "売却する本のISBNを入力してください" << endl << ":";
      cin >> word;
      for (i = 0; i != static_cast<int>(list.size()); i++) {
        if (list[i] == static_cast<string>(word)) {
          tr = true;
          break;
        }
      }
      if (!tr) {
        cout << "ISBNが見つかりませんでした" << endl;
        cout << "残念だったな(^O^)" << endl;

      } else {
        cout << i << " 番目にISBN: " << word << "が見つかりました" << endl;
        cout << "本の売却処理を行います..." << endl;
        list_allready.push_back(list[i]);
        swap(list[i], list.back());
        list.pop_back();
        cout << "処理が完了しました" << endl;
      }

    } else if (word == "a") {  //追加
      cout << "何を追加しますか？" << endl;
      cout << ":";
      cin >> word;
      list.push_back(word);
      cout << endl
           << word << "を" << list.size() << "番目に追加しました" << endl;
      for (int i = 0; i != list_allready.size(); i++) {
        if (list_allready[i] == word) {
          swap(list_allready[i], list_allready.back());
          list_allready.pop_back();
          tr = true;
          break;
        }
      }
      if (tr) {
        cout << i << "番目の" << word << "を売却した本から削除しました" << endl;
      } else {
        cout << "売却リストに" << word << "が見つかりませんでした(^O^)" << endl;
        cout << "データインプットが正確に行えていない可能性があります。" << endl
             << "特別藩とかに連絡を取ってください" << endl;
      }
    } else if (word == "s") {  //検索
      cout << "何を検索しますか?" << endl;
      cout << ":";
      cin >> word;
      for (int i = 0; i != static_cast<int>(list.size()); i++) {
        if (list[i] == word) {
          cout << i << "番目に" << word << "が見つかりました・ω・" << endl;
          tr = true;
          break;
        }
      }
      if (!tr) {
        cout << word << "は見つかりませんでした(^O^)" << endl;
      }

    } else if (word == "v") {  //表示
      cout << list.size() << "個のISBNを出力します...\n" << endl;
      for (i = 0; i != static_cast<int>(list.size()); i++) {
        cout << list[i] << endl;
      }
      cout << "\n出力が完了しました" << endl;
      cout << "すべての要素が出力されていませんか？ "
              "cmdのバッファ設定を確認してみてください。"
           << endl;
    } else if (word == "f") {  //ファイル出力

      cout << "ファイル出力を開始します..." << endl;
      ofstream ofs("dates.txt");
      for (i = 0; i != static_cast<int>(list.size()); i++) {
        ofs << list[i] << endl;
      }
      ofs.close();
      cout << "出力が完了しました" << endl;

    } else if (word == "r") {  //ファイル入力
#ifdef DEBUG
      cout << "dates.txtをアプリケーションと同じパスに配置しましたか? "
              "したのなら(ok!)"
           << endl;
      cout << "なお、既存のデータは全て上書きされます" << endl;
      cin >> word;
      if (word == "ok!") {
        cout << "処理を開始します..." << endl;
        ifstream ifs("dates.txt");
        if (ifs.fail()) {
          tr = true;
          cout << "読み込めませんでした(^O^)" << endl;
          cout << "以下の原因が考えられます:" << endl;
          cout << "-ISBN管理アプリケーション.exeと同じパスに配置しましたか?"
               << endl;
          cout << "-Windows Defender "
                  "などのソフトウェアが読み込みを阻止している可能性があります。"
                  "一度オフにしてください"
               << endl;
          cout << "名前は、dates.txt になっていますか？" << endl;
          cout << "以上のどの問題にも当てはまらない場合、致命的な蟲が発生してい"
                  "る可能性があります"
               << endl;
          cout << "レポートファイルを作成しますか？　するなら(ok!)" << endl
               << ":";
          cin >> word;
          if (word == "ok!") {
          } else {
            cout << "中断されました" << endl;
          }
        }
        i = 0;
        list.clear();
        FILE* fp;
        char buf[99999] = {0};
        if ((fp = fopen("dates.txt", "r")) != NULL) {
          /*ファイルの終わりまで繰り返し読み込む*/
          while (fgets(buf, 99999, fp) != NULL) {
            list[i] = buf;
            i++;
          }
        }
        cout << "読み込みが完了しました。" << endl;

      } else {
        cout << "ファイル読み込みを中断します" << endl;
      }
#endif
    } else if (word == "e") {  //閉じる
      cout << "本当に閉じますか?" << endl << "閉じるなら(e)を" << endl;
      return 0;
    } else if (word == "h") {
      cout << "//copyright 2019 NULL_CT licenced by : Do What The Fuck You "
              "Want To Public Licence\n\n";
      cout << "//"
              "何かあったら特別藩とかの人間に連絡を取ってください。\nなんとかな"
              "るはずです。"
           << endl;
      cout << "//99999冊までのISBNに(一応)対応しています。" << endl;
      cout << "//命令セットやOS、コンパイラによって変動する可能性があります。"
           << endl;
      cout << "//"
              "なお、このプログラムによって生じたありとあらゆることに対して製作"
              "者は責任を取りかねます。"
           << endl;
      cout << "//ご了承ください＼(^o^)／" << endl;
      cout << "//推奨環境↓" << endl;
      cout << "/*" << endl;
      cout << ":100kb程度のディスク空き容量" << endl;
      cout << ":ちょっとした知識" << endl;
      cout << ":やる気" << endl;
      cout << ":根気" << endl;
      cout << ":努力" << endl;
      cout << ":ピッてやるやつがあるとなお良い" << endl;
      cout << "*/" << endl;
      cout << "//(^O^)が出てきたらエラーだと思ってください。" << endl;
    } else if (word == "ax") {  //連続入力
      goto dateinput;
    } else if (word == "dx") {  //全データ削除
      cout << "本当に全てのデータを削除しますか? するなら(ok!)" << endl << ":";
      cin >> word;
      if (word == "ok!") {
        list.clear();
      } else {
        cout << "中止しました。" << endl;
      }
    } else if (word == "danbou") {  //暖房
#ifdef DEBUG
      cout << "!!このまま実行すると取り返しのつかないことになる場合があります!!"
           << endl;
      cout << "password:";
      cin >> word;
      if (word == "forkbomb") {
        cout << "本当に実行しますか？(ok!)" << endl;
        cout << ":";
        cin >> word;
        if (word == "ok!") {
          cout << "闇に落ちるが良い(ﾟ∀ﾟ)" << endl;
          while (true) {
            system(argv[0]);
          }
        }
      }
#endif
    } else if (word == "l") {  //販売済みのISBNを出力

      cout << "販売した本のISBNを出力します..." << endl;

      for (int i = 0; i != static_cast<int>(list_allready.size()); i++) {
        cout << list_allready[i] << endl;
      }

      cout << "出力を完了しました" << endl;

    } else if (word == "ICBNADMIN") {  //管理者向け隠しコマンド一覧表示

      cout
          << "本売却:(d)\n本追加:(a)\n連続して本追加:(ax)\n本検索:(s)"
             "\nISBN表示:(v)\nデータをファイル出力:(f)\nISBN管理アプリを閉じる:"
             "(e)\nhelp:(h)\n販売した本のISBNを表示する:(l)"
             "\n販売した本のISBNを全てファイル出力する:(fx)"
             "\n販売した本のISBNを連続で入力する:(lo)\nCopyright:(c)"
             "\n暖房をつける:(danbou)\n販売したISBNデータをすべて消す:(ld)"
          << endl;

    } else if (word == "fx") {  //販売済みISBNをファイル書き出し

      cout << "ファイル出力を開始します..." << endl;
      ofstream ofs("dates_uttayatu.txt");
      for (i = 0; i != static_cast<int>(list_allready.size()); i++) {
        ofs << list_allready[i] << endl;
      }
      ofs.close();
      cout << "出力が完了しました" << endl;

    } else if (word == "lo") {  //販売済みISBNを連続書き込み

      cout << "入力を終了するには、(e)を入力してください" << endl;
      for (int i = 0;; i++) {
        cout << ":";
        cin >> word;
        if (word == "e") {
          break;
        }
        list_allready.push_back(word);
      }
      cout << "入力が終了しました" << endl;

    } else if (word == "c") {  //こぴーらいと

      cout << "DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE\n";
      cout << "Version 2, December 2019\n";

      cout << "Copyright (C) 2019 Nari Yu <cockatiel.u10++@gmail.com>\n";

      cout << "Everyone is permitted to copy and distribute verbatim or "
              "modified\n";
      cout << "copies of this license document, and changing it is allowed as "
              "long\n";
      cout << "as the name is changed.\n";

      cout << "DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE\n";
      cout << "TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND "
              "MODIFICATION\n";

      cout << "0. You just DO WHAT THE FUCK YOU WANT TO.\n\n\n";

      cout << "(訳):どうとでも勝手にしやがれクソッタレ・公衆利用許諾(契約)書\n";

    } else if (word == "ld") {
      cout << "本当にデータ(販売済みISBN)を削除しますか？(ok!)" << endl;
      cin >> word;
      if (word == "ok!") {
        list_allready.clear();

      } else {
        cout << "中止されました" << endl;
      }

    } else {  //未確認文字集合体
      cout << "そんなコマンドは存在しません(^O^)" << endl;
    }
  }
}
