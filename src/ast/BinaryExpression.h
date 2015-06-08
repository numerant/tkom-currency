#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

#include <memory>
#include <string>

#include "Expression.h"
#include "Operator.h"
#include "NumValue.h"


namespace ast
{

    class BinaryExpression : public Expression
    {
    public:
        BinaryExpression(std::unique_ptr<Expression> leftOperand,
                Operator oper,
                std::unique_ptr<Expression> rightOperand);
        ~BinaryExpression();

        NumValue calculate() const override;
        std::string toString() const override;

    private:
        NumValue calculate(NumValue leftValue, NumValue rightValue) const;

        std::unique_ptr<Expression> leftOperand;
        std::unique_ptr<Expression> rightOperand;
        Operator oper;
        std::string currency;
    };

}

#endif	/* BINARYEXPRESSION_H */

