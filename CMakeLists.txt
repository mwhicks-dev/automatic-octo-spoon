cmake_minimum_required(VERSION 3.14)

project(automatic-octo-spoon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENTITY_SOURCES src/StandardTime.cpp src/Symbol.cpp src/Ticker.cpp src/TimeSeries.cpp)
set(APPLICATION_SOURCES src/TickerManager.cpp)
set(ADAPTER_SOURCES src/PriceAdapter.cpp src/TickerData.cpp src/TickerQueue.cpp src/TickerAdapter.cpp)

add_library(opt-entity STATIC ${ENTITY_SOURCES})
target_include_directories(opt-entity PUBLIC ./include)

add_library(opt-application STATIC ${APPLICATION_SOURCES})
target_include_directories(opt-application PUBLIC ./include)
target_link_libraries(opt-application opt-entity)

add_library(opt-adapter STATIC ${ADAPTER_SOURCES})
target_include_directories(opt-adapter PUBLIC ./include)
target_link_libraries(opt-adapter opt-entity opt-application)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(standard_time_test test/TestStandardTime.cpp)
target_link_libraries(standard_time_test opt-entity gtest gtest_main)

add_executable(symbol_test test/TestSymbol.cpp)
target_link_libraries(symbol_test opt-entity gtest gtest_main)

add_executable(ticker_test test/TestTicker.cpp)
target_link_libraries(ticker_test opt-entity gtest gtest_main)

add_executable(time_series_test test/TestTimeSeries.cpp)
target_link_libraries(time_series_test opt-entity gtest gtest_main)

add_executable(ticker_data_test test/TestTickerData.cpp)
target_link_libraries(ticker_data_test opt-entity opt-application opt-adapter gtest gtest_main)

add_executable(ticker_queue_test test/TestTickerQueue.cpp)
target_link_libraries(ticker_queue_test opt-entity opt-application opt-adapter gtest gtest_main)

add_executable(adapter_integration_test test/TestApplicationAdapters.cpp)
target_link_libraries(adapter_integration_test opt-entity opt-application opt-adapter gtest gtest_main)