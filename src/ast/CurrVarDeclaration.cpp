#include "CurrVarDeclaration.h"

using namespace ast;

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, unique_ptr<RValue> asgRValue)
{
    this->currency = currency;
    this->name = name;
    this->assignmentRValue = move(asgRValue);
    this->assignmentVarName = "";
}

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, string asgVarName)
{
    this->currency = currency;
    this->name = name;
    this->assignmentRValue = nullptr;
    this->assignmentVarName = asgVarName;
}

int CurrVarDeclaration::execute() const
{
}
