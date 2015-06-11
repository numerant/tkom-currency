#ifndef CURRVARDECLARATION_H
#define	CURRVARDECLARATION_H

#include <memory>
#include <iostream>
#include <string>
#include "../data/VariableStorage.h"
#include "VarDeclaration.h"
#include "Value.h"
#include "Expression.h"

namespace ast
{

    class CurrVarDeclaration : public VarDeclaration
    {
    public:
        CurrVarDeclaration(std::string currency, std::string name, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage);
        int execute() const override;
    private:
        void throwOnInvalidValue(std::string name) const;

        std::string currency;
        std::string name;
        std::unique_ptr<Expression> assignmentExpr;
        std::string assignmentVarName;
        data::VariableStorage *varStorage;

    };

} /* namespace ast */
#endif	/* CURRVARDECLARATION_H */

