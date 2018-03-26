CC=gcc
CFLAGS=-g

AR=ar

INSTALL_DIR=~/math330
ARFLAGS=-r
SOURCES=trig/cos330.c trig/sin330.c trig/tan330.c trig/arccos330.c trig/arccos330.c trig/arctan330.c exp/exp330.c exp/log330.c 
OBJECTS=$(SOURCES:.c=.o)

Build: lib cos330.o sin330.o tan330.o arccos330.o arcsin330.o arctan330.o exp330.o log330.o
	$(AR) $(ARFLAGS) libmath330.a cos330.o sin330.o tan330.o arccos330.o arcsin330.o arctan330.o exp330.o log330.o 
	
	cp libmath330.a lib
	mkdir -p bin

	$(CC) $(CFLAGS) -o bin/cli cli/cli.c -I ./include/ -L lib -lmath330 -lm
lib: math330.h

	mkdir -p include
	mkdir -p lib
	cp math330.h include 
	
cos330.o: trig/cos330.c
	$(CC) $(CFLAGS) -c -I include trig/cos330.c
sin330.o: trig/sin330.c
	$(CC) $(CFLAGS) -c -I include trig/sin330.c
tan330.o: trig/tan330.c
	$(CC) $(CFLAGS) -c -I include trig/tan330.c
arccos330.o: trig/arccos330.c
	$(CC) $(CFLAGS) -c -I include trig/arccos330.c
arcsin330.o: trig/arcsin330.c
	$(CC) $(CFLAGS) -c -I include trig/arcsin330.c
arctan330.o: trig/arctan330.c
	$(CC) $(CFLAGS) -c -I include trig/arctan330.c
exp330.o: exp/exp330.c
	$(CC) $(CFLAGS) -c -I include exp/exp330.c
log330.o: exp/log330.c
	$(CC) $(CFLAGS) -c -I include exp/log330.c
