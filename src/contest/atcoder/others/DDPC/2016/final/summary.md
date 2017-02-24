---
title        : DDPC2016 本戦 参加記
date         : 2016-02-22T23:00:56+09:00
contests     : atcoder
problemtypes :
- 参加記

---


　CodeFestivalや、ICPCは参加記書こうと何度も思いつつ、結局書かなかったので今回こそは書く。

<!--more-->

## 予選

自分は１７卒じゃないので２０位に入らないといけない、本戦は無理だろうなぁ、、、って感じで、テスト勉強の境になんとなく参加した。

A,Bがバグなく比較的早く解けて、この時点で順位が結構良かったので驚く。あとでtwitterを見ているとBで誤読したりバグらせて時間を消費した人が多かったらしい。

C,Dを見て、Dの10点が本当にやるだけだったのでとりあえずやる。この時点でなんかかなりいい順位になってて驚いていた。

Cは最初分からなかったが、いろいろ考えたら40点までは行けそうな解法が出てきた。Cの部分点を取れば本戦いけるんじゃないの？って状況な気がしたので、満点は諦めてとりあえず部分点を狙いに行く。ちなみに満点は自分の考察にSuffixArrayを加える感じだったが、SuffixArrayは名前しか聞いたことがなかったので良い選択だった。SuffixArrayは学んだけど、今見たら問題はまだ解いてなかったので解いておかないと...

バグで少し悩んだような記憶もあるけどとりあえず40点獲得、この時点で２０位周辺になり、本戦が見え始める。

その後Cをもう少し考えて、うまく実装すれば満点行けそうな気分になったところで終了、少し順位が下がったものの２４位だったので本戦の日程を確認。後日予選通過のメールが来た。

twitterを見ると、CでSuffixArrayまで気づいていた人はかなり多かったが、みんなバグらせていたような感じだった。運が良い？

## 本戦前日

　前日の朝から東京入りして少し観光しようとしていたが、２日前の深夜になって、本戦登録時に自動メールが来ることを知る。（自分には来ていないor迷惑メールで葬り去られた?（確認はしていたつもり））登録失敗か、と思ったが、朝になって電話で確認したらちゃんと登録できていて、登録したアドレスも間違っていないらしい。確認完了したのが家を出るべき時刻の１０分前とかだったのでとても焦った。

　ともあれ、登録できていたので安心して東京へ。観光と言っても、行くところは考えてなかったので秋葉原で電子部品とかPC系の店を転々として時間を潰した。
ホテルは会場の近くで8000円以内だとカプセルしかなかったらしいが、自分はちょっと会場まで遠い、普通のビジネスホテルにした。枕は固いが結構良いホテルだった。

## 本戦

朝の起床は余裕で成功。twitterを見て同じ学科の先輩が参加することを知る。会場まではJRの大森駅から歩くが、大森駅周辺の密度が高く、迷いそうで不安だった。（迷わなかった）

少し遅れて開会式が始まる。最後にchokudaiさんがルール説明をするが、遅れて始まったせいでコンテスト開始時間が迫る。説明後すぐに開始のカウントダウンが始まったが、3秒ほど間に合わず。

ともあれ、コンテスト開始。

