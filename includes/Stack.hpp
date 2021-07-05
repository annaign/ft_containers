#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type container_;

	public:
		explicit stack(const container_type &ctnr = container_type());
		virtual ~stack();

		stack &operator=(stack const &rhs);

		bool empty() const;
		size_type size() const;
		value_type &top();
		const value_type &top() const;
		void push(const value_type &val);
		void pop();

		template <typename T1, typename Cont1>
		friend bool operator==(const stack<T1, Cont1> &, const stack<T1, Cont1> &);

		template <typename T1, typename Cont1>
		friend bool operator<(const stack<T1, Cont1> &, const stack<T1, Cont1> &);
	};

	template <typename T, typename Container>
	stack<T, Container>::stack(const container_type &ctnr) : container_(ctnr)
	{
	}

	template <typename T, typename Container>
	stack<T, Container>::~stack()
	{
	}

	template <typename T, typename Container>
	stack<T, Container> &stack<T, Container>::operator=(stack const &rhs)
	{
		if (this != &rhs)
		{
			this->container_ = rhs.container_;
		}

		return *this;
	}

	template <typename T, typename Container>
	bool stack<T, Container>::empty() const
	{
		return this->container_.empty();
	}

	template <typename T, typename Container>
	typename stack<T, Container>::size_type stack<T, Container>::size() const
	{
		return this->container_.size();
	}

	template <typename T, typename Container>
	typename stack<T, Container>::value_type &stack<T, Container>::top()
	{
		return this->container_.back();
	}

	template <typename T, typename Container>
	const typename stack<T, Container>::value_type &stack<T, Container>::top() const
	{
		return this->container_.back();
	}

	template <typename T, typename Container>
	void stack<T, Container>::push(const value_type &val)
	{
		this->container_.push_back(val);
	}
	template <typename T, typename Container>
	void stack<T, Container>::pop()
	{
		this->container_.pop_back();
	}

	//=========================

	template <typename T, typename Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{

		return lhs.container_ == rhs.container_;
	}

	template <typename T, typename Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.container_ < rhs.container_;
	}

	template <typename T, typename Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
} // namespace ft

#endif