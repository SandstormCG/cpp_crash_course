enum class Operation{
    Add,
    Substract,
    Multiply,
    Divide
};

struct Calculator{
  Calculator(Operation op): operation{op}{}
  int calculate(int a, int b){
        switch(operation){
            case Operation::Add: { return a+b; }
            case Operation::Substract: { return a-b; }
            case Operation::Multiply: { return a*b; }
            case Operation::Divide: { return a/b; }
        }
  }
private:
    Operation operation;
};

void chapter2(){
    Calculator adder = Calculator(Operation::Add);
    std::cout << "The sum of 3 + 4 is " << adder.calculate(3,4) << std::endl;

    Calculator substractor = Calculator(Operation::Substract);
    std::cout << "The substraction of 4 - 3 is " << substractor.calculate(4,3) << std::endl;

    Calculator multiplier = Calculator(Operation::Multiply);
    std::cout << "The multiplication of 4 * 3 is " << multiplier.calculate(4,3) << std::endl;

    //Calculator divisor = Calculator(Operation::Divide);
    std::cout << "The division of 12 / 4 is " << Calculator(Operation::Divide).calculate(12,4) << std::endl;

}
