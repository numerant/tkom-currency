#include "Amount.h"

using namespace ast;

Amount::Amount(int integer)
{
    value = integer;
}

Amount::Amount(int integer, std::string fraction)
{
    value = integer;
    bmp::cpp_dec_float_50 frac = std::stoi(fraction);

    for (int i = 0; i < fraction.length(); i++)
        frac = frac / 10;

    value += frac;
}

bmp::cpp_dec_float_50 Amount::getValue() const
{
    return value;
}

std::string Amount::toString() const
{
    std::stringstream str;
    str << value /* << std::setw(precision) */;
    return str.str();
}
