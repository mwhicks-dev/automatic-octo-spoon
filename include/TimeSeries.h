#ifndef opt_TimeSeries_h
#define opt_TimeSeries_h

#include "Symbol.h"
#include "StandardTime.h"

namespace opt {

    class TimeSeries {

        Symbol symbol;

        StandardTime start, end;

        float open, close, high, low;

    public:

        TimeSeries(Symbol, StandardTime, StandardTime, 
                float, float, float, float);
            
        Symbol get_symbol(void);

        StandardTime get_start(void);

        StandardTime get_end(void);

        float get_open(void);

        float get_close(void);

        float get_high(void);

        float get_low(void);

    };

}

#endif