#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include <string>
#include "Value.h"

namespace ast
{

    class Expression
    {
    public:
        virtual ~Expression();
        virtual Value calculate() const = 0;
        virtual Value calculate(std::string targetCurr) const = 0;
        virtual std::string toString() const = 0;
    };

}
#endif	/* EXPRESSION_H */

