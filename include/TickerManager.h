#ifndef opt_TickerManager_h
#define opt_TickerManager_h

#include "PriceInput.h"
#include "TickerOutput.h"

namespace opt {

    class TickerManager : public PriceInput {

        TickerOutput& adapter;

    public:

        TickerManager(TickerOutput&);

        void update_ticker(Symbol, float) override;

    };

}

#endif