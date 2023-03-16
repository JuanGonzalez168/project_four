
CC = g++
CFLAGS = -Wall -g
OBJ = obj/main.o obj/tree.o obj/website.o
BIN = bin/run

main: $(OBJ)
	$(CC) $(CFALGS) $(OBJ) -o $(BIN)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

run:
	./$(BIN)

leak:
	valgrind --tool=memcheck --leak-check=full $(BIN)

clr: 
	rm -r bin/* obj/*
