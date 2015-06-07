#include "InputInstruction.h"

#include <iostream>

using namespace ast;

InputInstruction::~InputInstruction()
{

}

int InputInstruction::execute() const
{
    std::cout << value << std::endl;
}

std::string InputInstruction::toString() const
{
    return value;
}


