#include "TimeSeries.h"

using namespace opt;

TimeSeries::TimeSeries(Symbol symbol, StandardTime start, StandardTime end, 
        float open, float close, float high, float low)
        : symbol(symbol), start(start), end(end) {
    this->open = open;
    this->close = close;
    this->high = high;
    this->low = low;
}

Symbol TimeSeries::get_symbol(void) { return symbol; }

StandardTime TimeSeries::get_start(void) { return start; }

StandardTime TimeSeries::get_end(void) { return end; }

float TimeSeries::get_open(void) { return open; }

float TimeSeries::get_close(void) { return close; }

float TimeSeries::get_high(void) { return high; }

float TimeSeries::get_low(void) { return low; }