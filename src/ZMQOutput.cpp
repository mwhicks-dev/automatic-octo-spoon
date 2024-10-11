#include "ZMQOutput.h"

#include <sstream>

using namespace opt;

ZMQOutput::ZMQOutput() : context(1), 
    publisher(context, zmq::socket_type::pub) {
    publisher.bind("tcp://*:8000");
}

void ZMQOutput::process_tickers(TickerQueue& queue) {
    // send all tickers down zmq publisher
    if (!queue.ticker_available()) return;

    TickerData data = queue.pop_data();
    std::string ticker_string;
    {
        std::stringstream ss;
        ss << data.symbol
            << " " << data.timestamp
            << " " << data.value;
        ticker_string = ss.str();
    }

    zmq::message_t message(ticker_string);
    publisher.send(message, zmq::send_flags::none);
}