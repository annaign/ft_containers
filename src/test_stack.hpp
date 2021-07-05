#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

#include <iostream>
#include <string>

#include "Stack.hpp"
#include "stack"

template <typename T>
void test_stack(T stack)
{
	std::cout << "Stack size: " << stack.size() << std::endl;
	std::cout << "Stack empty: " << std::boolalpha << stack.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: stack.push(4) 3, 2, 1" << RESET_C << std::endl;
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);

	std::cout << "Stack size: " << stack.size() << std::endl;
	std::cout << "Stack empty: " << std::boolalpha << stack.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: stack.top()" << RESET_C << std::endl;
	std::cout << "Stack top: " << stack.top() << std::endl;

	std::cout << GREEN_C << "\tDO: newStack = queue" << RESET_C << std::endl;
	T newStack = stack;
	std::cout << "Stack size: " << newStack.size() << std::endl;

	std::cout << GREEN_C << "\tDO: stack.push(11)" << RESET_C << std::endl;
	stack.push(11);
	std::cout << "Stack size: " << stack.size() << std::endl;

	std::cout << "Stack stack == newStack: " << std::boolalpha << (stack == newStack) << std::endl;
	std::cout << "Stack stack != newStack: " << std::boolalpha << (stack != newStack) << std::endl;
	std::cout << "Stack stack < newStack: " << std::boolalpha << (stack < newStack) << std::endl;
	std::cout << "Stack stack <= newStack: " << std::boolalpha << (stack <= newStack) << std::endl;
	std::cout << "Stack stack > newStack: " << std::boolalpha << (stack > newStack) << std::endl;
	std::cout << "Stack stack >= newStack: " << std::boolalpha << (stack >= newStack) << std::endl;

	std::cout << GREEN_C << "\tDO: stack.pop()" << RESET_C << std::endl;
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;

	std::cout << "Stack size: " << stack.size() << std::endl;

	std::cout << RED_C << "\tEnd tests" << RESET_C << std::endl;
}

#endif