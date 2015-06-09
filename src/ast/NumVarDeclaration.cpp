#include "NumVarDeclaration.h"

using namespace ast;

NumVarDeclaration::NumVarDeclaration(std::string name, std::unique_ptr<Value> asgRValue)
{
    this->name = name;
    this->assignmentRValue = move(asgRValue);
    this->assignmentVarName = "";
}

NumVarDeclaration::NumVarDeclaration(std::string name, std::string asgVarName)
{
    this->name = name;
    this->assignmentRValue = nullptr;
    this->assignmentVarName = "";
}

int NumVarDeclaration::execute() const
{
}
