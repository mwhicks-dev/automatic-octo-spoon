#ifndef opt_TickerData_h
#define opt_TickerData_h

#include <string>

namespace opt {

    struct TickerData {

        std::string symbol, name, timestamp;

        float value;

        TickerData(std::string, std::string, std::string, float);

    };

}

#endif