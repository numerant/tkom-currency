#ifndef VARIABLESTORAGE_H
#define	VARIABLESTORAGE_H

#include <unordered_map>
#include <utility>
#include "../ast/Value.h"
namespace data
{

    class VariableStorage
    {
    public:
        void addVariable(std::string name, ast::Value value);
        void setValue(std::string name, ast::Value value);
        ast::Value getValue(std::string name);
    private:
        void throwOnUndeclaredVar(std::string name);
        void throwOnRedeclaration(std::string name);

        std::unordered_map<std::string, ast::Value> storage;
    };

}

#endif	/* VARIABLESTORAGE_H */

