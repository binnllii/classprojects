SRC=image.C main.C
OBJ=$(SRC:.C.o)

proj: $(OBJ)
	g++ $(OBJ) -o proj3G
.C.o: $<
	g++ -g -I. -c $<
clean:
	rm -f prog *.o
