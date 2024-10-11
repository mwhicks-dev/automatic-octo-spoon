#ifndef opt_FinazonInput_h
#define opt_FinazonInput_h

#include "IDataAdapter.h"

namespace opt {

    class FinazonInput : public IDataAdapter {

        std::string api_key;
        std::string base_url;

        std::string get(std::string);

    public:

        FinazonInput(std::string, std::string);

        StockData read_stock(std::string);

    };

}

#endif