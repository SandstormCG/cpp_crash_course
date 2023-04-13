#include <iostream>
#include "chapter_1/absolute_value.cpp"
#include "chapter_1/sum.cpp"
#include "chapter_2/operation.cpp"



int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;

    // Chapter 1 - absolute_value
    int my_num=-10;
    std::cout << "The absolute value of " << my_num << " is " << absolute_value(my_num) << std::endl;
    // Chapter 1 - sum
    std::cout << "The sum of 3 + 4 is " << sum(3,4) << std::endl;
    // Chapter 2 - operation
    chapter2();

    return 0;
}


