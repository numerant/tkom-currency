#include "Amount.h"

using namespace ast;

Amount::Amount(int integer)
{
    value = integer;
}

Amount::Amount(int integer, std::string fraction)
{
    value = integer;
    NumValue frac = std::stol(fraction);

    /* Convert string fraction into "0.xxx" numeric value */
    for (int i = 0; i < fraction.length(); i++)
        frac = frac / 10;

    value += frac;
}

NumValue Amount::getValue() const
{
    return value;
}

std::string Amount::toString() const
{
    std::stringstream str;
    str << value;
    return str.str();
}
