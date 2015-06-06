#ifndef TOKEN_H
#define	TOKEN_H

#include <string>
#include "../ast/Bracket.h"
#include "../ast/Operator.h"


namespace parser
{

    class Token
    {
    public:

        enum class Type
        {
            Eof,
            Integer,
            Operator,
            AlphaNum,
            Bracket,
        };

        Token();
        Token(std::string s);
        Token(int i);
        Token(ast::Bracket b);
        Token(ast::Operator o);

        Type getType() const;
        int getInteger() const;
        ast::Bracket getBracket() const;
        ast::Operator getOperator() const;

        std::string typeToString();
        std::string toString();
        std::string valueToString();
    private:


        std::string alphanumValue;
        Type type;

        union
        {
            int integer;
            ast::Bracket bracket;
            ast::Operator oper;
        } value;
    };

}
#endif	/* TOKEN_H */

