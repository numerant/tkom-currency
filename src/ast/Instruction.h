#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

#include "InputInstruction.h"


namespace ast
{

    class Instruction : InputInstruction
    {
    public:
        virtual ~Instruction();
        virtual int execute() const = 0;
    private:

    };

} /* namespace ast */
#endif	/* INSTRUCTION_H */

