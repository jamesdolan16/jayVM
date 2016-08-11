all: final

final: main.o
	g++ main.o -o final

main.o:
	g++ -c main.cpp -std=c++11

clean:
	rm *o final