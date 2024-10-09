#ifndef opt_TickerQueue_h
#define opt_TickerQueue_h

#include "Ticker.h"
#include "TickerData.h"

#include <queue>

namespace opt {

    class TickerQueue {

        std::queue<Ticker> tickers;

        std::string format_string;

    public:

        TickerQueue(std::string);

        void push_ticker(Ticker);

        TickerData pop_data(void);

        bool ticker_available(void);

    };

}

#endif