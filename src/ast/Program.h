#ifndef PROGRAM_H
#define	PROGRAM_H

#include <string>

namespace ast
{
    /* Class representing program constisting of multiple code lines. */
    class Program
    {
    public:
        virtual ~Program();
        virtual int execute() const = 0;
        virtual std::string toString() const = 0;

    private:

    };

}
#endif	/* PROGRAM_H */

