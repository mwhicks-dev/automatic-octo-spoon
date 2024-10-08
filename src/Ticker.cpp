#include "Ticker.h"

using namespace opt;

Ticker::Ticker(Symbol symbol, StandardTime time, float value) 
        : symbol(symbol), time(time) {
    this->value = value;
}

Symbol Ticker::get_symbol(void) { return symbol; }

StandardTime Ticker::get_time(void) { return time; }

float Ticker::get_value(void) { return value; }