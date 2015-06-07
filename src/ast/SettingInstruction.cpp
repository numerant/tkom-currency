#include "SettingInstruction.h"

using namespace ast;

SettingInstruction::SettingInstruction(std::string currFrom, std::unique_ptr<CurrencyVal> rate, std::string currTo,
        data::ExchangeRateStorage *storage)
{
    this->currFrom = currFrom;
    this->rate = std::move(rate);
    this->currTo = currTo;
    this->storage = storage;
}

int SettingInstruction::execute() const
{
    storage->setRate(currFrom, currTo, *rate);
}

std::string SettingInstruction::toString() const
{
   // return "SET " + currFrom + " = " + std::to_string(rate) + " " + currTo;
}
