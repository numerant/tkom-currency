#ifndef SETTINGINSTRUCTION_H
#define	SETTINGINSTRUCTION_H

#include <memory>
#include "NumValue.h"
#include "InputInstruction.h"
#include "../data/ExchangeRateStorage.h"

namespace ast
{

    class SettingInstruction : public InputInstruction
    {
    public:
        SettingInstruction(std::string currFrom, NumValue rate, std::string currTo,
                data::ExchangeRateStorage *storage);

        int execute() const override;
        std::string toString() const override;
    private:

        std::string currFrom;
        std::string currTo;
        NumValue rate;
        data::ExchangeRateStorage *storage;
    };

}
#endif	/* SETTINGINSTRUCTION_H */

