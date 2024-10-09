#include "TickerQueue.h"

using namespace opt;

TickerQueue::TickerQueue(std::string format_string) { 
    this->format_string = format_string;
}

void TickerQueue::push_ticker(Ticker ticker) { tickers.push(ticker); }

TickerData TickerQueue::pop_data(void) { 
    Ticker ticker = tickers.front(); 
    tickers.pop();

    return TickerData(
        ticker.get_symbol().get_symbol(),
        ticker.get_symbol().get_name(),
        ticker.get_time().format(format_string),
        ticker.get_value()
    );
}

bool TickerQueue::ticker_available(void) { return !tickers.empty(); }