/**
 * num_calculator
 *
 * @author Vitcharm
 * @since 2022-03-01
 */
#ifndef PROJ2_NUM_CALCULATOR_H
#define PROJ2_NUM_CALCULATOR_H

#include <iostream>
#include <deque>
using namespace std;
class NumCalculator {
public:
    NumCalculator();

    void dataLoader();

    void printSumDecimalResult();

    void printSumOctalResult();

private:
    string input_file_path;
    std::deque<int> num_array_1;
    std::deque<int> num_array_2;
    std::deque<int> num_sum_result;
};

#endif //PROJ2_NUM_CALCULATOR_H
