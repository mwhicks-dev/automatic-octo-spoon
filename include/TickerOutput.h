#ifndef opt_TickerOutput_h
#define opt_TickerOutput_h

#include "Ticker.h"

namespace opt {

    class TickerOutput {

    public:

        virtual void push_ticker(Ticker) = 0;

    };

}

#endif