#include "InstructionLink.h"

using namespace ast;

InstructionLink::InstructionLink(std::unique_ptr<Program> leftOperand,
        std::unique_ptr<Program> rightOperand)
{
    this->leftOperand = std::move(leftOperand);
    this->rightOperand = std::move(rightOperand);
}

InstructionLink::~InstructionLink()
{

}

int InstructionLink::execute() const
{
    leftOperand->execute();
    rightOperand->execute();
}

std::string InstructionLink::toString() const
{
    return leftOperand->toString() + "\n" + rightOperand->toString();
}
