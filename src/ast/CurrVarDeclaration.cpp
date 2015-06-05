#include "NumVarDeclaration.h"

using namespace ast;

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, RValue asgRValue, string asgVarName)
{
    this->currency = currency;
    this->name = name;
    this->assignmentRValue = asgRValue;
    this->assignmentVarName = asgVarName;
}