#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include <string>
#include "NumValue.h"

namespace ast
{

    class Expression
    {
    public:
        virtual ~Expression();
        virtual NumValue calculate() const = 0;
        virtual std::string toString() const = 0;
    };

}
#endif	/* EXPRESSION_H */

