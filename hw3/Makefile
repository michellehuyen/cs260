CC = g++ -std=c++11 -g
exe_file = hw3

$(exe_file): link.o queue.o driver.o
	$(CC) link.o queue.o driver.o -o $(exe_file)

link.o: link.cpp
	$(CC) -c link.cpp

queue.o: queue.cpp
	$(CC) -c queue.cpp

clean:
	rm -f *.out *.o $(exe_file)