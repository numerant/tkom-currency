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
    return readProgram();
}

std::unique_ptr<ast::Program> Parser::readProgram()
{
    auto instr = readInputInstr();
    while ( true )
    {
        if (!checkTokenValue(";") && !checkTokenValue("}"))
            throwOnUnexpectedInput(Token::Type::Operator);

        if(checkTokenType(Token::Type::Bracket))
            readBracket();
        else
            readOperator();

        if (!checkTokenType(Token::Type::Eof))
            instr = readInstructionLink(std::move(instr));
        else
            break;
    }

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
    if (checkTokenValue("SET"))
        return readSettingInstr();
//    else if (checkTokenValue("FUNCTION"))
//        return readFuncDefinition();
//    else if (checkTokenValue("NUM"))
//        return readNumVarDeclaration();
//    else if (checkTokenValue("PRINT"))
//        return readPrintInstr();
//    else if (checkTokenValue("$"))
//        return readAssignment();
//    else if (checkTokenValue("IF"))
//        return readIfStatement();
//    else if (checkTokenValue("WHILE"))
//        return readLoopStatement();
//
//    Token first = requireToken(Token::Type::AlphaNum);
//    if (checkTokenValue("="))
//        return readAssignment(first);
//    else if (checkTokenValue("("))
//        return readFuncCall(first);
//    else if (checkTokenType(Token::Type::AlphaNum))
//        return readNamedVarDeclaration(first);
    else
        throwOnUnexpectedInput();

}

std::unique_ptr<ast::SettingInstruction> Parser::readSettingInstr()
{
    requireToken(Token::Type::AlphaNum);
    std::string from = requireToken(Token::Type::AlphaNum);

    // readAmount;
    std::string to = requireToken(Token::Type::AlphaNum);
    return std::make_unique<ast::SettingInstruction>()
}


std::unique_ptr<ast::Operator> Parser::readOperator()
{
    const auto value = requireToken(Token::Type::Operator).getOperator();
    advance();
    return std::make_unique<Operator>(value);
}

std::unique_ptr<ast::Bracket> Parser::readBracket()
{
    const auto value = requireToken(Token::Type::Bracket).getBracket();
    advance();
    return std::make_unique<Bracket>(value);
}

void Parser::throwOnUnexpectedInput()
{
    throw std::runtime_error("Unexpected token: " + scanner->getToken().toString());
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