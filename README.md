# ISBNCTRLSYS
## 本をISBNで管理するシステム
### 使用ライブラリ
- openframeworks
### ソースファイル以外に必要なもの
#### 以下は.exeと同じパスに格納。ない場合はエラーが出まくります:
- isbncouponlist.txt(いくつクーポンが使われたかを格納)
- isbnrawlist.txt(すべての本のISBNを格納)
- isbnsoldlist.txt(売れた本のISBNを格納
- logo.txt(開始時に表示されるテキストを格納)
- text.txt(screen[2]に表示されるであろう文字を格納)
#### 以下は.exeと同じパスにあるdate/に格納。必須:
- Cica.ttf(このリポジトリに入れるとライセンスがめんどくさくなりそうなので省いた)
- その他hogehoge画像
### キー判定について
- f ウィンドウをリサイズ
- h ホームに戻る
#### ほげほげ
- screen2のボタン数が30を突破  
windows環境で試したときがぎがぎだったから本番環境で動くか不安  
releaseでビルドすればマシになるか...?
