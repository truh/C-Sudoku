CC=gcc

all: compile test

compile:
	cd src;\
	$(CC) -lm -o ../csudoku.out main.c

test: compile
	./csudoku.out

clean:
	rm csudoku.out
	rm Dokument.pdf
	rm csudoku-mhaidn-jklepp.zip

doc:
	rst2pdf -o Dokument.pdf README.rst

dist:
	zip csudoku-mhaidn-jklepp Makefile README.rst Dokument.pdf src/*