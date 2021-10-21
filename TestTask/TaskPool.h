#pragma once

#include <queue>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <functional>

#include "Request.h"

class TaskPool
{
public:
	TaskPool(int numberOfThreads);
	~TaskPool();

	void AddTask(Request* request);
	void Stop();
private:
	int _numberOfThreads;
	std::queue<Request*> _taskQueue;
	std::vector<std::thread> _threads;
	bool _stopFlag;
	std::condition_variable _cvar;
	std::mutex _mtx;
};
