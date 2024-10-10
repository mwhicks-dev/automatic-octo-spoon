#ifndef opt_IDataAdapter_h
#define opt_IDataAdapter_h

#include "StockData.h"

namespace opt {

    class IDataAdapter {

    public:

        virtual StockData read_stock(std::string) = 0;

    };

}

#endif