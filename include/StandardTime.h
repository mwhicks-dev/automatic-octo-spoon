#ifndef opt_StandardTime_h
#define opt_StandardTime_h

#include <string>
#include <chrono>

namespace opt {

    class StandardTime {

        time_t unix_time;

        void set_unix_time(time_t);

    public:

        StandardTime(time_t);
        
        StandardTime();

        time_t get_unix_time(void);

        std::string format(std::string);

    };

}

#endif