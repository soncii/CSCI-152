/*
 * csci152_student.h
 *
 * Header file for Assignment 1
 */

#ifndef CSCI152_STUDENT_H_
#define CSCI152_STUDENT_H_

#include <ostream>


class csci152_student {

	std::string name; // name of student

	// Note that we use non-negative integer scores for assignments, 
	// but that we use floating-point numbers for quizzes and the final
	// exam
	
	size_t num_of_assignments;		 // number of assignment_scores; this should be positive
	unsigned int *assignment_scores; // variable-length array; each item is out of 100 points

	size_t num_of_quizzes;		 // number of quiz_scores; this should always be 2 or more
	double *quiz_scores;	     // variable-length array; each item is out of 20.0 pts

	double final_exam_score;   // out of 100.0 points

public:

	/*
	 * Standard argument constructor -- you must allocate new 
	 * arrays for assignment_scores and quiz_scores, and copy 
	 * over the values from the initializer lists.
	 *
	 * Do not worry about illegal inputs for this assignment
	 */
	csci152_student(
			std::string nm,
			std::initializer_list<unsigned int> assignments,
			std::initializer_list<double> quizzes,
			double final_exam
	);

	/*
	 * Copy constructor
	 */
	csci152_student(const csci152_student& other);

	/*
	 * Copy assignment - be careful to properly dispose of allocated memory for this
	 * before overwriting with values from other
	 */
	csci152_student& operator=(const csci152_student& other);

	/*
	 * Name getter
	 */
	std::string get_name() const;

	/*
	 * Name setter
	 */
	void change_name(std::string new_name);

	/*
	 * Calculates the total assignment percentage between 0.0 and 100.0.
	 * Although individual assignment scores have integer values, the 
	 * final percentage should be a floating-point number
	 */
	double calculate_assignment_perc() const;

	/*
	 * Calculates the total quiz percentage between 0.0 and 100.0, dropping
	 * the lowest quiz score.
	 * Note that individual quiz scores are between 0 and 20.0
	 */
	double calculate_quiz_perc() const;


	/*
	 * Returns the value stored in final_exam_score
	 */
	double get_final_exam_perc() const;

	/*
	 * Calculates the total course grade as a percent, using the weighting from
	 * the syllabus
	 */
	double calculate_course_perc() const;

	/*
	 * Destructor - don't forget you need to delete anything you explicitly allocated
	 */
	~csci152_student();

};


#endif /* CSCI152_STUDENT_H_ */
