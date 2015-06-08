#ifndef ASSIGNMENT_H
#define	ASSIGNMENT_H

#include "Instruction.h"
#include "Value.h"

using namespace std;

namespace ast
{

    class Assignment : Instruction
    {
    public:
        //int execute() const override;

    private:
        string varToChange;
        Value rvalue;
        string newVar;
        //FuncCall function;

    };

} /* namespace ast */
#endif	/* ASSIGNMENT_H */