[A問題](http://blog.cormoran-web.com/procon/contest/atcoder/others/ddpc/2016/final/A)

適当に読んで適当に書いて提出。WA。

ちょっと焦るが、冷静になってAC。

[B問題](http://blog.cormoran-web.com/procon/contest/atcoder/others/ddpc/2016/final/B)

貪欲っぽいけどうまくできない、2分探索したらうまくできる？？？、できない（本当はできる）って感じでとりあえず放置して他の問題を読む。

Cは括弧の文字列で面白そうだったけど数え上げはちょっと..って感じでBに戻る。

Bを考えると貪欲で行けそう、ってなって書く、サンプルは通ったので提出、TLE。

もう一度考えるとTLEして当然だった。セグメント木でうまく改良できそうだったので修正、提出。幾つかのバグで苦しむもAC。

[C問題](http://blog.cormoran-web.com/procon/contest/atcoder/others/ddpc/2016/final/C)

Cを考える。再帰的にやれば、部分点は取れそうなことがわかったので実装。時間との戦い。

一応時間内に大体実装できたが、実行したら配列外アクセスとかで死ぬ。配列の添え字にマイナス使うの初めてだったかもしれない。

バグを一つづつ潰していくが、他にもいろいろミスっていたようで答えが合わず、いろいろやっているうちにコンテスト終了。A,Bを解いて３４位だった。

予選よりも悪いけれど、Cが全くダメだったわけではないのでその点まあ満足。

終了後にCの解法を聞いたら、方針は同じらしい。木DPの典型問題らしいが、木DPは数えるほどしか書いたことがない...

後でmapに逃げて再帰のままで解いたら満点になった。忙しくてまだ木DPとかを復習できてないけどこれはちゃんとやっておきたい。

Dは読んだだけ、Eは読んでいない。少なくともDはやっておこうと思う。



## その後

　ディスコの会社紹介、落合先生の講演、ディスコ社内ツアーがあった。

　会社紹介ではディスコの正体を知って驚いた。事前にディスコとディスカバリーチャンネルは違うという情報を得ており、さらっと調べたが、その時は何故かディスコがディスカバリーチャンネルの親会社なのか、っていう結論になっていた。（本当に何故こうなったのか謎、記憶がない）ディスコのロゴがディスカバリーチャンネルロゴと雰囲気似ているのも原因？ロボットをやってることもあって、趣味的だけど精密加工のマシンとかは好きなので、もうちょっとちゃんと調べておけばよかったと少し後悔した。

　事前情報

<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">明日のDDPC(DISCO presents ディスカバリーチャンネルプログラミングコンテスト)のハッシュタグです！DISCOとディスカバリーチャンネルは全然違う会社です！お間違いなく！！！ <a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a></p>&mdash; chokudai(高橋 直大) (@chokudai) <a href="https://twitter.com/chokudai/status/700574545355247618">2016, 2月 19</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

　思いっきり間違っていた。同じこと思ってた人発見。
<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">そういえば僕はディスコをディスカバリーチャンネルを作るスタジオ会社だと思ってたせいで事業紹介でびっくりした　<a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a></p>&mdash; きゅうり (@kyuridenamida) <a href="https://twitter.com/kyuridenamida/status/700928034732318720">2016, 2月 20</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

　落合先生の講演は、Kobe IT Festivalで１度聞いていたり、魔法の世紀を読んでいたりしたこともあっていい感じに理解して聞けた気がする（気分だけ）。法律はGitHubでいいそうです...。うまくまとまっていたけど、本人も言っていたようにプロコンで落合さんっていうのはやっぱりちょっと謎で、上のことも相まって謎なコンテストだなぁって感じ。（笑）

　社内ツアーは思ったより楽しかった。他の会社をあまり知らないのでなんとも言えないけど、あの建物だけでプールとか寮があってかなり充実した建物らしいことはわかった。渡り廊下の無駄にずらして重なり合った感じとかは好きだった。

## 食事

　昼食「DDPC特別ビュッフェ」。偏食の塊なのでビュッフェとかにしてくれると本当に嬉しい。おなかいっぱい食べられた。勝手なこと言うと、寿司は納豆とカッパ巻き希望.

　食事中にディスカバリーチャンネルにインタビューされたけど、変な感じにありきたりなことしか答えられなかった。申し訳ない。

　画像を拝借。Twitterは便利。

<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">(( &#39;ω&#39; 三 &#39;ω&#39; )) <a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a> <a href="https://t.co/J9ycaoBWGb">pic.twitter.com/J9ycaoBWGb</a></p>&mdash; とっきー (@tokky_cpp) <a href="https://twitter.com/tokky_cpp/status/700888482974031872">2016, 2月 20</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>


　余談だが、上の画像を見てイチゴを食べていないことに気づき、ショックを受けた。
　

　懇親会ではDDPC特別ビュッフェⅡ（？）と、DDPC特別ケーキ（？）が出た。

　昼食、懇親会ともに結構時間が長く、コミュニケーション能力が著しく低いので幾度も危機に陥ったが適度に人と話すことはできた。

　画像発見

<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">特別ビュッフェであんなに食ったのにまた食事フェーズなのか…<a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a> <a href="https://t.co/P4yddzEoPY">pic.twitter.com/P4yddzEoPY</a></p>&mdash; っこ|KO@精進したい (@sujinbemani_79c) <a href="https://twitter.com/sujinbemani_79c/status/700941670297182208">2016, 2月 20</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

ケーキは完全体を発見できず。

<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">解散<br>お疲れ様でした<br> <a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a> <a href="https://t.co/cPmJIGPyKe">pic.twitter.com/cPmJIGPyKe</a></p>&mdash; 榴弾を撃ち込むナナシ (@04nanashi09) <a href="https://twitter.com/04nanashi09/status/700966205746577408">2016, 2月 20</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

　イチゴのケーキだったのでお昼の不満は解消。ただ、ケーキに気づいた頃には半分以上なくなっていて少し危なかった。


## まとめ
　競技以外にも様々な楽しみがあってとてもいい感じのコンテストでした。

　来年も、って話がしきりあったので来年も期待しています。来年は卒業生枠に入れるから高確率で行ける？？　とか言ってないで強くなれるよう精進します。


<blockquote class="twitter-tweet" data-lang="ja"><p lang="ja" dir="ltr">DDPC集合写真です！ <a href="https://twitter.com/hashtag/ddpc2016?src=hash">#ddpc2016</a> <a href="https://t.co/Hip0UiXVxV">pic.twitter.com/Hip0UiXVxV</a></p>&mdash; chokudai(高橋 直大) (@chokudai) <a href="https://twitter.com/chokudai/status/700966703035842560">2016, 2月 20</a></blockquote> <script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>
