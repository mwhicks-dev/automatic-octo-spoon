#include "TickerData.h"

using namespace opt;

TickerData::TickerData(std::string symbol, std::string name,
        std::string timestamp, float value) {
    this->symbol = symbol;
    this->name = name;
    this->timestamp = timestamp;
    this->value = value;
}