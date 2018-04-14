#target: dependencies
#	action

all: algo

algo: algo.o helpers.o searching.o sorting.o
	cc algo.o helpers.o searching.o sorting.o -o algo

algo.o: algo.c
	cc -c algo.c

helpers.o: helpers.c helpers.h
	cc -c helpers.c

searching.o: searching.c searching.h
	cc -c searching.c

sorting.o: sorting.c sorting.h
	cc -c sorting.c

clean:
	rm -f *.o *.gch algo
