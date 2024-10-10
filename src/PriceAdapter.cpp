#include "PriceAdapter.h"

using namespace opt;

PriceAdapter::PriceAdapter(IPriceInput& input) : input(input) {}

void PriceAdapter::update_ticker(StockData dto) {
    input.update_ticker(Symbol(dto.symbol, dto.name), dto.value);
}