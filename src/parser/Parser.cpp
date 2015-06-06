#include "Parser.h"

using namespace parser;
using namespace ast;

Parser::Parser(std::unique_ptr<Scanner> scanner_)
: scanner(std::move(scanner_))
{
}

Parser::~Parser()
{
}

std::unique_ptr<Program> Parser::parse()
{
    advance();
    //return readExpression();
}

void Parser::throwOnUnexpectedInput(Token::Type expected)
{
    throw std::runtime_error("Unexpected token: " + scanner->getToken().toString());
            //+ ", expected one was: " + Token::toString(expected));
}

Token Parser::requireToken(Token::Type expected)
{
    const auto token = scanner->getToken();
    const auto type = token.getType();
    if (type != expected)
        throwOnUnexpectedInput(expected);
    return token;
}

bool Parser::checkTokenType(Token::Type expected) const
{
    return scanner->getToken().getType() == expected;
}

void Parser::advance()
{
    scanner->readNextToken();
}