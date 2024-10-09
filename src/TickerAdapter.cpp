#include "TickerAdapter.h"

using namespace opt;

TickerAdapter::TickerAdapter(TickerQueue& data) : output_data(data) {}

void TickerAdapter::push_ticker(Ticker ticker) { output_data.push_ticker(ticker); }