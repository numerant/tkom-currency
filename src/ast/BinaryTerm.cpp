#include "BinaryTerm.h"

using namespace ast;

BinaryTerm::BinaryTerm(std::unique_ptr<Term> leftOperand, Operator oper, std::unique_ptr<Term> rightOperand)
{
    this->leftOperand = std::move(leftOperand);
    this->rightOperand = std::move(rightOperand);
    this->oper = oper;
}

BinaryTerm::~BinaryTerm()
{

}

Value BinaryTerm::calculate() const
{
    const auto leftValue = leftOperand->calculate();
    const auto rightValue = rightOperand->calculate();
    return calculate(leftValue, rightValue);
}

Value BinaryTerm::calculate(std::string targetCurr) const
{
    const auto leftValue = leftOperand->calculate(targetCurr);
    const auto rightValue = rightOperand->calculate(targetCurr);
    return calculate(leftValue, rightValue);
}


Value BinaryTerm::calculate(Value leftValue, Value rightValue) const
{
    switch (oper)
    {
        case Operator::Multiplication:
            return leftValue * rightValue;
        case Operator::Division:
            return leftValue / rightValue;
    }

    throw std::runtime_error("Unknown operator");
}

std::string BinaryTerm::toString() const
{
    using ast::toString;
    return leftOperand->toString() + ' ' + toString(oper) + ' ' + rightOperand->toString();
}
