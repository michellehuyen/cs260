CC = g++ -std=c++11 -g
exe_file = hw5

$(exe_file): link.o list.o driver.o
	$(CC) link.o list.o driver.o -o $(exe_file)

link.o: link.cpp
	$(CC) -c link.cpp

list.o: list.cpp
	$(CC) -c list.cpp

clean:
	rm -f *.out *.o $(exe_file)
