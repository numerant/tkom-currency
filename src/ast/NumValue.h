#ifndef NUMVALUE_H
#define	NUMVALUE_H

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/number.hpp>

/* NumValue type is Boost's cpp_dec_float. */
typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<10>> NumValue;

#endif	/* NUMVALUE_H */

