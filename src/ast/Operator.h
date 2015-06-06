#ifndef OPERATOR_H
#define	OPERATOR_H

namespace ast
{

    enum class Operator
    {
        /* Arithmetic operators */
        Plus,
        Minus,
        Multiplication,
        Division,
        /* Assignment */
        Assignment,
        /* Relational operators */
        Equal,
        NotEqual,
        Greater,
        Less,
        GreaterEqual,
        LessEqual,
        /* Other */
        Comma,
        Dot,
    };

}

#endif	/* OPERATOR_H */

