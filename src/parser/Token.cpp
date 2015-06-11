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

Token::Token(long int i)
{
    type = Type::Integer;
    value.integer = i;
}

Token::Token(std::string s)
{
    alphanumValue = s;
    for(int i = 0; i < s.length(); i++)
    {
        if ( !isdigit(s[i]) )
        {
            type = Type::AlphaNum;
            return;
        }
    }
    value.integer = std::stol(s);
    type = Type::Integer;
}

Token::Token(ast::Operator o)
{
    type = Type::Operator;
    value.oper = o;
}

Token::Type Token::getType() const
{
    return type;
}

long int Token::getInteger() const
{
    return value.integer;
}

ast::Bracket Token::getBracket() const
{
    return value.bracket;
}

ast::Operator Token::getOperator() const
{
    return value.oper;
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

std::string Token::toString(Type type)
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

std::string Token::valueToString()
{
    switch (type)
    {
        case Type::AlphaNum:
            return alphanumValue;
        case Type::Bracket:
            return ast::toString(value.bracket);
        case Type::Integer:
            return alphanumValue;
        case Type::Operator:
            return ast::toString(value.oper);
        default:
            return std::string();
    }
}
