#ifndef VALUE_H
#define	VALUE_H

#include "Factor.h"
#include "NumValue.h"
#include "CurrValue.h"

namespace ast
{

    enum class ValueType
    {
        Numeric,
        Currency,
    };

    class Value
    {
    public:
        Value(NumValue numeric);
        Value(CurrValue currency, std::string targetCurrency);

        std::string toString();
        Value& operator=(Value b);
        Value operator+(Value b);
        Value operator-(Value b);
        Value operator*(Value b);
        Value operator/(Value b);
    private:
        void throwInvalidOperation();

        ValueType type;
        NumValue numeric;
        CurrValue currency;
    };

}
#endif	/* VALUE_H */

