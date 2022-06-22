CC = g++ -std=c++11 -g
exe_file = hw7

$(exe_file): node.o hash.o driver.o
	$(CC) node.o hash.o driver.o -o $(exe_file)

node.o: node.cpp
	$(CC) -c node.cpp

hash.o: hash.cpp
	$(CC) -c hash.cpp

clean:
	rm -f *.out *.o $(exe_file)