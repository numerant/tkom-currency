#include "Scanner.h"

using namespace parser;
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
    while ( in && isspace( in.peek() ) )
        in.get();
}

bool Scanner::tryBrace()
{

}

bool Scanner::tryOperator()
{

}

bool Scanner::trySpecial()
{

}

