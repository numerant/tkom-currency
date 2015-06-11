#include "PrintInstruction.h"

using namespace ast;

PrintInstruction::PrintInstruction(std::string varName, data::VariableStorage* varStorage)
{
    this->varName = varName;
    this->varStorage = varStorage;
}

int PrintInstruction::execute() const
{
    std::cout << varName << " = " << varStorage->getValue(varName).toString() << std::endl;
}

std::string PrintInstruction::toString() const
{

}
