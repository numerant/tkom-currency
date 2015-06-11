#include "Assignment.h"

using namespace ast;

Assignment::Assignment(std::string varName, std::unique_ptr<Expression> asgExpr, data::VariableStorage* storage)
{
    this->assignmentExpr = std::move(asgExpr);
    this->varName = varName;
    this->storage = storage;
}

int Assignment::execute() const
{
    std::string currency = storage->getValue(varName).getCurrencyName();
    storage->setValue(varName, assignmentExpr->calculate(currency));
}

std::string Assignment::toString() const
{
    return varName + " = " + assignmentExpr->toString();
}
