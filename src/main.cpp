#include <cstdlib>
#include <iostream>
#include "parser/Scanner.h"

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


    return 0;
}

