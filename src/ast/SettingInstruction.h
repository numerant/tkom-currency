#ifndef SETTINGINSTRUCTION_H
#define	SETTINGINSTRUCTION_H

#include <memory>
#include "Currency.h"
#include "InputInstruction.h"
#include "../data/ExchangeRateStorage.h"

namespace bmp = boost::multiprecision;

namespace ast
{

    class SettingInstruction : public InputInstruction
    {
    public:
        SettingInstruction(std::string currFrom, Currency rate, std::string currTo,
                data::ExchangeRateStorage *storage);

        int execute() const override;
        std::string toString() const override;
    private:

        std::string currFrom;
        std::string currTo;
        Currency rate;
        data::ExchangeRateStorage *storage;
    };

}
#endif	/* SETTINGINSTRUCTION_H */

