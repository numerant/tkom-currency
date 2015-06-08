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

NumValue BinaryTerm::calculate() const
{
    const auto leftValue = leftOperand->calculate();
    const auto rightValue = rightOperand->calculate();
    return calculate(leftValue, rightValue);
}

NumValue BinaryTerm::calculate(NumValue leftValue, NumValue rightValue) const
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
