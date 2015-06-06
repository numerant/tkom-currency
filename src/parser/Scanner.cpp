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
    ignoreWhitespaces();
    if (tryEof())
        return;
    throwStreamError();
    if (tryBracket() || tryTwoCharOperator() || tryOperator())
        return;
    if (tryAlphaNum())
        return;
    throwUnknownToken();
}

bool Scanner::tryAlphaNum()
{
    std::string buffer;
    while (in && std::isalnum(in.peek()))
        buffer += static_cast<char> (in.get());
    if (buffer.empty())
        return false;
    token = Token(buffer);
    return true;
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
        case '=':
            token = Operator::Assignment;
            break;
        case '.':
            token = Operator::Dot;
            break;
        case ',':
            token = Operator::Comma;
            break;
        case ';':
            token = Operator::Semicolon;
            break;
        case '$':
            token = Operator::Dollar;
            break;
        case '>':
            token = Operator::Greater;
            break;
        case '<':
            token = Operator::Less;
            break;
        default:
            return false;
    }
    in.get();
    return true;
}

bool Scanner::tryTwoCharOperator()
{
    char first = in.get();
    char second = in.peek();

    if (first == '=' && second == '=')
        token = Operator::Equal;
    else if (first == '!' && second == '=')
        token = Operator::NotEqual;
    else if (first == '>' && second == '=')
        token = Operator::GreaterEqual;
    else if (first == '<' && second == '=')
        token = Operator::LessEqual;
    else
    {
        in.unget();
        return false;
    }

    in.get();
    return true;
}

bool Scanner::tryEof()
{
    if (!in.eof())
        return false;
    token = Token();
    return true;
}

void Scanner::throwStreamError()
{
    if (!in)
        throw std::runtime_error("Input error");
}

void Scanner::throwUnknownToken()
{
    const std::string msg = "Token not recognized, starting with: ";
    throw std::runtime_error(msg + static_cast<char> (in.get()));
}


