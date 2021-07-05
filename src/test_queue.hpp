#ifndef TEST_QUEUE_HPP
#define TEST_QUEUE_HPP

#include <iostream>
#include <string>

#include "Queue.hpp"
#include "queue"

template <typename T>
void test_queue(T queue)
{
	std::cout << "Stack size: " << queue.size() << std::endl;
	std::cout << "Stack empty: " << std::boolalpha << queue.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: queue.push(4) 3, 2, 1" << RESET_C << std::endl;
	queue.push(4);
	queue.push(3);
	queue.push(2);
	queue.push(1);

	std::cout << "Stack size: " << queue.size() << std::endl;
	std::cout << "Stack empty: " << std::boolalpha << queue.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: queue.front()" << RESET_C << std::endl;
	std::cout << "Stack top: " << queue.front() << std::endl;

	std::cout << GREEN_C << "\tDO: newStack = queue" << RESET_C << std::endl;
	T newStack = queue;
	std::cout << "Stack size: " << newStack.size() << std::endl;

	std::cout << GREEN_C << "\tDO: queue.push(11)" << RESET_C << std::endl;
	queue.push(11);
	std::cout << "Stack size: " << queue.size() << std::endl;

	std::cout << "Stack queue == newStack: " << std::boolalpha << (queue == newStack) << std::endl;
	std::cout << "Stack queue != newStack: " << std::boolalpha << (queue != newStack) << std::endl;
	std::cout << "Stack queue < newStack: " << std::boolalpha << (queue < newStack) << std::endl;
	std::cout << "Stack queue <= newStack: " << std::boolalpha << (queue <= newStack) << std::endl;
	std::cout << "Stack queue > newStack: " << std::boolalpha << (queue > newStack) << std::endl;
	std::cout << "Stack queue >= newStack: " << std::boolalpha << (queue >= newStack) << std::endl;

	std::cout << GREEN_C << "\tDO: queue.pop()" << RESET_C << std::endl;
	while (!queue.empty())
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;

	std::cout << "Stack size: " << queue.size() << std::endl;

	std::cout << RED_C << "\tEnd tests" << RESET_C << std::endl;
}

#endif