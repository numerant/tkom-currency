#ifndef PRINTINSTRUCTION_H
#define	PRINTINSTRUCTION_H

#include <iostream>
#include <string>
#include "../data/VariableStorage.h"
#include "Instruction.h"

namespace ast
{

    class PrintInstruction : public Instruction
    {
    public:
        PrintInstruction(std::string varName, data::VariableStorage *varStorage);

        int execute() const override;
        std::string toString() const override;
    private:
        std::string varName;
        data::VariableStorage *varStorage;

    };

}

#endif	/* PRINTINSTRUCTION_H */

