#ifndef CURRVALUE_H
#define	CURRVALUE_H

#include <string>
#include "../data/ExchangeRateStorage.h"
#include "NumValue.h"

namespace ast
{
    /* Represents value with associated currency name. */
    class CurrValue
    {
    public:
        CurrValue();
        CurrValue(NumValue value, std::string currency, data::ExchangeRateStorage *storage);
        CurrValue convertTo(std::string targetCurrency) const;
        std::string getCurrency();
        std::string toString() const;

        CurrValue operator+(CurrValue b);
        CurrValue operator-(CurrValue b);
        CurrValue operator*(NumValue b);
        CurrValue operator/(NumValue b);
    private:
        void throwInvalidOperation();

        data::ExchangeRateStorage *storage;
        std::string currency;
        NumValue value;
    };

}
#endif	/* CURRVALUE_H */

