#ifndef FACTOR_H
#define	FACTOR_H

#include <memory>
#include <string>
#include "Term.h"
#include "Expression.h"
#include "Value.h"

namespace ast
{

    class Factor : public Term
    {
    public:
        Factor(std::unique_ptr<Expression> operand);
        ~Factor();

        Value calculate() const override;
        std::string toString() const override;
    private:
        std::unique_ptr<Expression> operand;
    };

}
#endif	/* FACTOR_H */

