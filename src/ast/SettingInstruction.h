#ifndef SETTINGINSTRUCTION_H
#define	SETTINGINSTRUCTION_H

#include "InputInstruction.h"
#include "../data/ExchangeRateStorage.h"

namespace ast
{

    class SettingInstruction : public InputInstruction
    {
    public:
        SettingInstruction(std::string currFrom, int rate, std::string currTo,
                data::ExchangeRateStorage *storage);

        int execute() const override;
        std::string toString() const override;
    private:

        std::string currFrom;
        std::string currTo;
        int rate;
        data::ExchangeRateStorage *storage;
    };

}
#endif	/* SETTINGINSTRUCTION_H */

