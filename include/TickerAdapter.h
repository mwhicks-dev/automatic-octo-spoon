#ifndef opt_TickerAdapter_h
#define opt_TickerAdapter_h

#include "ITickerOutput.h"
#include "TickerQueue.h"

namespace opt {

    class TickerAdapter : public ITickerOutput {

        TickerQueue& output_data;

    public:

        TickerAdapter(TickerQueue&);

        void push_ticker(Ticker);

    };

}

#endif