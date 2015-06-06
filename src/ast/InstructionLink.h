#ifndef INSTRUCTIONLINK_H
#define	INSTRUCTIONLINK_H

#include <memory>
#include "Program.h"

namespace ast
{

    class InstructionLink : public Program
    {
    public:
        InstructionLink(std::unique_ptr<Program> leftOperand,
                std::unique_ptr<Program> rightOperand);
        ~InstructionLink();

        int execute() const override;
        std::string toString() const override;

    private:

        /* Fields */
        std::unique_ptr<Program> leftOperand;
        std::unique_ptr<Program> rightOperand;
    };

}
#endif	/* INSTRUCTIONLINK_H */

