#ifndef VARDECLARATION_H
#define	VARDECLARATION_H

#include "Instruction.h"

namespace ast
{

class VarDeclaration : Instruction
{
public:
    virtual ~VarDeclaration();
    virtual void execute() const = 0;
private:

};

} /* namespace ast */
#endif	/* VARDECLARATION_H */

