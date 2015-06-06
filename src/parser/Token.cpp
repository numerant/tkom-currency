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
