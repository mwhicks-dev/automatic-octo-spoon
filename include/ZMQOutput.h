#ifndef opt_ZMQOutput_h
#define opt_ZMQOutput_h

#include <zmq.hpp>

#include "IOutputAdapter.h"

namespace opt {

    class ZMQOutput : public IOutputAdapter {

        zmq::context_t context;
        zmq::socket_t publisher;

    public:

        ZMQOutput();

        void process_tickers(TickerQueue&);

    };

}

#endif