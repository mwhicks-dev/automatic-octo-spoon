#include "FinazonInput.h"

#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include <sstream>
#include <stdexcept>

using namespace opt;

std::string FinazonInput::get(std::string url) {
    std::string response_body;

    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_body);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) 
        throw std::exception();

    return response_body;
}

FinazonInput::FinazonInput(std::string api_key, std::string base_url) 
        : api_key(api_key), base_url(base_url) {
    
}

static void invalid_symbol(std::string symbol) {
    std::stringstream ss;
    ss << "No such symbol " << symbol;
    throw std::invalid_argument(ss.str());
}

StockData FinazonInput::read_stock(std::string symbol) {
    std::string url;
    json response;
    
    StockData output;
    output.symbol = symbol;
    
    // read security name
    {
        std::stringstream ss;
        ss << base_url << "/tickers"
            << "?apikey=" << api_key
            << "&ticker=" << symbol;
        url = ss.str();
    }
    response = json::parse(get(url));
    if (response["data"].size() == 0)
        invalid_symbol(symbol);

    bool found = false;
    for (json data : response["data"]) {
        if (data["ticker"] != symbol)
            continue;
        
        output.name = data["security"];
        found = true;
        break;
    }
    
    if (!found)
        invalid_symbol(symbol);

    // read price
    {
        std::stringstream ss;
        ss << base_url << "/price"
            << "?apikey=" << api_key
            << "&ticker=" << symbol;
        url = ss.str();
    }
    response = json::parse(get(url));
    output.value = response["p"];

    return output;
}