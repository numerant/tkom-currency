#include "Operator.h"

using namespace ast;

std::string ast::toString(Operator o)
{
    switch (o)
    {
        case Operator::Assignment:
            return "=";
        case Operator::Comma:
            return ",";
        case Operator::Division:
            return "/";
        case Operator::Dollar:
            return "$";
        case Operator::Dot:
            return ".";
        case Operator::Equal:
            return "==";
        case Operator::Greater:
            return ">";
        case Operator::GreaterEqual:
            return ">=";
        case Operator::Less:
            return "<";
        case Operator::LessEqual:
            return "<=";
        case Operator::Minus:
            return "-";
        case Operator::Multiplication:
            return "*";
        case Operator::NotEqual:
            return "!=";
        case Operator::Plus:
            return "+";
        case Operator::Semicolon:
            return ";";
    }
}