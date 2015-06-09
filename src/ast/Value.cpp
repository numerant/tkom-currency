#include "Value.h"

using namespace ast;

Value::Value(NumValue numeric)
{
    this->numeric = numeric;
    this->type = ValueType::Numeric;
    //this->storage = nullptr;
}

Value::Value(CurrValue currency)
{
    this->currency = currency;
    this->type = ValueType::Currency;
}

Value& Value::operator=(Value assigned)
{
    if (this == &assigned)
        return *this;

    if (this->type != assigned.type)
        throwInvalidOperation();

    if (this->type == ValueType::Numeric)
        this->numeric = assigned.numeric;
    else
        this->currency = assigned.currency.convertTo(this->currency.getCurrency());

    return *this;
}

Value Value::operator+(Value summand)
{
    Value newValue = *this;

    if (newValue.type != summand.type)
        throwInvalidOperation();

    if (newValue.type == ValueType::Numeric)
        newValue.numeric += summand.numeric;
    else
        newValue.currency = newValue.currency.convertTo(this->currency.getCurrency())
        + summand.currency.convertTo(this->currency.getCurrency());

    return newValue;
}

Value Value::operator-(Value subtrahend)
{
    Value newValue = *this;

    if (newValue.type != subtrahend.type)
        throwInvalidOperation();

    if (newValue.type == ValueType::Numeric)
        newValue.numeric -= subtrahend.numeric;
    else
        newValue.currency = newValue.currency.convertTo(this->currency.getCurrency())
        - subtrahend.currency.convertTo(this->currency.getCurrency());

    return newValue;
}

Value Value::operator*(Value multiplier)
{
    Value newValue = *this;

    if (newValue.type == multiplier.type && newValue.type == ValueType::Currency)
        throwInvalidOperation();

    if (newValue.type == ValueType::Numeric)
        newValue.numeric = newValue.numeric * multiplier.numeric;
    else
        newValue.currency = newValue.currency.convertTo(this->currency.getCurrency())
        * multiplier.numeric;

    return newValue;
}

Value Value::operator/(Value divisor)
{
    Value newValue = *this;

    if (newValue.type == divisor.type && newValue.type == ValueType::Currency)
        throwInvalidOperation();

    if (newValue.type == ValueType::Numeric)
        newValue.numeric = newValue.numeric / divisor.numeric;
    else
        newValue.currency = newValue.currency.convertTo(this->currency.getCurrency())
        / divisor.numeric;

    return newValue;
}

std::string Value::toString() const
{
    if (type == ValueType::Currency)
        return currency.toString();
    else
    {
        std::stringstream str;
        str << numeric /* << std::setw(precision) */;
        return str.str();
    }
}

void Value::throwInvalidOperation()
{
    throw std::runtime_error("Invalid arithmetic operation: " + this->toString());
}
