#include "Factor.h"

using namespace ast;

Factor::Factor(std::unique_ptr<Expression> operand)
: value(0)
{
    this->operand = std::move(operand);
    this->type = FactorType::Expression;
}

Factor::Factor(Value value_)
: value(value_)
{
    this->type = FactorType::Value;
}

Factor::~Factor()
{

}

Value Factor::calculate() const
{
    if (type == FactorType::Expression)
        return operand->calculate();
    else return value;
}

Value Factor::calculate(std::string targetCurr) const
{
    if (type == FactorType::Expression)
        return operand->calculate(targetCurr);
    else return value;
}


std::string Factor::toString() const
{
    if (type == FactorType::Expression)
        return operand->toString();
    else return value.toString();
}

