#include "CurrValue.h"

using namespace ast;

CurrValue::CurrValue(NumValue value, std::string currency, data::ExchangeRateStorage* storage)
{

}


CurrValue CurrValue::convertTo(std::string targetCurrency)
{
    if (CurrValue.currency == targetCurrency)
        return *this;
    try
    {
        CurrValue newValue = *this;
        NumValue rate = storage->getRate(CurrValue.currency, targetCurrency);
        newValue.value *= rate;
        newValue.currency = targetCurrency;
    }
    catch (const std::out_of_range& oor)
    {
        throw std::runtime_error("No exchange rate for specified currencies is defined : "
                + this->currency + ", " + targetCurrency);
    }
}

std::string CurrValue::getCurrency()
{
    return currency;
}

std::string CurrValue::toString()
{
    return value + " " + currency;
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
    throw std::runtime_error("Invalid arithmetic operation here: " + this->getCurrency());
}
