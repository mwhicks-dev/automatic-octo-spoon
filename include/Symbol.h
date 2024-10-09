#ifndef opt_Symbol_h
#define opt_Symbol_h

#include <string>

namespace opt {

    class Symbol {

        std::string symbol;

        std::string name;

    public:

        Symbol(std::string, std::string);

        std::string get_symbol(void);

        std::string get_name(void);

    };

}

#endif