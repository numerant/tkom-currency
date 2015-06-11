#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

#include <memory>
#include <string>
#include "Bracket.h"
#include "Expression.h"
#include "Operator.h"
#include "Value.h"

namespace ast
{
    /* Represents expression with two operands. */
    class BinaryExpression : public Expression
    {
    public:
        BinaryExpression(std::unique_ptr<Expression> leftOperand,
                Operator oper,
                std::unique_ptr<Expression> rightOperand);
        ~BinaryExpression();

        Value calculate() const override;
        Value calculate(std::string targetCurr) const override;
        std::string toString() const override;

    private:
        Value calculate(Value leftValue, Value rightValue) const;

        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;
        Operator oper;
        std::string currency;
    };

}

#endif	/* BINARYEXPRESSION_H */

