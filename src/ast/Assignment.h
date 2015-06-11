#ifndef ASSIGNMENT_H
#define	ASSIGNMENT_H

#include <string>
#include <memory>
#include "../data/VariableStorage.h"
#include "Instruction.h"
#include "Expression.h"

namespace ast
{
    /* Represents assignment instruction (like "var1 = var2 * 2"). */
    class Assignment : public Instruction
    {
    public:
        Assignment(std::string varName, std::unique_ptr<Expression> asgExpr, data::VariableStorage *storage);
        int execute() const override;
        virtual std::string toString() const override;
    private:
        std::string varName;
        std::unique_ptr<Expression> assignmentExpr;
        data::VariableStorage *storage;
    };

}
#endif	/* ASSIGNMENT_H */

