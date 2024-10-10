#ifndef opt_PriceAdapter_h
#define opt_PriceAdapter_h

#include "IPriceInput.h"
#include "StockData.h"

namespace opt {

    class PriceAdapter {

        IPriceInput& input;

    public:

        PriceAdapter(IPriceInput&);

        void update_ticker(StockData);

    };

}

#endif