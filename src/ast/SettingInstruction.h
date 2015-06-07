#ifndef SETTINGINSTRUCTION_H
#define	SETTINGINSTRUCTION_H

#include <memory>
#include "InputInstruction.h"
#include "../data/ExchangeRateStorage.h"
#include "../data/CurrencyVal.h"

namespace ast
{

    class SettingInstruction : public InputInstruction
    {
    public:
        SettingInstruction(std::string currFrom, std::unique_ptr<CurrencyVal> rate, std::string currTo,
                data::ExchangeRateStorage *storage);

        int execute() const override;
        std::string toString() const override;
    private:

        std::string currFrom;
        std::string currTo;
        std::unique_ptr<CurrencyVal> rate;
        data::ExchangeRateStorage *storage;
    };

}
#endif	/* SETTINGINSTRUCTION_H */

