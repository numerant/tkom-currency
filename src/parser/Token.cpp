#include "Token.h"

using namespace parser;

Token::Token()
{
    type = Type::Eof;
}

Token::Token(ast::Bracket b)
{
    type = Type::Bracket;
    value.bracket = b;
}

Token::Token(int i)
{
    type = Type::Integer;
    value.integer = i;
}

Token::Token(std::string s)
{
    type = Type::AlphaNum;
    alphanumValue = s;
}

Token::Token(ast::Operator o)
{
    type = Type::Operator;
    value.oper = o;
}

std::string Token::typeToString()
{
    switch (type)
    {
        case Type::AlphaNum:
            return "AlphaNum";
        case Type::Bracket:
            return "Bracket";
        case Type::Eof:
            return "Eof";
        case Type::Integer:
            return "Integer";
        case Type::Operator:
            return "Operator";
    }
}

std::string Token::toString()
{
    return typeToString() + "(\"" + valueToString() + "\")";
}

std::string Token::valueToString()
{
    switch (type)
    {
        case Type::AlphaNum:
            return alphanumValue;
        case Type::Bracket:
            return ast::toString(value.bracket);
        case Type::Integer:
            return "Integer";
        case Type::Operator:
            return ast::toString(value.oper);
        default:
            return std::string();
    }
}
