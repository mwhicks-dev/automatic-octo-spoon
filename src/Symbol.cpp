#include "Symbol.h"

using namespace opt;

Symbol::Symbol(std::string symbol, std::string name) {
    this->symbol = symbol;
    this->name = name;
}

std::string Symbol::get_symbol(void) { return symbol; }

std::string Symbol::get_name(void) { return name; }