all: main.comp.cpp
	g++-6 -std=c++11 main.comp.cpp -O3
	rm out && ./a.out < ./tool/input.txt > out
	cd ./tool && java Judge input.txt ../out

