#include "ExchangeRateStorage.h"

using namespace data;

CurrencyVal ExchangeRateStorage::getRate(std::string from, std::string to)
{
    return storage.at(std::make_pair(from, to));
}

void ExchangeRateStorage::setRate(std::string from, std::string to, CurrencyVal rate)
{
    // Exchange rate upsert
    std::pair<std::string, std::string> key = std::make_pair(from, to);
    if (storage.find(key) == storage.end())
        storage.insert(std::make_pair(key, rate));
    else
        storage[key] = rate;
}
