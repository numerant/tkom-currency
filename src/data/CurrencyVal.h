#ifndef CURRENCYVAL_H
#define	CURRENCYVAL_H

class CurrencyVal
{
public:
    CurrencyVal(int integer, int fraction, int precision);
    CurrencyVal operator+(const CurrencyVal& value);
    CurrencyVal operator-(const CurrencyVal& value);
    CurrencyVal operator*(const int& multiplier);
    CurrencyVal operator/(const int& divisor);

    int getFraction() const;
    int getInteger() const;
    int getPrecision() const;
private:


    int integer;
    int fraction;
    int precision;
};

#endif	/* CURRENCYVAL_H */

