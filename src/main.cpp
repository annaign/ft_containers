#include <iostream>
#include <string>

#include "test_vector.hpp"
#include "test_list.hpp"
#include "test_map.hpp"
#include "test_stack.hpp"
#include "test_queue.hpp"

void runVector()
{
	std::cout << YELLOW_C << "----- STD Vector -----" << RESET_C << std::endl;
	std::vector<int> std_vector(5, 6);

	// test_vector(std::vector<int>());
	// test_vector(std::vector<int>(3));
	test_vector(std::vector<int>(std_vector));

	std::cout << YELLOW_C << "----- FT Vector -----" << RESET_C << std::endl;
	ft::vector<int> ft_vector(5, 6);

	// test_vector(ft::vector<int>());
	// test_vector(ft::vector<int>(3));
	test_vector(ft::vector<int>(ft_vector));
}

void runList()
{
	std::cout << YELLOW_C << "----- STD List -----" << RESET_C << std::endl;
	std::list<int> std_list;

	test_list(std::list<int>(std_list));

	std::cout << YELLOW_C << "----- FT List -----" << RESET_C << std::endl;
	ft::list<int> ft_list;

	test_list(ft::list<int>(ft_list));
}

void runMap()
{
	std::cout << YELLOW_C << "----- STD Map -----" << RESET_C << std::endl;
	std::map<int, int> std_map;

	test_map1(std::map<int, int>(std_map));

	std_map.insert(std::make_pair(7, 7));
	std_map.insert(std::make_pair(3, 3));
	std_map.insert(std::make_pair(9, 19));
	std_map.insert(std::make_pair(8, 8));
	std_map.insert(std::make_pair(8, 1));
	std_map.insert(std::make_pair(1, 1));
	std_map.insert(std::make_pair(10, 10));

	std::cout << GREEN_C << "\tDO: use map.value_comp()" << RESET_C << std::endl;
	std::map<int, int>::iterator it = std_map.begin();
	std::pair<int, int> highest = *std_map.rbegin(); // last element
	do
	{
		std::cout << it->first << " => " << it->second << "   ";
	} while (std_map.value_comp()(*it++, highest));
	std::cout << std::endl;

	std::cout << GREEN_C << "\tDO: use ret = std_map.equal_range(8)" << RESET_C << std::endl;
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ret;
	ret = std_map.equal_range(8);

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	test_map2(std_map);

	std::cout << YELLOW_C << "----- FT Map -----" << RESET_C << std::endl;
	ft::map<int, int> ft_map;

	test_map1(ft::map<int, int>(ft_map));

	ft_map.insert(ft::make_pair(7, 7));
	ft_map.insert(ft::make_pair(3, 3));
	ft_map.insert(ft::make_pair(9, 19));
	ft_map.insert(ft::make_pair(8, 8));
	ft_map.insert(ft::make_pair(8, 1));
	ft_map.insert(ft::make_pair(1, 1));
	ft_map.insert(ft::make_pair(10, 10));

	std::cout << GREEN_C << "\tDO: use map.value_comp()" << RESET_C << std::endl;
	ft::map<int, int>::iterator it2 = ft_map.begin();
	ft::pair<int, int> highest2 = *ft_map.rbegin(); // last element
	do
	{
		std::cout << it2->first << " => " << it2->second << "   ";
	} while (ft_map.value_comp()(*it2++, highest2));
	std::cout << std::endl;

	std::cout << GREEN_C << "\tDO: use ret2 = ft_map.equal_range(8)" << RESET_C << std::endl;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ret2;
	ret2 = ft_map.equal_range(8);

	std::cout << "lower bound points to: ";
	std::cout << ret2.first->first << " => " << ret2.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret2.second->first << " => " << ret2.second->second << '\n';

	test_map2(ft_map);
}

void runStack()
{
	std::cout << YELLOW_C << "----- STD Stack -----" << RESET_C << std::endl;
	std::stack<int> std_stack;

	test_stack(std::stack<int>(std_stack));

	std::cout << YELLOW_C << "----- FT Stack -----" << RESET_C << std::endl;
	ft::stack<int> ft_stack;

	test_stack(ft::stack<int>(ft_stack));
}

void runQueue()
{
	std::cout << YELLOW_C << "----- STD Stack -----" << RESET_C << std::endl;
	std::queue<int> std_queue;

	test_queue(std::queue<int>(std_queue));

	std::cout << YELLOW_C << "----- FT Stack -----" << RESET_C << std::endl;
	ft::queue<int> ft_queue;

	test_queue(ft::queue<int>(ft_queue));
}

int main(void)
{
	runVector();
	runList();
	runMap();
	runStack();
	runQueue();

	return 0;
}
