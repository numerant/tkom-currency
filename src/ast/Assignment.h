#ifndef ASSIGNMENT_H
#define	ASSIGNMENT_H

#include "Instruction.h"
#include "RValue.h"

using namespace std;

namespace ast
{

class Assignment : Instruction
{
public:
    
private:
    string varToChange;
    RValue rvalue;
    string newVar;
    //FuncCall function;
    
};

} /* namespace ast */
#endif	/* ASSIGNMENT_H */

