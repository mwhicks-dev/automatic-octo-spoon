#include "TickerAdapter.h"

using namespace opt;

TickerAdapter::TickerAdapter(TickerData& data) : output_data(data) {}

void TickerAdapter::push_ticker(Ticker ticker) { output_data.push_ticker(ticker); }