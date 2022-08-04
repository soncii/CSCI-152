#include "queue.h"
#include "queue.cpp"
#include "timer.h"
#include <iostream>

int main() {
    queue q;
    timer tmr;

    for (int i=0; i<120000000; i++) {
        q.push(i);
    }
    double duration = tmr.secs_since_start();

    std::cout<<"Time taken: "<<duration<<"\n";
    return 0;
}