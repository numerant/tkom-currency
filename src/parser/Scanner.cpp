#include "Scanner.h"

using namespace parser;
using namespace ast;
using namespace std;

Scanner::Scanner(std::istream& in_) :
in(in_)
{
}

Token Scanner::getToken() const
{
    return token;
}

void Scanner::readNextToken()
{

}

bool Scanner::tryAlphaNum()
{

}

void Scanner::ignoreWhitespaces()
{
    while (in && isspace(in.peek()))
        in.get();
}

bool Scanner::tryBracket()
{
    switch (in.peek())
    {
        case '{':
            token = Bracket::CurlyLeft;
            break;
        case '}':
            token = Bracket::CurlyRight;
            break;
        case '(':
            token = Bracket::ParenthLeft;
            break;
        case ')':
            token = Bracket::ParenthRight;
            break;
        default:
            return false;
    }
    in.get();
    return true;
}

bool Scanner::tryOperator()
{
    switch (in.peek())
    {
        case '+':
            token = Operator::Plus;
            break;
        case '-':
            token = Operator::Minus;
            break;
        case '*':
            token = Operator::Multiplication;
            break;
        case '/':
            token = Operator::Division;
            break;
        default:
            return false;
    }
    in.get();
    return true;
}

bool Scanner::trySpecial()
{

}

bool Scanner::tryEof()
{
    if (!in.eof())
        return false;
    token = Token();
    return true;
}


