#ifndef EXCHANGERATESTORAGE_H
#define	EXCHANGERATESTORAGE_H

#include <map>
#include <utility>
#include "../ast/NumValue.h"

namespace data
{

    class ExchangeRateStorage
    {
    public:
        void setRate(std::string from, std::string to, NumValue rate);
        NumValue getRate(std::string from, std::string to);
    private:
        std::map<std::pair<std::string, std::string>, NumValue> storage;
    };

}
#endif	/* EXCHANGERATESTORAGE_H */

