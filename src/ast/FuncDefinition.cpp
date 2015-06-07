#include "FuncDefinition.h"

using namespace ast;

FuncDefinition::FuncDefinition(std::string funcName, std::unique_ptr<InstrSequence> sequence)
{
    this->funcName = funcName;
    this->sequence = std::move(sequence);
}

int FuncDefinition::execute() const
{
    // put sequence into the map
}

std::string FuncDefinition::toString() const
{
    return "FUNCTION" + funcName + "{ " + sequence->toString() + "}";
}
