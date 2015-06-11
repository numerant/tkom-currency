#ifndef BINARYTERM_H
#define	BINARYTERM_H

#include <string>
#include <memory>
#include "Term.h"
#include "Value.h"
#include "Operator.h"

namespace ast
{
    /* Represents term with two operands. */
    class BinaryTerm : public Term
    {
    public:
        BinaryTerm(std::unique_ptr<Term> leftOperand,
                Operator oper,
                std::unique_ptr<Term> rightOperand);
        ~BinaryTerm();

        Value calculate() const override;
        Value calculate(std::string targetCurr) const override;

        std::string toString() const override;

    private:
        Value calculate(Value leftValue, Value rightValue) const;

        std::unique_ptr<Term> leftOperand;
        std::unique_ptr<Term> rightOperand;
        Operator oper;
    };

}
#endif	/* BINARYTERM_H */

