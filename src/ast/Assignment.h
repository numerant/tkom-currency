#ifndef ASSIGNMENT_H
#define	ASSIGNMENT_H

#include <string>
#include <memory>
#include "Instruction.h"
#include "Expression.h"
#include "../data/VariableStorage.h"


namespace ast
{

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

