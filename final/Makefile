CC = g++ -std=c++11 -g
exe_file = final

$(exe_file): node.o graph.o driver.o
	$(CC) node.o graph.o driver.o -o $(exe_file)

node.o: node.cpp
	$(CC) -c node.cpp

graph.o: graph.cpp
	$(CC) -c graph.cpp

clean:
	rm -f *.out *.o $(exe_file)