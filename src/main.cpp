#include <cstdlib>
#include <iostream>
#include "parser/Scanner.h"
#include "parser/Parser.h"

using namespace std;
using namespace parser;

int main(int argc, char** argv)
{
    Parser p(std::make_unique<Scanner>(std::cin));
    auto var1 = std::move(p.parse());
    var1->execute();

    return 0;
}

