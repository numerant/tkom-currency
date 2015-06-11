#include "CurrVarDeclaration.h"

using namespace ast;


CurrVarDeclaration::CurrVarDeclaration(std::string currency, std::string name, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage)
{
    this->currency = currency;
    this->name = name;
    this->assignmentExpr = std::move(asgExpr);
    this->assignmentVarName = "";
    this->varStorage = storage;
}

int CurrVarDeclaration::execute() const
{
    Value value = assignmentExpr->calculate(currency);
    if (value.getType() == ValueType::Numeric)
        throwOnInvalidValue(name);
    varStorage->addVariable(name, value);
}

void CurrVarDeclaration::throwOnInvalidValue(std::string name) const
{
    throw std::runtime_error("Expected currency value, but got numeric instead - in declaration of: " + name);
}
