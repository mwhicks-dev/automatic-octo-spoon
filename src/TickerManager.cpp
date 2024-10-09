#include "TickerManager.h"

using namespace opt;

TickerManager::TickerManager(ITickerOutput& adapter)
    : adapter(adapter) {}

void TickerManager::update_ticker(Symbol symb, float value) {
    // get current time
    std::chrono::system_clock c;
    StandardTime t(c.to_time_t(c.now()));

    // create new ticker
    Ticker ticker(symb, t, value);
    adapter.push_ticker(Ticker(symb, t, value));
}