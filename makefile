proj1: main.o helpers.o
	g++ -o proj1 main.o helpers.o
main.o: main.cpp helpers.h
	g++ -c main.cpp -g
helpers.o: helpers.cpp helpers.h
	g++ -c helpers.cpp -g
clean:
	rm *.o proj1