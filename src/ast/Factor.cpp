#include "Factor.h"

using namespace ast;

Factor::Factor(std::unique_ptr<Expression> operand)
{
    this->operand = std::move(operand);
}

Factor::~Factor()
{

}

Value Factor::calculate() const
{
    return operand->calculate();
}

std::string Factor::toString() const
{
    return operand->toString();
}

