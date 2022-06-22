CC = g++ -std=c++11 -g
exe_file = hw6

$(exe_file): node.o bst.o driver.o
	$(CC) node.o bst.o driver.o -o $(exe_file)

node.o: node.cpp
	$(CC) -c node.cpp

bst.o: bst.cpp
	$(CC) -c bst.cpp

clean:
	rm -f *.out *.o $(exe_file)
