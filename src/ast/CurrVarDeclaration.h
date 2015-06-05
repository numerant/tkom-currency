#ifndef CURRVARDECLARATION_H
#define	CURRVARDECLARATION_H

#include "VarDeclaration.h"
#include "RValue.h"

#include <string>


namespace ast
{

class CurrVarDeclaration : VarDeclaration
{
public:
    CurrVarDeclaration(string currency, string name, RValue asgRValue, string asgVarName);
    void execute() const override;
private:
    string currency;
    string name;
    RValue assignmentRValue;
    string assignmentVarName;

};

} /* namespace ast */
#endif	/* CURRVARDECLARATION_H */

