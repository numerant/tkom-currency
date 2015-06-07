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
    else if (checkTokenValue("FUNCTION"))
        return readFuncDefinition();
    else
        return readInstruction();

    throwOnUnexpectedInput();
}

std::unique_ptr<ast::Instruction> Parser::readInstruction()
{
    if (checkTokenValue("NUM"))
        return readNumVarDeclaration();
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
}


std::unique_ptr<ast::SettingInstruction> Parser::readSettingInstr()
{
    advance();
    std::string from = requireToken(Token::Type::AlphaNum).valueToString();
    advance();

    if (!checkTokenValue("="))
        throwOnUnexpectedInput();
    advance();

    Currency rate = readAmount()->getValue();
    // readAmount;
    std::string to = requireToken(Token::Type::AlphaNum).valueToString();
    advance();
    return std::make_unique<ast::SettingInstruction>(from, rate, to, &storage);
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

std::unique_ptr<ast::Amount> Parser::readAmount()
{
    bool negative = false;
    long int integer;
    std::string fraction = "0";
    if (checkTokenValue("("))
    {
        advance();
        if (!checkTokenValue("-"))
            throwOnUnexpectedInput();
        advance();
        negative = true;
    }

    integer = requireToken(Token::Type::Integer).getInteger();
    advance();
    if (checkTokenValue("."))
    {
        advance();
        fraction = requireToken(Token::Type::Integer).valueToString();
        advance();
    }
    if (negative)
    {
        integer *= -1;
        if (!checkTokenValue(")"))
            throwOnUnexpectedInput();
        advance();
    }

    return std::make_unique<ast::Amount>(integer, fraction);
}

std::unique_ptr<ast::FuncDefinition> Parser::readFuncDefinition()
{
    advance();

    std::string funcName = requireToken(Token::Type::AlphaNum).valueToString();
    advance();

    if (!checkTokenValue("{"))
        throwOnUnexpectedInput();
    advance();

    auto sequence = readInstrSequence();

    if (!checkTokenValue("}"))
        throwOnUnexpectedInput();
    advance();

    return std::make_unique<ast::FuncDefinition>(funcName, std::move(sequence));
}

std::unique_ptr<ast::InstrSequence> Parser::readInstrSequence()
{
//    auto instr = readInstruction();
//    while ( true )
//    {
//        if (!checkTokenValue(";") && !checkTokenValue("}"))
//            throwOnUnexpectedInput(Token::Type::Operator);
//
//        if(checkTokenType(Token::Type::Bracket))
//            readBracket();
//        else
//            readOperator();
//
//        if (!checkTokenType(Token::Type::Eof))
//            instr = readInstructionLink(std::move(instr));
//        else
//            break;
//    }
//
//    return instr;
}

std::unique_ptr<ast::NumVarDeclaration> Parser::readNumVarDeclaration()
{
    advance();
    std::string varName = requireToken(Token::Type::AlphaNum).valueToString();
    advance();
    if (!checkTokenValue("="))
        throwOnUnexpectedInput();
    advance();
    //Currency amount = readAmount()->getValue(); EXPRESSION
    advance();

    //return std::make_unique<ast::NumVarDeclaration>(varName, amount);
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