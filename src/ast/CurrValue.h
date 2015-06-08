#ifndef CURRVALUE_H
#define	CURRVALUE_H

#include <string>
#include "NumValue.h"

namespace ast
{

    class CurrValue
    {
    public:
        CurrValue convertTo(std::string targetCurrency);
        std::string getCurrency();

        CurrValue operator+(CurrValue b);
        CurrValue operator-(CurrValue b);
        CurrValue operator*(NumValue b);
        CurrValue operator/(NumValue b);
    private:
        void throwInvalidOperation();

        std::string currency;
        NumValue value;
    };

}
#endif	/* CURRVALUE_H */

