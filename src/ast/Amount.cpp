#include "Amount.h"

using namespace ast;

Amount::Amount(int integer)
{
    value = integer;
}

Amount::Amount(int integer, std::string fraction)
{
    value = integer;
    Currency frac = std::stol(fraction);

    for (int i = 0; i < fraction.length(); i++)
        frac = frac / 10;

    value += frac;
}

Currency Amount::getValue() const
{
    return value;
}

std::string Amount::toString() const
{
    std::stringstream str;
    str << value /* << std::setw(precision) */;
    return str.str();
}
