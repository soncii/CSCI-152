
# Automatically generated Makefile

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++ -O3 -flto


main : Makefile   main.o set.o
	$(CPP) $(Flags) -o main main.o set.o

main.o : Makefile   main.cpp   set.h
	$(CPP) -c $(Flags) main.cpp -o  main.o

set.o : Makefile   set.cpp   set.h
	$(CPP) -c $(Flags) set.cpp -o  set.o
