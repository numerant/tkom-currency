#ifndef INSTRSEQUENCE_H
#define	INSTRSEQUENCE_H

#include <string>

namespace ast
{
    /* Class representing instruction sequence in function. */
    class InstrSequence
    {
    public:
        InstrSequence();
        int execute() const;
        std::string toString() const;
    private:

    };

}
#endif	/* INSTRSEQUENCE_H */

