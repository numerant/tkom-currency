#include "CurrValue.h"

using namespace ast;

CurrValue CurrValue::convertTo(std::string targetCurrency)
{

}

std::string CurrValue::getCurrency()
{

}

CurrValue CurrValue::operator+(CurrValue summand)
{
    if (this->currency != summand.currency)
        throwInvalidOperation();

    CurrValue newValue = *this;
    newValue.value += summand.value;

    return newValue;
}

CurrValue CurrValue::operator-(CurrValue subtrahend)
{
    if (this->currency != subtrahend.currency)
        throwInvalidOperation();

    CurrValue newValue = *this;
    newValue.value -= subtrahend.value;

    return newValue;
}

CurrValue CurrValue::operator*(NumValue multiplier)
{
    CurrValue newValue = *this;
    newValue.value *= multiplier;

    return newValue;
}

CurrValue CurrValue::operator/(NumValue divisor)
{
    CurrValue newValue = *this;
    newValue.value /= divisor;

    return newValue;
}

void CurrValue::throwInvalidOperation()
{
    throw std::runtime_error("Invalid arithmetic operation here: " +this->getCurrency());
}
