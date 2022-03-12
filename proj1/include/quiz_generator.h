/**
 * quiz_generator
 *
 * @author Vitcharm
 * @since 2022-03-01
 */

#ifndef PROJ1_QUIZ_GENERATOR_H
#define PROJ1_QUIZ_GENERATOR_H

#include <cstdlib>

using namespace std;
class Quiz{
public:
    Quiz();

    void initQuiz();

    void runQuizGenerator();

    void runQuizTest();

    double runQuizEvaluation();

    template<typename T>
    T &validateInput(T &val);

private:
    int question_num;
    int max_num;
    double* usr_time{};
    int* num_pool_A{};
    int* num_pool_B{};
    int* answer_pool{};
    int* usr_pool{};
};
#endif //PROJ1_QUIZ_GENERATOR_H
