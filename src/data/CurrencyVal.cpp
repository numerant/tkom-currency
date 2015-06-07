#include "CurrencyVal.h"

#include <cmath>

CurrencyVal::CurrencyVal(int integer, int fraction, int precision)
{
    this->integer = integer;
    this->fraction = fraction;
    this->precision = precision;
}

CurrencyVal CurrencyVal::operator+(const CurrencyVal& value)
{
    int new_integer;
    int new_fraction;
    int new_precision;

    if (precision > value.getPrecision())
    {
        new_precision = precision;
        new_fraction = value.getFraction();

        for (int i = 0; i < precision - value.getPrecision(); i++)
            new_fraction *= 10;

        new_fraction += fraction;
    }
    else
    {
        new_precision = value.getPrecision();
        new_fraction = fraction;

        for (int i = 0; i < value.getPrecision() - precision; i++)
            new_fraction *= 10;

        new_fraction += value.getFraction();
    }
    new_integer = integer + value.getInteger();
    new_integer += new_fraction / std::pow(10, new_precision);
    new_fraction = new_fraction % (int)std::pow(10, new_precision); // this should be made better

    return CurrencyVal(new_integer, new_fraction, new_precision);

}

CurrencyVal CurrencyVal::operator-(const CurrencyVal& value)
{
    int new_integer;
    int new_fraction;
    int new_precision;

    if (precision > value.getPrecision())
    {
        new_precision = precision;
        new_fraction = fraction;
        int tmp_fraction = value.getFraction();

        for (int i = 0; i < precision - value.getPrecision(); i++)
            tmp_fraction *= 10;

        new_fraction -= tmp_fraction;
    }
    else
    {
        new_precision = value.getPrecision();
        new_fraction = fraction;

        for (int i = 0; i < value.getPrecision() - precision; i++)
            new_fraction *= 10;

        new_fraction -= value.getFraction();
    }
    new_integer = integer - value.getInteger();
    if (new_fraction < 0)
        new_integer--;
    new_fraction = new_fraction % (int)std::pow(10, new_precision);
    new_fraction = std::abs(new_fraction);

    return CurrencyVal(new_integer, new_fraction, new_precision);
}

CurrencyVal CurrencyVal::operator*(const int& multiplier)
{
    int new_integer = integer;
    int new_fraction;
    int tmp_value = 1;

    for (int i = 0; i < precision; i++)
            tmp_value *= 10;

    new_integer *= tmp_value;
    new_integer += fraction;

    new_integer *= multiplier;

    new_fraction = new_integer % tmp_value;
    new_integer = new_integer / tmp_value;

    return CurrencyVal(new_integer, new_fraction, precision);
}

CurrencyVal CurrencyVal::operator/(const int& divisor)
{
    int new_integer = integer;
    int new_fraction;
    int tmp_value = 1;

    for (int i = 0; i < precision; i++)
            tmp_value *= 10;

    new_integer *= tmp_value;
    new_integer += fraction;

    new_integer = std::lround(new_integer / divisor);

    new_fraction = new_integer % tmp_value;
    new_integer = new_integer / tmp_value;

    return CurrencyVal(new_integer, new_fraction, precision);
}

int CurrencyVal::getFraction() const
{
    return fraction;
}

int CurrencyVal::getInteger() const
{
    return integer;
}

int CurrencyVal::getPrecision() const
{
    return precision;
}