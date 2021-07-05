#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

namespace ft
{
	template <typename T, typename Container = ft::list<T> >
	class queue
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type container_;

	public:
		explicit queue(const container_type &ctnr = container_type());
		virtual ~queue();

		queue &operator=(queue const &rhs);

		bool empty() const;
		size_type size() const;
		value_type &front();
		const value_type &front() const;
		value_type &back();
		const value_type &back() const;
		void push(const value_type &val);
		void pop();

		template <typename T1, typename Cont1>
		friend bool operator==(const queue<T1, Cont1> &, const queue<T1, Cont1> &);

		template <typename T1, typename Cont1>
		friend bool operator<(const queue<T1, Cont1> &, const queue<T1, Cont1> &);
	};

	template <typename T, typename Container>
	queue<T, Container>::queue(const container_type &ctnr) : container_(ctnr)
	{
	}

	template <typename T, typename Container>
	queue<T, Container>::~queue()
	{
	}

	template <typename T, typename Container>
	queue<T, Container> &queue<T, Container>::operator=(queue const &rhs)
	{
		if (this != &rhs)
		{
			this->container_ = rhs.container_;
		}

		return *this;
	}

	template <typename T, typename Container>
	bool queue<T, Container>::empty() const
	{
		return this->container_.empty();
	}

	template <typename T, typename Container>
	typename queue<T, Container>::size_type queue<T, Container>::size() const
	{
		return this->container_.size();
	}

	template <typename T, typename Container>
	typename queue<T, Container>::value_type &queue<T, Container>::front()
	{
		return this->container_.front();
	}

	template <typename T, typename Container>
	const typename queue<T, Container>::value_type &queue<T, Container>::front() const
	{
		return this->container_.front();
	}

	template <typename T, typename Container>
	typename queue<T, Container>::value_type &queue<T, Container>::back()
	{
		return this->container_.back();
	}

	template <typename T, typename Container>
	const typename queue<T, Container>::value_type &queue<T, Container>::back() const
	{
		return this->container_.back();
	}

	template <typename T, typename Container>
	void queue<T, Container>::push(const value_type &val)
	{
		this->container_.push_back(val);
	}
	template <typename T, typename Container>
	void queue<T, Container>::pop()
	{
		this->container_.pop_front();
	}

	//=========================

	template <typename T, typename Container>
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{

		return lhs.container_ == rhs.container_;
	}

	template <typename T, typename Container>
	bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return lhs.container_ < rhs.container_;
	}

	template <typename T, typename Container>
	bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
} // namespace ft

#endif