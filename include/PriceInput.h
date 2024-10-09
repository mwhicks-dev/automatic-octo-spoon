#ifndef opt_PriceInput_h
#define opt_PriceInput_h

#include "Symbol.h"

namespace opt {

    class PriceInput {

    public:

        virtual void update_ticker(Symbol, float) = 0;

    };

}

#endif