#ifndef EXCHANGERATESTORAGE_H
#define	EXCHANGERATESTORAGE_H

#include <map>
#include <utility>

namespace data
{

    class ExchangeRateStorage
    {
    public:
        void setRate(std::string from, std::string to, int rate);
        int getRate(std::string from, std::string to);
    private:
        std::map<std::pair<std::string, std::string>, int> storage;
    };

}
#endif	/* EXCHANGERATESTORAGE_H */

