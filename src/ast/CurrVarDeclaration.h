#ifndef CURRVARDECLARATION_H
#define	CURRVARDECLARATION_H

#include "VarDeclaration.h"
#include "Value.h"
#include "Expression.h"
#include "../data/VariableStorage.h"

#include <memory>
#include <iostream>

using namespace std;

namespace ast
{

    class CurrVarDeclaration : public VarDeclaration
    {
    public:
        CurrVarDeclaration(string currency, string name, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage);
        CurrVarDeclaration(string currency, string name, string asgVarName, data::VariableStorage *storage);
        int execute() const override;
    private:
        void throwOnInvalidValue(std::string name) const;

        string currency;
        string name;
        unique_ptr<Expression> assignmentExpr;
        string assignmentVarName;
        data::VariableStorage *varStorage;

    };

} /* namespace ast */
#endif	/* CURRVARDECLARATION_H */

