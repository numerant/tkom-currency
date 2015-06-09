#ifndef CURRVALUE_H
#define	CURRVALUE_H

#include <string>
#include "NumValue.h"
#include "../data/ExchangeRateStorage.h"

namespace ast
{

    class CurrValue
    {
    public:
        CurrValue();
        CurrValue(NumValue value, std::string currency, data::ExchangeRateStorage *storage);
        CurrValue convertTo(std::string targetCurrency);
        std::string getCurrency();
        std::string toString();

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

