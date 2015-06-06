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

std::unique_ptr<ast::Program> Parser::readProgram()
{
    auto instr = readInputInstr();
    while (checkTokenType(Token::Type::Operator) &&
            (checkTokenValue(";") || checkTokenValue("}")))
        instr = readInstructionLink(std::move(instr));
    return instr;
}

std::unique_ptr<ast::Program> Parser::readInstructionLink(std::unique_ptr<ast::Program> leftOperand)
{
    auto rightOperand = readInputInstr();
    return make_unique<InstructionLink>(std::move(leftOperand),
            std::move(rightOperand));
}

std::unique_ptr<ast::Program> Parser::readInputInstr()
{

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

bool Parser::checkTokenValue(std::string value) const
{
    return scanner->getToken().valueToString() == value;
}

void Parser::advance()
{
    scanner->readNextToken();
}