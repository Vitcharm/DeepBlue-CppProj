/**
 * quiz_generator
 *
 * @author Vitcharm
 * @since 2022-03-01
 */
#include <iostream>
#include <limits>
#include <chrono>
#include "quiz_generator.h"

Quiz::Quiz() = default;

void Quiz::initQuiz() {
    cout << "Input num of question in the quiz" << endl;
    validateInput(question_num);
    cout << "Input range(max number) of question in the quiz" << endl;
    validateInput(max_num);
    cout << "Init Quiz!" << " Has " << question_num << "questions" << endl;
    num_pool_A = new int[question_num];
    num_pool_B = new int[question_num];
    answer_pool = new int[question_num];
    usr_pool = new int[question_num];
    usr_time = new double[question_num];
}

void Quiz::runQuizGenerator() {
    srand((unsigned)time(nullptr));
    for (int i = 0; i < question_num; ++i) {
        num_pool_A[i] = rand() % (max_num + 1);
        num_pool_B[i] = rand() % (max_num + 1);
        answer_pool[i] = num_pool_A[i] + num_pool_B[i];
    }
    cout << "Questions Generator Success!" << endl;
}

void Quiz::runQuizTest() {
    cout << "Now Run Quiz Test!" << endl;
    for (int i = 0; i < question_num; ++i) {
        cout << "Question No." << i + 1 << endl;
        cout << num_pool_A[i] << " + " << num_pool_B[i] << " = ?" << endl;
        auto startTime = std::chrono::high_resolution_clock::now();
        validateInput(usr_pool[i]);
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = endTime - startTime;
        usr_time[i] = (double)fp_ms.count();
        cout << "used time: " << usr_time[i] << "ms" << endl;
    }
    cout << "********* Quiz Finished **********" << endl;
}

double Quiz::runQuizEvaluation() {
    int correct_count = 0;
    int wrong_count = 0;
    double average_time = 0.0;
    double min_time = usr_time[0];
    for (int i = 0; i < question_num; ++i) {
        if (usr_pool[i] == answer_pool[i]) {
            correct_count++;
        } else {
            wrong_count++;
            cout << "Question No." << i + 1 << " wrong, you answer is: " << usr_pool[i] << endl;
            cout << "Correct answer is: " << answer_pool[i] << endl;
        }
        average_time = average_time + usr_time[i];
        min_time = min(min_time, usr_time[i]);
    }
    cout << "****************" << endl;
    cout << "Correct: " << correct_count << endl;
    cout << "Wrong: " << wrong_count << endl;
    cout << "Minimum Question Used Time: " << min_time << " ms" << endl;
    cout << "Average Used Time: " << average_time/(double)question_num << " ms" << endl;
    return (100 / (double)question_num) * correct_count;
}

template<typename T>
T &Quiz::validateInput(T &val) {
    while (true) {
        if (cin >> val && (int)val >= 0) {
            break;
        } else {
            cout << "Enter a valid integer value!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return val;
}
