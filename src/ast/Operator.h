#ifndef OPERATOR_H
#define	OPERATOR_H

#include <string>

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
        Dollar,
        Semicolon,
    };

    std::string toString(Operator o);
}

#endif	/* OPERATOR_H */

