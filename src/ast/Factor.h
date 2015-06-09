#ifndef FACTOR_H
#define	FACTOR_H

#include <memory>
#include <string>
#include "Term.h"
#include "Expression.h"
#include "Value.h"

namespace ast
{

    enum class FactorType
    {
        Expression,
        Value,
    };

    class Factor : public Term
    {
    public:
        Factor(std::unique_ptr<Expression> operand);
        Factor(Value value);
        ~Factor();

        Value calculate() const override;
        Value calculate(std::string targetCurr) const override;

        std::string toString() const override;
    private:
        FactorType type;
        std::unique_ptr<Expression> operand;
        Value value;
    };

}
#endif	/* FACTOR_H */

