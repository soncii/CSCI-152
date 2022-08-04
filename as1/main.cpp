#include "csci152_student.h"
#include <iostream>

void print(const csci152_student& student) {
	std::cout << student.get_name() << ": " << student.calculate_course_perc() << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {
	//int n;
	//std:: cin>>n;
	//int a[n];
	csci152_student agood("Agood Stutante",
					{100, 100, 100, 100},
					{20.0, 20.0, 20.0, 2.3, 20.0, 20.0},
					100);

	csci152_student abads("Abads Tudant",
					{50, 0, 10, 25, 3, 12}, //20
					{2.1, 3.2, 7.4, 11.0, 3.6}, //25.2
					35.8); //35.8
    csci152_student aslan("Aslan Gimaletdinov",
					{100,100,56,63,10,98,84,56}, //70.875*0.25=17.71875
					{2.3,10,20,15,3.5,0,20}, //59*0.45=26.55
					75.6); //75.6*0.3=22.68
	print(aslan);
	print(agood);  // should print: Agood Stutante: 100
	print(abads);  // should print: Abads Tudant: 29.0817

	std::cout << "-----" << std::endl;

	csci152_student abads_clone(abads); // same as abads
	std::cout<<"Cloned"<<std::endl;
	print(abads_clone);   // should print: Abads Tudant: 29.0817

	abads_clone.change_name("Abads' evil twin");

	print(abads_clone);   // should print: Abads' evil twin: 29.0817
	print(abads);         // should still print: Abads Tudant: 29.0817

	std::cout << "-----" << std::endl;

	abads = agood; // agood's values should be copied into abads

	agood.change_name("Elwood Stutante");

	print(abads);        // should print: Agood Stutante: 100
	print(agood); 		 // should print: Elwood Stutante: 100
	print(abads_clone);  // should print: Abads' evil twin: 29.0817
	std::cout<<"-------MYCUSTOM------"<<std::endl;
	csci152_student Damir(agood);
	print(Damir);
	Damir.change_name("Damir");
	print(Damir);
	Damir=abads_clone;
	print(Damir);
    return 0;
}



