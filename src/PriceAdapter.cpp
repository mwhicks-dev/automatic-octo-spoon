#include "PriceAdapter.h"

using namespace opt;

PriceAdapter::PriceAdapter(IPriceInput& input) : input(input) {}

void PriceAdapter::update_ticker(std::string symbol, std::string name, 
        float value) {
    input.update_ticker(Symbol(symbol, name), value);
}