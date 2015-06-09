#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>

#include "VarDeclaration.h"
#include "Value.h"
#include "Expression.h"

namespace ast
{

    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgExpr);
        //NumVarDeclaration(std::string name, std::string asgVarName);
        int execute() const override;

    private:
        std::string name;
        std::unique_ptr<Expression> assignmentExpr;
        std::string assignmentVarName;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

