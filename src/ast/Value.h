#ifndef VALUE_H
#define	VALUE_H

#include <sstream>
#include "NumValue.h"
#include "CurrValue.h"

namespace ast
{

    enum class ValueType
    {
        Numeric,
        Currency,
        Undefined
    };

    class Value
    {
    public:
        Value();
        Value(NumValue numeric);
        Value(CurrValue currency);

        ValueType getType();
        std::string toString() const;
        Value convertTo(std::string currency) const;
        Value& operator=(Value b);
        Value operator+(Value b);
        Value operator-(Value b);
        Value operator*(Value b);
        Value operator/(Value b);
    private:
        void throwInvalidOperation(Value second);

        ValueType type;
        NumValue numeric;
        CurrValue currency;
        //data::ExchangeRateStorage *storage;
    };

}
#endif	/* VALUE_H */

