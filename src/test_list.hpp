#ifndef TEST_LIST_HPP
#define TEST_LIST_HPP

#include <iostream>
#include <string>

#include "List.hpp"
#include "list"

bool less_5(const int &value)
{
	return (value < 5);
}

struct is_near_5
{
	bool operator()(double first, double second)
	{
		return (first + second < 5);
	}
};

template <typename T>
void print_list(const T &list)
{
	std::cout << UNDERLINE_W << "Print list:" << RESET_C << " ";

	typename T::const_iterator it = list.begin();
	for (; it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_reverse_list(const T &list)
{
	std::cout << UNDERLINE_W << "Print list:" << RESET_C << " ";

	typename T::const_reverse_iterator it = list.rbegin();
	typename T::const_reverse_iterator itEnd = list.rend();
	for (; it != itEnd; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void test_list(T list)
{
	std::cout << "list.front(): " << list.front() << std::endl;
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "List max_size: " << list.max_size() << std::endl;
	std::cout << "List empty: " << std::boolalpha << list.empty() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.push_back(4), list.push_back(5)" << RESET_C << std::endl;
	list.push_back(4);
	list.push_back(5);
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: print_reverse list" << RESET_C << std::endl;
	print_reverse_list(list);

	std::cout << GREEN_C << "\tDO: list.pop_front()" << RESET_C << std::endl;
	list.pop_front();
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.pop_back()" << RESET_C << std::endl;
	list.pop_back();
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.push_front(4), list.push_front(5)" << RESET_C << std::endl;
	list.push_front(4);
	list.push_front(5);
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: ist.insert(list.begin(), 0)" << RESET_C << std::endl;
	list.insert(list.begin(), 0);
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.insert(list.end(), 9)" << RESET_C << std::endl;
	list.insert(list.end(), 9);
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.insert(++list.begin(), 2, 1)" << RESET_C << std::endl;
	list.insert(++list.begin(), 2, 1);
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	int tmp[3];
	tmp[0] = 1;
	tmp[1] = 2;
	tmp[2] = 3;

	std::cout << GREEN_C << "\tDO: int tmp[3], assign(tmp, tmp + 3)" << RESET_C << std::endl;
	list.insert(--list.end(), tmp, tmp + 3);
	print_list(list);

	std::cout << GREEN_C << "\tDO: constructor newlist(5, 3)" << RESET_C << std::endl;
	T newlist(5, 3);
	std::cout << "List size: " << newlist.size() << std::endl;
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: constructor newlist2(list.begin(), list.end())" << RESET_C << std::endl;
	T newlist2(list.begin(), list.end());
	std::cout << "List size: " << newlist2.size() << std::endl;
	print_list(newlist2);

	std::cout << GREEN_C << "\tDO: newlist = newlist2" << RESET_C << std::endl;
	newlist = newlist2;
	std::cout << "List size: " << newlist.size() << std::endl;
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: newlist.assign(3, 4)" << RESET_C << std::endl;
	newlist.assign(3, 4);
	std::cout << "List size: " << newlist.size() << std::endl;
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: constructor newlist2(list.begin(), --list.end())" << RESET_C << std::endl;
	newlist2.assign(newlist.begin(), --newlist.end());
	std::cout << "List size: " << newlist2.size() << std::endl;
	print_list(newlist2);

	std::cout << "Before swap" << std::endl;
	print_list(list);
	print_list(newlist);
	std::cout << GREEN_C << "\tDO: list.swap(newlist)" << RESET_C << std::endl;
	list.swap(newlist);
	print_list(list);
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: ft::swap(list, newlist)" << RESET_C << std::endl;
	ft::swap(list, newlist);
	print_list(list);
	print_list(newlist);

	std::cout << "list == list: " << std::boolalpha << (list == list) << std::endl;
	std::cout << "list == newlist: " << std::boolalpha << (list == newlist) << std::endl;
	std::cout << "list != newlist: " << std::boolalpha << (list != newlist) << std::endl;
	std::cout << "list < newlist: " << std::boolalpha << (list < newlist) << std::endl;
	std::cout << "list <= newlist: " << std::boolalpha << (list <= newlist) << std::endl;
	std::cout << "list > newlist: " << std::boolalpha << (list > newlist) << std::endl;
	std::cout << "list >= newlist: " << std::boolalpha << (list >= newlist) << std::endl;

	std::cout << GREEN_C << "\tDO: newlist2.splice(newlist2.end(), list)" << RESET_C << std::endl;
	newlist2.splice(newlist2.end(), list);
	std::cout << "List size: " << newlist2.size() << std::endl;
	print_list(newlist2);
	print_list(list);

	std::cout << GREEN_C << "\tDO: newlist.push_back(7)" << RESET_C << std::endl;
	newlist.push_back(7);
	std::cout << "List size: " << newlist.size() << std::endl;
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: list = newlist2" << RESET_C << std::endl;
	list = newlist2;
	std::cout << "List size: " << list.size() << std::endl;
	print_list(list);

	std::cout << GREEN_C << "\tDO: newlist2.sort()" << RESET_C << std::endl;
	newlist2.sort();
	print_list(newlist2);

	newlist = newlist2;

	std::cout << GREEN_C << "\tDO: list.sort(ft::greater<typename T::value_type>())" << RESET_C << std::endl;
	list.sort(ft::greater<typename T::value_type>());
	print_list(list);

	std::cout << GREEN_C << "\tDO: newlist2.resize(2)" << RESET_C << std::endl;
	newlist2.resize(2);
	print_list(newlist2);

	print_list(newlist);
	std::cout << GREEN_C << "\tDO: newlist.merge(newlist2)" << RESET_C << std::endl;
	newlist.merge(newlist2);
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: list.remove(4)" << RESET_C << std::endl;
	list.remove(4);
	print_list(list);

	std::cout << GREEN_C << "\tDO: list.remove(4)" << RESET_C << std::endl;
	list.remove_if(less_5);
	print_list(list);

	print_list(newlist);
	std::cout << GREEN_C << "\tDO: newlist.unique()" << RESET_C << std::endl;
	newlist.unique();
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: newlist.unique(is_near_5())" << RESET_C << std::endl;
	newlist.unique(is_near_5());
	print_list(newlist);

	std::cout << GREEN_C << "\tDO: newlist.reverse()" << RESET_C << std::endl;
	newlist.reverse();
	print_list(newlist);

	std::cout << RED_C << "\tEnd tests" << RESET_C << std::endl;
}

#endif