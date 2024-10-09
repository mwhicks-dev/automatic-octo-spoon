#ifndef opt_TickerAdapter_h
#define opt_TickerAdapter_h

#include "ITickerOutput.h"
#include "TickerData.h"

namespace opt {

    class TickerAdapter : public ITickerOutput {

        TickerData& output_data;

    public:

        TickerAdapter(TickerData&);

        void push_ticker(Ticker);

    };

}

#endif