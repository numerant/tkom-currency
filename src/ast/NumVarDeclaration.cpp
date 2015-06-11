#include "NumVarDeclaration.h"

using namespace ast;

NumVarDeclaration::NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgRValue, data::VariableStorage *storage)
{
    this->name = name;
    this->assignmentExpr = std::move(asgRValue);
    this->assignmentVarName = "";
    this->varStorage = storage;
}

int NumVarDeclaration::execute() const
{
    Value value = assignmentExpr->calculate();
    if (value.getType() == ValueType::Currency)
        throwOnInvalidValue(name);
    varStorage->addVariable(name, value);
}

std::string NumVarDeclaration::toString() const
{
    return "NUM" + name + " = " + assignmentExpr->toString();
}

void NumVarDeclaration::throwOnInvalidValue(std::string name) const
{
    throw std::runtime_error("Expected numeric value, but got currency instead - in declaration of: " + name);
}

