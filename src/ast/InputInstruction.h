#ifndef INPUTINSTRUCTION_H
#define	INPUTINSTRUCTION_H

#include <string>

#include "Program.h"

namespace ast
{

    class InputInstruction : public Program
    {
    public:
        InputInstruction(std::string value);

        int execute() const override;
        std::string toString() const override;
    private:

        std::string value;
    };

} /* namespace ast */

#endif	/* INPUTINSTRUCTION_H */

