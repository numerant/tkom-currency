#ifndef BINARYTERM_H
#define	BINARYTERM_H

#include <string>
#include <memory>
#include "Term.h"
#include "NumValue.h"
#include "Operator.h"

namespace ast
{

    class BinaryTerm : public Term
    {
    public:
        BinaryTerm(std::unique_ptr<Term> leftOperand,
                Operator oper,
                std::unique_ptr<Term> rightOperand);
        ~BinaryTerm();

        NumValue calculate() const override;
        std::string toString() const override;

    private:
        NumValue calculate(NumValue leftValue, NumValue rightValue) const;

        std::unique_ptr<Term> leftOperand;
        std::unique_ptr<Term> rightOperand;
        Operator oper;
    };

}
#endif	/* BINARYTERM_H */

