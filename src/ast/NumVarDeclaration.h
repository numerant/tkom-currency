#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <string>

#include "VarDeclaration.h"
#include "RValue.h"


namespace ast
{

class NumVarDeclaration : VarDeclaration
{
public:
    NumVarDeclaration(string name, RValue asgRValue, string asgVarName);
    void execute() const override;
private:
    string name;
    RValue assignmentRValue;
    string assignmentVarName;

};

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

