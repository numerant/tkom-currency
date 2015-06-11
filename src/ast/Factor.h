#ifndef FACTOR_H
#define	FACTOR_H

#include <memory>
#include <string>
#include <iostream>
#include "../data/VariableStorage.h"
#include "Term.h"
#include "Expression.h"
#include "Value.h"

namespace ast
{
    enum class FactorType
    {
        Expression,
        Value,
        Variable
    };

    /* Class representing factor in Term production. */
    class Factor : public Term
    {
    public:
        /* Each type of Factor requires its own constructor. */
        Factor(std::unique_ptr<Expression> operand);
        Factor(Value value);
        Factor(std::string varName, data::VariableStorage *storage);
        ~Factor();

        Value calculate() const override;
        Value calculate(std::string targetCurr) const override;

        std::string toString() const override;
    private:
        /* Fields */
        FactorType type;
        std::string varName;
        std::unique_ptr<Expression> operand;
        data::VariableStorage *varStorage;
        Value value;
    };

}
#endif	/* FACTOR_H */

