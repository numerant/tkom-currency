#ifndef NUMVARDECLARATION_H
#define	NUMVARDECLARATION_H

#include <memory>

#include "VarDeclaration.h"
#include "RValue.h"

using namespace std;

namespace ast
{

    class NumVarDeclaration : public VarDeclaration
    {
    public:
        NumVarDeclaration(string name, unique_ptr<RValue> asgRValue);
        NumVarDeclaration(string name, string asgVarName);
        int execute() const override;

    private:
        string name;
        unique_ptr<RValue> assignmentRValue;
        string assignmentVarName;

    };

} /* namespace ast */
#endif	/* NUMVARDECLARATION_H */

