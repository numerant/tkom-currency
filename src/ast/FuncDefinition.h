#ifndef FUNCDEFINITION_H
#define	FUNCDEFINITION_H

#include <string>
#include <memory>
#include "InputInstruction.h"
#include "InstrSequence.h"


namespace ast
{

    class FuncDefinition : public InputInstruction
    {
    public:
        FuncDefinition(std::string funcName, std::unique_ptr<InstrSequence> sequence);
        int execute() const override;
        std::string toString() const override;
    private:
        std::string funcName;
        std::unique_ptr<InstrSequence> sequence;
    };

}
#endif	/* FUNCDEFINITION_H */

