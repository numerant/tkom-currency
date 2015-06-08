#ifndef AMOUNT_H
#define	AMOUNT_H

#include <sstream>
#include <string>
#include "NumValue.h"

namespace bmp = boost::multiprecision;

namespace ast
{

    class Amount
    {
    public:
        Amount(int integer);
        Amount(int integer, std::string fraction);
        std::string toString() const;
        NumValue getValue() const;
    private:
        NumValue value;
    };

}

#endif	/* AMOUNT_H */

