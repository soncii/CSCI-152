
#ifndef TIMER_INCLUDED
#define TIMER_INCLUDED  1

#include <chrono>
#include <iostream> 

class timer {

   std::chrono::high_resolution_clock::time_point start_time;

public:

   timer() : start_time(std::chrono::high_resolution_clock::now()) { }

   void restart() {
	   start_time = std::chrono::high_resolution_clock::now();
   }

   double secs_since_start() {
      std::chrono::high_resolution_clock::time_point current_time =
    		  	  	  	  std::chrono::high_resolution_clock::now();

      return std::chrono::duration<double> (current_time - start_time).count();
   }

};

#endif

