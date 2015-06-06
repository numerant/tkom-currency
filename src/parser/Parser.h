#ifndef PARSER_H
#define	PARSER_H

#include <memory>
#include "Scanner.h"
#include "../ast/Program.h"

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
        std::unique_ptr<ast::Program> readInstructionLink(std::unique_ptr<ast::Program> leftInstr);
        std::unique_ptr<ast::Program> readInputInstr();

        /* Helper methods */
        void throwOnUnexpectedInput(Token::Type expected);
        Token requireToken(Token::Type expected);
        bool checkTokenType(Token::Type expected) const;
        void advance();

        /* Fields */
        std::unique_ptr<Scanner> scanner;
    };

}
#endif	/* PARSER_H */
