#ifndef CURRVARDECLARATION_H
#define	CURRVARDECLARATION_H

#include "VarDeclaration.h"
#include "RValue.h"

#include <memory>

using namespace std;

namespace ast
{

class CurrVarDeclaration : VarDeclaration
{
public:
    CurrVarDeclaration(string currency, string name, unique_ptr<RValue> asgRValue);
    CurrVarDeclaration(string currency, string name, string asgVarName);
    int execute() const override;
private:
    string currency;
    string name;
    unique_ptr<RValue> assignmentRValue;
    string assignmentVarName;

};

} /* namespace ast */
#endif	/* CURRVARDECLARATION_H */

