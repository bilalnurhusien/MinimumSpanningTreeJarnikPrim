CC=g++
CFLAGS=-I.
OBJ = Graph.o MinimumSpanningTree.o main.o

%.o: %.cpp
	$(CC) -c -std=c++11 -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -std=c++11 -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) main
