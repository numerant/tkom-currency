#ifndef INPUTINSTRUCTION_H
#define	INPUTINSTRUCTION_H

#include <string>

#include "Program.h"

namespace ast
{
    /* Generic class representing InputInstruction production. */
    class InputInstruction : public Program
    {
    public:
        virtual ~InputInstruction();

    };

} /* namespace ast */

#endif	/* INPUTINSTRUCTION_H */

