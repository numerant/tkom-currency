#include "SettingInstruction.h"

#include <iostream>

using namespace ast;

SettingInstruction::SettingInstruction(std::string currFrom, NumValue rate, std::string currTo,
        data::ExchangeRateStorage *storage)
{
    this->currFrom = currFrom;
    this->rate = rate;
    this->currTo = currTo;
    this->storage = storage;
}

int SettingInstruction::execute() const
{
    storage->setRate(currFrom, currTo, rate);
    std::cout << currFrom << currTo << rate;
}

std::string SettingInstruction::toString() const
{
   // return "SET " + currFrom + " = " + std::to_string(rate) + " " + currTo;
}
