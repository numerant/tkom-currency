#ifndef CURRENCY_H
#define	CURRENCY_H

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/number.hpp>

typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<10>> Currency;

#endif	/* CURRENCY_H */

