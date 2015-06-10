#ifndef FACTOR_H
#define	FACTOR_H

#include <memory>
#include <string>
#include <iostream>
#include "Term.h"
#include "Expression.h"
#include "Value.h"
#include "../data/VariableStorage.h"

namespace ast
{

    enum class FactorType
    {
        Expression,
        Value,
        Variable
    };

    class Factor : public Term
    {
    public:
        Factor(std::unique_ptr<Expression> operand);
        Factor(Value value);
        Factor(std::string varName, data::VariableStorage *storage);
        ~Factor();

        Value calculate() const override;
        Value calculate(std::string targetCurr) const override;

        std::string toString() const override;
    private:
        FactorType type;
        std::string varName;
        std::unique_ptr<Expression> operand;
        data::VariableStorage *varStorage;
        Value value;
    };

}
#endif	/* FACTOR_H */

