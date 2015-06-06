#ifndef BRACKET_H
#define	BRACKET_H

#include <string>

namespace ast
{

    enum class Bracket
    {
        ParenthLeft,
        ParenthRight,
        CurlyLeft,
        CurlyRight
    };

    std::string toString(Bracket b);

} /* namespace ast */
#endif	/* BRACKET_H */

