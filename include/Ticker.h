#ifndef opt_Ticker_h
#define opt_Ticker_h

#include "Symbol.h"
#include "StandardTime.h"

namespace opt {

    class Ticker {

        Symbol symbol;

        StandardTime time;

        float value;

    public:

        Ticker(Symbol, StandardTime, float);

        Symbol get_symbol(void);

        StandardTime get_time(void);

        float get_value(void);

    };

}

#endif