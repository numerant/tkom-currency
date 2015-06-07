#ifndef TERM_H
#define	TERM_H

#include "Expression.h"
#include <memory>

namespace ast
{

    class Term : public Expression
    {
    public:
        Term(std::unique_ptr<Term> factor);
        int calculate() const override;
    private:
        std::unique_ptr<Term> factor;
    };

}
#endif	/* TERM_H */

