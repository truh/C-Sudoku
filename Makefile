CC=gcc

all: compile test

compile:
	cd src;\
	$(CC) -lm -o ../csudoku.out main.c

test: compile
	./csudoku.out < sudoku_01.txt # sudoku ueber stdio eingaeben
	./csudoku.out f sudoku_02.txt # sudoku ueber den f (file) parameter angeben
	./csudoku.out f sudoku_03.txt
	./csudoku.out xf xsudoku.txt  # xsudoku

clean:
	rm csudoku.out
	rm Dokument.pdf
	rm csudoku-mhaidn-jklepp.zip

doc:
	rst2pdf -o Dokument.pdf README.rst

dist:
	git log --stat > repo.log
	zip csudoku-mhaidn-jklepp Makefile README.rst Dokument.pdf repo.log src/*