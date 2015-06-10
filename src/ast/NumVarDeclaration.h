#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>
#include <iostream>

#include "VarDeclaration.h"
#include "Value.h"
#include "Expression.h"
#include "../data/VariableStorage.h"

namespace ast
{

    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage);
        //NumVarDeclaration(std::string name, std::string asgVarName);
        int execute() const override;

    private:
        void throwOnInvalidValue(std::string name) const;

        std::string name;
        std::unique_ptr<Expression> assignmentExpr;
        std::string assignmentVarName;
        data::VariableStorage *varStorage;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

