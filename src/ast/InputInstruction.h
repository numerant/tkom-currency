#ifndef INPUTINSTRUCTION_H
#define	INPUTINSTRUCTION_H

#include <string>

#include "Program.h"

namespace ast
{

    class InputInstruction : public Program
    {
    public:
        virtual ~InputInstruction();

        int execute() const override;
        std::string toString() const override;
    private:

        std::string value;
    };

} /* namespace ast */

#endif	/* INPUTINSTRUCTION_H */

