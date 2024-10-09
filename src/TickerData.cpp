#include "TickerData.h"

using namespace opt;

void TickerData::push_ticker(Ticker ticker) { tickers.push(ticker); }

Ticker TickerData::pop_ticker(void) { 
    Ticker res = tickers.front(); 
    tickers.pop();
    return res;
}

bool TickerData::ticker_available(void) { return !tickers.empty(); }