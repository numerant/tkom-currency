#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>

#include "VarDeclaration.h"
#include "Value.h"

using namespace std;

namespace ast
{

    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(string name, unique_ptr<Value> asgRValue);
        NumVarDeclaration(string name, string asgVarName);
        int execute() const override;

    private:
        string name;
        unique_ptr<Value> assignmentRValue;
        string assignmentVarName;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

