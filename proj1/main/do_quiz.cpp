/**
 * do_quiz
 *
 * @author Vitcharm
 * @since 2022-03-01
 */
#include <iostream>
#include "quiz_generator.h"
int main() {
    Quiz quiz;
    quiz.initQuiz();
    quiz.runQuizGenerator();
    quiz.runQuizTest();
    double score = quiz.runQuizEvaluation();
    cout << "Your score is " << score << "/100" << endl;
    return 0;
}