#ifndef TERM_H
#define	TERM_H

#include "Expression.h"
#include <memory>

namespace ast
{
    /* Class representing term, which is only instantiated
     * either as Factor or as BinaryExpression. */
    class Term : public Expression
    {
    public:
        virtual ~Term();
    };

}
#endif	/* TERM_H */

