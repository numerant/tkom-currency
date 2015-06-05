#ifndef PRINTVAR_H
#define	PRINTVAR_H

#include <string>
#include "Instruction.h"

using namespace std;


namespace ast
{   

class PrintVar : Instruction
{
public:
    PrintVar(string varName);
    int execute() const override;

private:
    string varName;
};

} /* namespace ast */
#endif	/* PRINTVAR_H */

