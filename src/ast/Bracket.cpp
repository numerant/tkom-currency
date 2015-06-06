#include "Bracket.h"

using namespace ast;

std::string ast::toString(Bracket b)
{
    switch (b)
    {
        case Bracket::CurlyLeft:
            return "{";
        case Bracket::CurlyRight:
            return "}";
        case Bracket::ParenthLeft:
            return "(";
        case Bracket::ParenthRight:
            return ")";
    }
}
