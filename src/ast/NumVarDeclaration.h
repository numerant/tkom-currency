#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>
#include <iostream>
#include "../data/VariableStorage.h"
#include "VarDeclaration.h"
#include "Value.h"
#include "Expression.h"

namespace ast
{
    /* Class representing declaration of numeric variable. */
    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage);
        int execute() const override;
        std::string toString() const override;

    private:
        void throwOnInvalidValue(std::string name) const;

        std::string name;
        std::unique_ptr<Expression> assignmentExpr;
        std::string assignmentVarName;
        data::VariableStorage *varStorage;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

