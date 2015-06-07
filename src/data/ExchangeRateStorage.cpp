#include "ExchangeRateStorage.h"

using namespace data;

bmp::cpp_dec_float_50 ExchangeRateStorage::getRate(std::string from, std::string to)
{
    return storage.at(std::make_pair(from, to));
}

void ExchangeRateStorage::setRate(std::string from, std::string to, bmp::cpp_dec_float_50 rate)
{
    // Exchange rate upsert
    std::pair<std::string, std::string> key = std::make_pair(from, to);
    if (storage.find(key) == storage.end())
        storage.insert(std::make_pair(key, rate));
    else
        storage[key] = rate;
}
