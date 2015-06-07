#include <cstdlib>
#include <iostream>
#include "parser/Scanner.h"
#include "parser/Parser.h"

using namespace std;
using namespace parser;

/*
 *
 */
int main(int argc, char** argv)
{
    Scanner scanner(cin);

    while(cin)
    {
        scanner.readNextToken();
        cout << scanner.getToken().toString() << "\n";
    }

//      Parser p(std::make_unique<Scanner>(std::cin));
//      p.parse()->execute();

    return 0;
}

