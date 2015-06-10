#include "VariableStorage.h"

using namespace data;

void VariableStorage::addVariable(std::string name, ast::Value value)
{
    auto retValue = storage.insert(std::make_pair(name, value));
    if (retValue.second == false)     // is true if element was actually inserted
        throwOnRedeclaration(name);
}

void VariableStorage::setValue(std::string name, ast::Value value)
{
    if (storage.find(name) != storage.end())
        storage[name] = value;
    else throwOnUndeclaredVar(name);
}

ast::Value VariableStorage::getValue(std::string name)
{
    if (storage.find(name) != storage.end())
        return storage[name];
    else throwOnUndeclaredVar(name);
}

void VariableStorage::throwOnUndeclaredVar(std::string name)
{
    throw std::runtime_error("Variable not declared: " + name);
}

void VariableStorage::throwOnRedeclaration(std::string name)
{
    throw std::runtime_error("Attempted redeclaration of variable: " + name);
}
