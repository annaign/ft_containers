#ifndef TEST_MAP_HPP
#define TEST_MAP_HPP

#include <iostream>
#include <string>

#include "Map.hpp"
#include "map"

template <typename T>
void print_map(const T &map)
{
	std::cout << UNDERLINE_W << "Print map:" << RESET_C << " ";

	typename T::const_iterator it = map.begin();
	for (; it != map.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << "    ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_reverse_map(const T &map)
{
	std::cout << UNDERLINE_W << "Print map:" << RESET_C << " ";

	typename T::const_reverse_iterator it = map.rbegin();
	typename T::const_reverse_iterator itEnd = map.rend();
	for (; it != itEnd; ++it)
	{
		std::cout << it->first << " => " << it->second << "    ";
	}
	std::cout << std::endl;
}

template <typename T>
void test_map1(T map)
{
	std::cout << "map size: " << map.size() << std::endl;
	std::cout << "map max_size: " << map.max_size() << std::endl;
	std::cout << "map empty: " << std::boolalpha << map.empty() << std::endl;
	print_map(map);
}

template <typename T>
void test_map2(T map)
{
	std::cout << GREEN_C << "\tDO: map.insert(make_pair(7, 7)), 3-3  9-19  8-8  8-1  1-1  10-10" << RESET_C << std::endl;
	std::cout << "map size: " << map.size() << std::endl;
	print_map(map);

	std::cout << GREEN_C << "\tDO: print_reverse map" << RESET_C << std::endl;
	print_reverse_map(map);

	std::cout << GREEN_C << "\tDO: map.erase(++map.begin())" << RESET_C << std::endl;
	// map.erase(--map.end());
	map.erase(++map.begin());
	std::cout << "map size: " << map.size() << std::endl;
	print_map(map);

	std::cout << GREEN_C << "\tDO: constructor newmap(map)" << RESET_C << std::endl;
	T newmap(map);
	std::cout << "map size: " << newmap.size() << std::endl;
	print_map(newmap);

	std::cout << "Before swap" << std::endl;
	map.erase(++map.begin());
	print_map(map);
	print_map(newmap);
	std::cout << GREEN_C << "\tDO: map.swap(newmap)" << RESET_C << std::endl;
	map.swap(newmap);
	print_map(map);
	print_map(newmap);

	std::cout << GREEN_C << "\tDO: ft::swap(map, newmap)" << RESET_C << std::endl;
	ft::swap(map, newmap);
	print_map(map);
	print_map(newmap);

	std::cout << "map == map: " << std::boolalpha << (map == map) << std::endl;
	std::cout << "map == newmap: " << std::boolalpha << (map == newmap) << std::endl;
	std::cout << "map != newmap: " << std::boolalpha << (map != newmap) << std::endl;
	std::cout << "map < newmap: " << std::boolalpha << (map < newmap) << std::endl;
	std::cout << "map <= newmap: " << std::boolalpha << (map <= newmap) << std::endl;
	std::cout << "map > newmap: " << std::boolalpha << (map > newmap) << std::endl;
	std::cout << "map >= newmap: " << std::boolalpha << (map >= newmap) << std::endl;

	std::cout << GREEN_C << "\tDO: newmap2 = newmap" << RESET_C << std::endl;
	T newmap2 = newmap;
	std::cout << "map size: " << newmap2.size() << std::endl;
	print_map(newmap2);

	std::cout << GREEN_C << "\tDO: newmap2.erase(8)" << RESET_C << std::endl;
	std::cout << "newmap2 delete: " << newmap2.erase(8) << std::endl;
	std::cout << "newmap2 size: " << newmap2.size() << std::endl;
	print_map(newmap2);

	std::cout << GREEN_C << "\tDO: newmap2.erase(88)" << RESET_C << std::endl;
	std::cout << "newmap2 delete: " << newmap2.erase(88) << std::endl;
	std::cout << "newmap2 size: " << newmap2.size() << std::endl;
	print_map(newmap2);

	std::cout << GREEN_C << "\tDO: newmap2.count(8)" << RESET_C << std::endl;
	std::cout << "newmap2 count: " << newmap2.count(8) << std::endl;

	std::cout << GREEN_C << "\tDO: newmap2.count(7)" << RESET_C << std::endl;
	std::cout << "newmap2 count: " << newmap2.count(7) << std::endl;

	std::cout << GREEN_C << "\tDO: newmap2[9]" << RESET_C << std::endl;
	std::cout << "newmap2[9]: " << newmap2[9] << std::endl;
	print_map(newmap2);

	std::cout << GREEN_C << "\tDO: use map.key_comp()" << RESET_C << std::endl;
	typename T::key_compare mycomp = map.key_comp();
	int highest = map.rbegin()->first; // key value of last element

	typename T::iterator it = map.begin();
	do
	{
		std::cout << it->first << " => " << it->second << "   ";
	} while (mycomp((*it++).first, highest));
	std::cout << std::endl;

	std::cout << GREEN_C << "\tDO: map.lower_bound(7), map.upper_bound(9), map.erase(itlow, itup)" << RESET_C << std::endl;
	typename T::iterator itlow, itup;

	itlow = map.lower_bound(7); // itlow points to 7
	itup = map.upper_bound(9);	// itup points to 10 (not 9!)

	map.erase(itlow, itup); // erases [itlow,itup)

	for (typename T::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << it->first << " => " << it->second << "   ";
	std::cout << std::endl;

	std::cout << RED_C << "\tEnd tests" << RESET_C << std::endl;
}

#endif