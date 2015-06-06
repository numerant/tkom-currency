#ifndef SCANNER_H
#define	SCANNER_H

#include <istream>
#include "Token.h"

using namespace std;

namespace parser
{

    class Scanner
    {
    public:
        Scanner(std::istream& in);
        Scanner(const Scanner&) = delete;
        const Scanner& operator=(const Scanner&) = delete;
        void readNextToken();
        Token getToken() const;

    private:
        std::istream& in;
        Token token;

        void ignoreWhitespaces();
        bool tryBracket();
        bool tryOperator();
        bool tryTwoCharOperator();
        bool tryAlphaNum();
        bool tryEof();

    };

} /* namespace parser */
#endif	/* SCANNER_H */

