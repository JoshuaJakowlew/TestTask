#include <chrono>
#include <thread>
#include <iostream>

#include "Request.h"

using namespace std::chrono_literals;

Request* GetRequest() noexcept
{
    static int n = 5;

    std::this_thread::sleep_for(100ms);

    std::cout << "GetRequest" << std::endl;

    return (n-- > 0) ? new Request : nullptr;
}

void ProcessRequest(Request* request) noexcept
{
    std::this_thread::sleep_for(250ms);
    std::cout << "ProcessRequst" << std::endl;
}
