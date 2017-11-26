+++
title = "ICPC"
date = "2017-07-14T00:00:00+09:00"
[menu.library]
Name = "ICPC"
identifier = "ICPC"
parent = ""
+++

<!--more-->

## 各種コマンド

~~~ sh
#コンパイル
alias cxxg=g++ -std=c++14  -Wall -Wextra -DDEBUG -D_GLIBCXX_DEBUG -fsanitize=address -Wfloat-equal -Wshadow
alias cxx=g++ -std=c++14  -Wall -Wextra -Wfloat-equal -Wshadow -O3
# スタック拡張
ulimit -s 1048576
~~~

## emacs

~~~
(global-linum-mode t)
(column-number-mode t)
(line-number-mode t)
(global-set-key "\C-h" 'delete-backward-char)
(add-hook 'c++-mode-hook 'flymake-mode)
~~~

## makefile

~~~ makefile
check-syntax:
	g++ -Wall -Wextra -Wshadow -fsyntax-only -std=gnu++14 $(CHK_SOURCES)
~~~