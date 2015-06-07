#ifndef EXPRESSION_H
#define	EXPRESSION_H

namespace ast
{

    class Expression
    {
    public:
        Expression();
        virtual int calculate() const = 0;
    private:

    };

}
#endif	/* EXPRESSION_H */

