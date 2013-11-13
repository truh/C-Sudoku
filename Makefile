CC      :=gcc

WARNINGS:= -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes

CFLAGS  := -g -std=c99 $(WARNINGS)

SRC     := src/*

EXECUTABLE:= ./csudoku

DISTRIBUTE:= Makefile README.rst Dokument.pdf src

all: dist

build:
    $(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRC)

clean:
    rm $(EXECUTABLE)
    rm Dokument.pdf

rebuild: clean build

doc:
    rst2pdf -o Dokument.pdf README.pdf

dist: doc

