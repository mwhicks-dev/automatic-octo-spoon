#include "StandardTime.h"

#include <iomanip>
#include <sstream>

using namespace opt;

void StandardTime::set_unix_time(time_t t) { this->unix_time = t; }

StandardTime::StandardTime(time_t t) { set_unix_time(t); }

std::chrono::system_clock c;

StandardTime::StandardTime() { 
    set_unix_time(
        c.to_time_t(c.now())
    );
}

std::string StandardTime::format(std::string fmt) {
    std::tm tm = *std::localtime(&unix_time);

    std::stringstream ss;
    ss << std::put_time(&tm, fmt.c_str());
    return ss.str();
}
