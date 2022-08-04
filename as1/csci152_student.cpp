#include "csci152_student.h"

csci152_student::csci152_student(
            std::string nm,
			std::initializer_list<unsigned int> assignments,
			std::initializer_list<double> quizzes,
			double final_exam) :
        name(nm),
        final_exam_score(final_exam),
        num_of_assignments(assignments.size()),
        assignment_scores(new unsigned int[num_of_assignments]),
        num_of_quizzes(quizzes.size()),
        quiz_scores (new double [num_of_quizzes])     
{
    int i=0;
    for (auto item:assignments){
        assignment_scores[i]=item;
        i++;
    }
    i=0;
    for (auto item:quizzes){
        quiz_scores[i]=item;
        i++;
    }
}
csci152_student::csci152_student(const csci152_student& other):
name(other.name),
num_of_assignments(other.num_of_assignments),
assignment_scores(new unsigned int[num_of_assignments]),
num_of_quizzes(other.num_of_quizzes),
quiz_scores(new double[num_of_quizzes]),
final_exam_score(other.final_exam_score)
{
    for (size_t i=0; i<num_of_assignments;i++) {
        assignment_scores[i]=other.assignment_scores[i];
    }
      for (size_t i=0; i<num_of_quizzes;i++) {
        quiz_scores[i]=other.quiz_scores[i];
    }
}
csci152_student& csci152_student::operator=(const csci152_student& other) 
{
    name = other.name;
    final_exam_score=other.final_exam_score;
    num_of_assignments=other.num_of_assignments;
    num_of_quizzes=other.num_of_quizzes;
    delete[] assignment_scores;
    delete[] quiz_scores;
    assignment_scores = new unsigned int[num_of_assignments];
    quiz_scores = new double[num_of_quizzes];
    for (int i=0; i<num_of_assignments; i++) {
        assignment_scores[i]=other.assignment_scores[i];
    }
      for (int i=0; i<num_of_quizzes;i++) {
        quiz_scores[i]=other.quiz_scores[i];
    }
    return *this;
}
std::string csci152_student::get_name() const {
    return name;
}
void csci152_student::change_name(std::string new_name) {
    name=new_name;
}
double csci152_student::calculate_assignment_perc() const {
    int min=101;
    double sum=0;
    for(int i=0; i<num_of_assignments; i++) {
        sum+=*(assignment_scores+i);
    }
    double percent = sum/(num_of_assignments);
    return percent;
}
double csci152_student::calculate_quiz_perc() const {
    double min=101;
    double sum=0.0;
    for(int i=0; i<num_of_quizzes; i++) {
        sum+=*(quiz_scores+i);
        if (*(quiz_scores+i)<min) min=*(quiz_scores+i);
    }
    sum-=min;
    return sum/(num_of_quizzes-1)*5;
}
double csci152_student::get_final_exam_perc() const {
    return final_exam_score;
}
double csci152_student::calculate_course_perc() const {
    double assignment = csci152_student::calculate_assignment_perc();
    double quiz = csci152_student::calculate_quiz_perc();
    double final_ex = csci152_student::get_final_exam_perc();
    double course_percent = assignment*0.25+quiz*0.45+final_ex*0.3;
    return course_percent;  
}
csci152_student::~csci152_student() {
    delete[] assignment_scores;
    delete[] quiz_scores;
}