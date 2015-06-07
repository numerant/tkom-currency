#ifndef EXCHANGERATESTORAGE_H
#define	EXCHANGERATESTORAGE_H

#include <map>
#include <utility>
#include "../ast/Currency.h"

namespace bmp = boost::multiprecision;

namespace data
{

    class ExchangeRateStorage
    {
    public:
        void setRate(std::string from, std::string to, Currency rate);
        Currency getRate(std::string from, std::string to);
    private:
        std::map<std::pair<std::string, std::string>, Currency> storage;
    };

}
#endif	/* EXCHANGERATESTORAGE_H */

