#include "BinaryExpression.h"
#include "Bracket.h"

using namespace ast;

BinaryExpression::BinaryExpression(std::unique_ptr<Expression> leftOperand,
        Operator oper, std::unique_ptr<Expression> rightOperand)
{
    this->leftOperand = std::move(leftOperand);
    this->rightOperand = std::move(rightOperand);
    this->oper = oper;
}

BinaryExpression::~BinaryExpression()
{

}

Value BinaryExpression::calculate() const
{
    const auto leftValue = leftOperand->calculate();
    const auto rightValue = rightOperand->calculate();
    return calculate(leftValue, rightValue);
}

std::string BinaryExpression::toString() const
{
    using ast::toString;
    return leftOperand->toString() + ' ' + toString(oper) + ' ' + rightOperand->toString();
}

Value BinaryExpression::calculate(Value leftValue, Value rightValue) const
{
    switch (oper)
    {
        case Operator::Plus:
            return leftValue + rightValue;
        case Operator::Minus:
            return leftValue - rightValue;
    }

    throw std::runtime_error("Unknown operator");
}

