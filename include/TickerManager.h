#ifndef opt_TickerManager_h
#define opt_TickerManager_h

#include "IPriceInput.h"
#include "ITickerOutput.h"

namespace opt {

    class TickerManager : public IPriceInput {

        ITickerOutput& adapter;

    public:

        TickerManager(ITickerOutput&);

        void update_ticker(Symbol, float) override;

    };

}

#endif