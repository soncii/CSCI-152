#include "stack.h"
#include "stack.cpp"
#include "timer.h"
#include <iostream>

int main() {
    stack st1;
    timer tmr;

    for (int i=0; i<120000000; i++) {
        st1.push(i);
    }
    double duration = tmr.secs_since_start();

    std::cout<<"Time taken: "<<duration<<"\n";
    return 0;
}