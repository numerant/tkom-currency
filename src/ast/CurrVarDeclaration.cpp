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

CurrVarDeclaration::CurrVarDeclaration(string currency, string name, string asgVarName, data::VariableStorage *storage)
{
    this->currency = currency;
    this->name = name;
    this->assignmentExpr = nullptr;
    this->assignmentVarName = asgVarName;
    this->varStorage = storage;
}

int CurrVarDeclaration::execute() const
{
    Value value = assignmentExpr->calculate(currency);
    if (value.getType() == ValueType::Numeric)
        throwOnInvalidValue(name);
    varStorage->addVariable(name, value);

    std::cout << name << " = " << value.toString() << std::endl;
}

void CurrVarDeclaration::throwOnInvalidValue(std::string name) const
{
    throw std::runtime_error("Expected currency value, but got numeric instead - in declaration of: " + name);
}
