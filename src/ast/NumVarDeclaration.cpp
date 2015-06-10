#include "NumVarDeclaration.h"

using namespace ast;

NumVarDeclaration::NumVarDeclaration(std::string name, std::unique_ptr<Expression> asgRValue, data::VariableStorage *storage)
{
    this->name = name;
    this->assignmentExpr = std::move(asgRValue);
    this->assignmentVarName = "";
    this->varStorage = storage;
}

//NumVarDeclaration::NumVarDeclaration(std::string name, std::string asgVarName)
//{
//    this->name = name;
//    this->assignmentExpr = nullptr;
//    this->assignmentVarName = "";
//}

int NumVarDeclaration::execute() const
{
    Value value = assignmentExpr->calculate();
    if (value.getType() == ValueType::Currency)
        throwOnInvalidValue(name);
    varStorage->addVariable(name, value);

    std::cout << name << " = " << value.toString() << std::endl;
}

void NumVarDeclaration::throwOnInvalidValue(std::string name) const
{
    throw std::runtime_error("Expected numeric value, but got currency instead - in declaration of: " + name);
}

