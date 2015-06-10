#include "Factor.h"

using namespace ast;

Factor::Factor(std::unique_ptr<Expression> operand)
: value(0)
{
    this->operand = std::move(operand);
    this->type = FactorType::Expression;
    this->varStorage = nullptr;
}

Factor::Factor(Value value_)
: value(value_)
{
    this->type = FactorType::Value;
    this->varStorage = nullptr;
}

Factor::Factor(std::string varName, data::VariableStorage *storage)
: value(0)
{
    this->varName = varName;
    this->type = FactorType::Variable;
    this->varStorage = storage;
}

Factor::~Factor()
{

}

Value Factor::calculate() const
{
    if (type == FactorType::Expression)
        return operand->calculate();
    else if (type == FactorType::Variable)
        return varStorage->getValue(varName);
    else return value;
}

Value Factor::calculate(std::string targetCurr) const
{
    if (type == FactorType::Expression)
        return operand->calculate(targetCurr);
    else if (type == FactorType::Variable)
        return varStorage->getValue(varName).convertTo(targetCurr);
    else return value.convertTo(targetCurr);
}

std::string Factor::toString() const
{
    if (type == FactorType::Expression)
        return operand->toString();
    else return value.toString();
}

