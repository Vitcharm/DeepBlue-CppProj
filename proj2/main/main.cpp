#include <iostream>
#include <num_calculator.h>
int main(int argc, char *argv[]) {
    std::cout << "Finsh the long number adding project" << std::endl;
    NumCalculator numCalculator;
    numCalculator.dataLoader();
    numCalculator.printSumDecimalResult();
    numCalculator.printSumOctalResult();
    return 0;
}
