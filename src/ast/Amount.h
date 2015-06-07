#ifndef AMOUNT_H
#define	AMOUNT_H

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <sstream>
#include <string>

namespace bmp = boost::multiprecision;

namespace ast
{

    class Amount
    {
    public:
        Amount(int integer);
        Amount(int integer, std::string fraction);
        std::string toString() const;
        bmp::cpp_dec_float_50 getValue() const;
    private:
        bmp::cpp_dec_float_50 value;
    };

}

#endif	/* AMOUNT_H */

