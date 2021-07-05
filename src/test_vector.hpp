#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>

#include "Vector.hpp"
#include "vector"

template <typename T>
void print_vector(const T &vector)
{
	std::cout << UNDERLINE_W << "Print vector:" << RESET_C << " ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_vector2(const T &vector)
{
	std::cout << UNDERLINE_W << "Print vector:" << RESET_C << " ";

	typename T::const_iterator it = vector.begin();
	for (; it != vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void test_vector(T vector)
{
	// print_vector(vector);
	// std::cout << GREEN_C << "\tDO: vector.reserve(0)" << RESET_C << std::endl;
	// vector.reserve(0);
	// print_vector(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;
	std::cout << "Vector max_size: " << vector.max_size() << std::endl;
	std::cout << "Vector empty: " << std::boolalpha << vector.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.push_back(4)" << RESET_C << std::endl;
	vector.push_back(4);
	print_vector2(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;
	std::cout << "Vector empty: " << std::boolalpha << vector.empty() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.reserve(8)" << RESET_C << std::endl;
	vector.reserve(8);
	print_vector(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.resize(10)" << RESET_C << std::endl;
	vector.resize(10);
	print_vector(vector);
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.resize(5)" << RESET_C << std::endl;
	vector.resize(5);
	print_vector(vector);
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.push_back(9)" << RESET_C << std::endl;
	vector.push_back(9);
	print_vector(vector);
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.pop_back()" << RESET_C << std::endl;
	vector.pop_back();
	print_vector(vector);
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: vector.push_back(8)" << RESET_C << std::endl;
	vector.push_back(8);
	print_vector(vector);
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << "Vector vector.at(0) : " << vector.at(0) << std::endl;
	try
	{
		std::cout << "Vector vector.at(vector.size()) : " << vector.at(vector.size()) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED_C << e.what() << RESET_C << '\n';
	}
	std::cout << "Vector vector.front() : " << vector.front() << std::endl;
	std::cout << "Vector vector.back() : " << vector.back() << std::endl;

	std::cout << GREEN_C << "\tDO: assign(4, 2)" << RESET_C << std::endl;
	vector.assign(4, 2);
	print_vector(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;

	int tmp[3];
	tmp[0] = 1;
	tmp[1] = 2;
	tmp[2] = 3;

	std::cout << GREEN_C << "\tDO: int tmp[3], assign(tmp, tmp + 3)" << RESET_C << std::endl;
	vector.assign(tmp, tmp + 3);
	print_vector(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;

	typename T::iterator it = vector.begin();
	typename T::iterator it_end = vector.end();

	std::cout << GREEN_C << "\tDO: iterator print vector" << RESET_C << std::endl;
	while (it != it_end)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	typename T::reverse_iterator it_rev = vector.rbegin();
	typename T::reverse_iterator it_rev_end = vector.rend();

	std::cout << GREEN_C << "\tDO: reverse_iterator print vector" << RESET_C << std::endl;
	while (it_rev != it_rev_end)
	{
		std::cout << *it_rev << " ";
		++it_rev;
	}
	std::cout << std::endl;

	T tmp_vector;
	tmp_vector.assign(4, 3);
	tmp_vector.push_back(8);
	it = tmp_vector.begin();

	std::cout << GREEN_C << "\tDO: tmp_vector.assign(4, 3), tmp_vector.push_back(8), assign(it, tmp_vector.end())"
			  << RESET_C << std::endl;
	vector.assign(it, tmp_vector.end());
	print_vector(vector);

	std::cout << "Vector capacity: " << vector.capacity() << std::endl;
	std::cout << "Vector size: " << vector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: newVector = vector" << RESET_C << std::endl;
	T newVector = vector;
	print_vector(newVector);

	std::cout << "newVector capacity: " << newVector.capacity() << std::endl;
	std::cout << "newVector size: " << newVector.size() << std::endl;

	std::cout << "Vector vector == newVector: " << std::boolalpha << (vector == newVector) << std::endl;
	std::cout << "Vector vector != newVector: " << std::boolalpha << (vector != newVector) << std::endl;

	std::cout << GREEN_C << "\tDO: vector.push_back(8)" << RESET_C << std::endl;
	vector.push_back(7);
	print_vector(vector);

	std::cout << "Vector vector == newVector: " << std::boolalpha << (vector == newVector) << std::endl;
	std::cout << "Vector vector < newVector: " << std::boolalpha << (vector < newVector) << std::endl;
	std::cout << "Vector vector <= newVector: " << std::boolalpha << (vector <= newVector) << std::endl;
	std::cout << "Vector vector > newVector: " << std::boolalpha << (vector > newVector) << std::endl;
	std::cout << "Vector vector >= newVector: " << std::boolalpha << (vector >= newVector) << std::endl;

	std::cout << "Before swap" << std::endl;
	print_vector(vector);
	print_vector(newVector);
	std::cout << GREEN_C << "\tDO: vector.swap(newVector)" << RESET_C << std::endl;
	vector.swap(newVector);
	print_vector(vector);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: ft::swap(vector, newVector)" << RESET_C << std::endl;
	ft::swap(vector, newVector);
	print_vector(vector);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.insert(newVector.begin(), 0)" << RESET_C << std::endl;
	newVector.insert(newVector.begin(), 0);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.insert(++(newVector.begin()), 2, 1)" << RESET_C << std::endl;
	newVector.insert(++(newVector.begin()), 2, 1);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.insert(--(newVector.end()), 3, 5)" << RESET_C << std::endl;
	newVector.insert(newVector.end(), 3, 5);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.clear()" << RESET_C << std::endl;
	newVector.clear();
	print_vector(newVector);

	std::cout << "newVector capacity: " << newVector.capacity() << std::endl;
	std::cout << "newVector size: " << newVector.size() << std::endl;

	std::cout << GREEN_C << "\tDO: newVector.insert(newVector.begin(), 3, 1)" << RESET_C << std::endl;
	newVector.insert(newVector.begin(), 3, 1);
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.insert(newVector.begin() + 2, vector.begin(), vector.end())"
			  << RESET_C << std::endl;
	newVector.insert(newVector.begin() + 2, vector.begin(), vector.end());
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.erase(newVector.begin())" << RESET_C << std::endl;
	newVector.erase(newVector.begin());
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.erase(--(newVector.end()))" << RESET_C << std::endl;
	newVector.erase(--(newVector.end()));
	print_vector(newVector);

	std::cout << GREEN_C << "\tDO: newVector.erase(newVector.begin())" << RESET_C << std::endl;
	newVector.erase(newVector.begin() + 1, newVector.begin() + 5);
	print_vector(newVector);

	std::cout << RED_C << "\tEnd tests" << RESET_C << std::endl;
}

#endif