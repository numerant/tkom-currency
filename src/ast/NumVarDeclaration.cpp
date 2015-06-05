#include "NumVarDeclaration.h"

using namespace ast;

NumVarDeclaration::NumVarDeclaration(string name, unique_ptr<RValue> *asgRValue)
{
    this->name = name;
    this->assignmentRValue = move(asgRValue);
    this->assignmentVarName = "";
}

NumVarDeclaration::NumVarDeclaration(string name, string asgVarName)
{
    this->name = name;
    this->assignmentRValue = nullptr;
    this->assignmentVarName = "";
}