#ifndef VARDECLARATION_H
#define	VARDECLARATION_H

#include "Instruction.h"

namespace ast
{

    class VarDeclaration : public Instruction
    {
    public:
        virtual ~VarDeclaration();
    private:

    };

} /* namespace ast */
#endif	/* VARDECLARATION_H */

