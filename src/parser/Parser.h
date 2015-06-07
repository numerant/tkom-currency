#ifndef PARSER_H
#define	PARSER_H

#include <memory>
#include "Scanner.h"
#include "../ast/Program.h"
#include "../ast/InstructionLink.h"
#include "../ast/InputInstruction.h"
#include "../ast/SettingInstruction.h"

namespace parser
{

    class Parser
    {
    public:
        Parser(std::unique_ptr<Scanner> scanner);
        ~Parser();
        std::unique_ptr<ast::Program> parse();
    private:
        /* Parsing methods */
        std::unique_ptr<ast::Program> readProgram();
        std::unique_ptr<ast::Program> readInstructionLink(std::unique_ptr<ast::Program> leftOperand);
        std::unique_ptr<ast::Program> readInputInstr();
        std::unique_ptr<ast::SettingInstruction> readSettingInstr();
        std::unique_ptr<ast::Operator> readOperator();
        std::unique_ptr<ast::Bracket> readBracket();

        /* Helper methods */
        void throwOnUnexpectedInput();
        void throwOnUnexpectedInput(Token::Type expected);
        Token requireToken(Token::Type expected);
        bool checkTokenType(Token::Type expected) const;
        bool checkTokenValue(std::string value) const;
        void advance();

        /* Fields */
        std::unique_ptr<Scanner> scanner;
    };

}
#endif	/* PARSER_H */

