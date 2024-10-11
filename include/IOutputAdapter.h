#ifndef opt_IOutputAdapter_h
#define opt_IOutputAdapter_h

#include "TickerQueue.h"

namespace opt {

    class IOutputAdapter {

    public:

        virtual void process_tickers(TickerQueue&) = 0;

    };

}

#endif