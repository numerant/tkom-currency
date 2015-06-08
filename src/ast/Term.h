#ifndef TERM_H
#define	TERM_H

#include "Expression.h"
#include <memory>

namespace ast
{

    class Term : public Expression
    {
    public:
        virtual ~Term();
    };

}
#endif	/* TERM_H */

