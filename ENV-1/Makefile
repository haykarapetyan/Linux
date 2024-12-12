all: program

program: main.o complex.o sort.o
	g++ $^ -o $@

main.o: main.cpp complex.h sort.h
	g++ -c $< -o $@

complex.o: complex.cpp complex.h
	g++ -c $< -o $@

sort.o: sort.cpp sort.h complex.h
	g++ -c $< -o $@

clean:
	rm -rf *.o program
