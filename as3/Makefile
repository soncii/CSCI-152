
# Automatically generated Makefile

Flags = -Wreturn-type -Wundef -std=c++11
CPP = g++ -O3 -flto


main : Makefile   main.o queue.o
	$(CPP) $(Flags) -o main main.o queue.o

main.o : Makefile   main.cpp   queue.h
	$(CPP) -c $(Flags) main.cpp -o  main.o

queue.o : Makefile   queue.cpp   queue.h
	$(CPP) -c $(Flags) queue.cpp -o  queue.o
