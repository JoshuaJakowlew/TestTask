#include <iostream>

#include "TaskPool.h"

TaskPool::TaskPool(int numberOfThreads) :
	_numberOfThreads{ numberOfThreads },
	_stopFlag{false}
{
	_threads.reserve(numberOfThreads);
	for (int i = 0; i < numberOfThreads; ++i)
	{
		_threads.emplace_back([i, this] {
			while (!_stopFlag)
			{
				std::unique_lock<std::mutex> lock{ _mtx };
				if (_taskQueue.empty())
					continue;

				auto request = _taskQueue.front();
				_taskQueue.pop();
				lock.unlock();

				std::cout << "Thread " << i << std::endl;
				ProcessRequest(request);
			}
		});
	} 
}

TaskPool::~TaskPool()
{
	for (auto&& thread : _threads)
		thread.join();
}

void TaskPool::AddTask(Request* request)
{
	std::unique_lock<std::mutex> lock{ _mtx };
	_taskQueue.push(request);
}

void TaskPool::Stop()
{
	std::unique_lock<std::mutex> lock{ _mtx };
	_stopFlag = true;
}
