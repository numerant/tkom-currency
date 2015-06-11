#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

#include "InputInstruction.h"

namespace ast
{
    /* Class representing instruction that might occur both globally and in function definition. */
    class Instruction : public InputInstruction
    {
    public:
        virtual ~Instruction();
        virtual int execute() const = 0;
    private:

    };

} /* namespace ast */
#endif	/* INSTRUCTION_H */

