CC=g++
DIR=$(shell pwd)

IDIR=./include
ODIR=./src

CFLAGS=-I$(IDIR)
_SRC=main.cpp octree.cpp vector.cpp
SRC=$(patsubst %,$(ODIR)/%,$(_SRC))

octree: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	st -e $(DIR)/octree
