#ifndef opt_PriceAdapter_h
#define opt_PriceAdapter_h

#include "IPriceInput.h"

namespace opt {

    class PriceAdapter {

        IPriceInput& input;

    public:

        PriceAdapter(IPriceInput&);

        void update_ticker(std::string, std::string, float);

    };

}

#endif