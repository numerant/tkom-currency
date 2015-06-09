#include "NumVarDeclaration.h"

using namespace ast;

NumVarDeclaration::NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgRValue)
{
    this->name = name;
    this->assignmentExpr = std::move(asgRValue);
    this->assignmentVarName = "";
}

//NumVarDeclaration::NumVarDeclaration(std::string name, std::string asgVarName)
//{
//    this->name = name;
//    this->assignmentExpr = nullptr;
//    this->assignmentVarName = "";
//}

int NumVarDeclaration::execute() const
{
}
