CC=clang

all: compile test

compile:
	cd src;\
	$(CC) -lm -g -v -o ../csudoku.out main.c io.c sudoku.c

test: compile
	./csudoku.out < res/sudoku_01.txt # sudoku ueber stdio eingaeben
	./csudoku.out < res/sudoku_02.txt # sudoku ueber den f (file) parameter angeben
	./csudoku.out < res/sudoku_03.txt # Unschaffbares Sudoku
	./csudoku.out < res/sudoku_04.txt # Sudoku aus dem Beispielcode
	./csudoku.out x < res/xsudoku.txt # X-Sudoku

clean:
	rm csudoku.out
	rm Dokument.pdf
	rm csudoku-mhaidn-jklepp.zip

doc:
	rst2pdf -o Dokument.pdf README.rst

dist: doc compile
	git log --stat > repo.log
	zip csudoku-mhaidn-jklepp Makefile README.rst Dokument.pdf repo.log src/* res/*
