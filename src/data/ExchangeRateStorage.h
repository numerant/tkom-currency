#ifndef EXCHANGERATESTORAGE_H
#define	EXCHANGERATESTORAGE_H

#include <map>
#include <utility>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace bmp = boost::multiprecision;

namespace data
{

    class ExchangeRateStorage
    {
    public:
        void setRate(std::string from, std::string to, bmp::cpp_dec_float_50 rate);
        bmp::cpp_dec_float_50 getRate(std::string from, std::string to);
    private:
        std::map<std::pair<std::string, std::string>, bmp::cpp_dec_float_50> storage;
    };

}
#endif	/* EXCHANGERATESTORAGE_H */

