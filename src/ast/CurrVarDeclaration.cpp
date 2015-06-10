#include "CurrVarDeclaration.h"

using namespace ast;

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, unique_ptr<Expression> asgExpr, data::VariableStorage *storage)
{
    this->currency = currency;
    this->name = name;
    this->assignmentExpr = move(asgExpr);
    this->assignmentVarName = "";
    this->varStorage = storage;
}

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, string asgVarName)
{
    this->currency = currency;
    this->name = name;
    this->assignmentExpr = nullptr;
    this->assignmentVarName = asgVarName;
}

int CurrVarDeclaration::execute() const
{
    Value value = assignmentExpr->calculate(currency);
    if (value.getType() == ValueType::Currency)
        throwOnInvalidValue(name);
    varStorage->addVariable(name, value);
}

void CurrVarDeclaration::throwOnInvalidValue(std::string name) const
{
    throw std::runtime_error("Expected numeric value, but got currency instead - in declaration of: " + name);
}
