#pragma once

class Request {};

Request* GetRequest() noexcept;

void ProcessRequest(Request* request) noexcept;

constexpr int NumberOfThreads = 2;
