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
        Token();
        Token(std::string s);
        Token(int i);
        Token(ast::Bracket b);
        Token(ast::Operator o);
    private:
        std::string alphanumValue;
        union
        {
            int integer;
            ast::Bracket bracket;
            ast::Operator oper;
        } value;
    };

}
#endif	/* TOKEN_H */

