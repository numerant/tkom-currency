#ifndef EXCHANGERATESTORAGE_H
#define	EXCHANGERATESTORAGE_H

#include <map>
#include <utility>
#include "CurrencyVal.h"

namespace data
{

    class ExchangeRateStorage
    {
    public:
        void setRate(std::string from, std::string to, CurrencyVal rate);
        CurrencyVal getRate(std::string from, std::string to);
    private:
        std::map<std::pair<std::string, std::string>, CurrencyVal> storage;
    };

}
#endif	/* EXCHANGERATESTORAGE_H */

