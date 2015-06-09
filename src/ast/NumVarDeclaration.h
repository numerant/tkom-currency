#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>

#include "VarDeclaration.h"
#include "Value.h"
namespace ast
{

    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(std::string name, std::unique_ptr<Value> asgRValue);
        NumVarDeclaration(std::string name, std::string asgVarName);
        int execute() const override;

    private:
        std::string name;
        std::unique_ptr<Value> assignmentRValue;
        std::string assignmentVarName;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

