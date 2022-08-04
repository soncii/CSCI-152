
# Automatically generated Makefile

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++ -O3 -flto


main : Makefile   main.o csci152_student.o
	$(CPP) $(Flags) -o main main.o csci152_student.o

main.o : Makefile   main.cpp   csci152_student.h
	$(CPP) -c $(Flags) main.cpp -o  main.o

csci152_student.o : Makefile   csci152_student.cpp   csci152_student.h
	$(CPP) -c $(Flags) csci152_student.cpp -o  csci152_student.o
