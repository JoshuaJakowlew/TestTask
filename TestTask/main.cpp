#include <iostream>

#include "TaskPool.h"

int main()
{
	std::cout << "Hello world\n";

	const auto start = std::chrono::steady_clock::now();

	TaskPool pool{ NumberOfThreads };

	while (auto request = GetRequest())
	{
		pool.AddTask(request);
	}

	pool.Stop();

	const auto end = std::chrono::steady_clock::now();
	const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>((end - start)).count();
	std::cout << elapsed << " vs " << 5 * (100 + 250) << std::endl;
}
