#ifndef opt_TickerData_h
#define opt_TickerData_h

#include "Ticker.h"

#include <queue>

namespace opt {

    class TickerData {

        std::queue<Ticker> tickers;

    public:

        void push_ticker(Ticker);

        Ticker pop_ticker(void);

        bool ticker_available(void);

    };

}

#endif