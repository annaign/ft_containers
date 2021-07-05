#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utility.hpp"

namespace ft
{
	template <typename T>
	class list;

	template <typename T>
	class ListIterator
	{
	public:
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T *const_pointer;
		typedef const T &const_reference;
		typedef T value_type;

		typedef typename list<T>::node_ Node;

	protected:
		Node *ptr_current;

	public:
		ListIterator() : ptr_current(NULL) {}
		ListIterator(Node *ptr) : ptr_current(ptr) {}
		ListIterator(ListIterator const &src) : ptr_current(src.ptr_current) {}
		virtual ~ListIterator() {}

		ListIterator &operator=(ListIterator const &rhs)
		{
			this->ptr_current = rhs.ptr_current;
			return *this;
		}

		// Forward iterator requirements
		reference operator*()
		{
			return this->ptr_current->data;
		}

		const_reference operator*() const
		{
			return this->ptr_current->data;
		}

		pointer operator->()
		{
			return &this->ptr_current->data;
		}

		const_pointer operator->() const
		{
			return &this->ptr_current->data;
		}

		ListIterator &operator++()
		{
			this->ptr_current = this->ptr_current->next;
			return *this;
		}

		ListIterator operator++(int)
		{
			ListIterator it = *this;
			operator++();

			return it;
		}

		// Bidirectional iterator requirements
		ListIterator &operator--()
		{
			this->ptr_current = this->ptr_current->prev;
			return *this;
		}

		ListIterator operator--(int)
		{
			ListIterator it = *this;
			operator--();

			return it;
		}

		// Forward iterator requirements
		template <typename TT>
		friend bool operator==(const ListIterator<TT> &lhs, const ListIterator<TT> &rhs);

		template <typename TT>
		friend class list;
	};

	template <typename T>
	bool operator==(const ListIterator<T> &lhs, const ListIterator<T> &rhs)
	{
		return lhs.ptr_current == rhs.ptr_current;
	}

	template <typename T>
	bool operator!=(const ListIterator<T> &lhs, const ListIterator<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	class list
	{
	public:
		struct node_
		{
			T data;
			node_ *prev;
			node_ *next;

			node_(T data) : data(data), prev(NULL), next(NULL) {}
		};

		typedef T value_type;
		typedef T &reference;
		typedef T const &const_reference;
		typedef T *pointer;
		typedef T const *const_pointer;
		typedef ListIterator<value_type> iterator;
		typedef ListIterator<value_type const> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		node_ *first_;
		node_ *last_;
		size_type size_;

		void assign_int_(size_type count, const_reference value);
		template <typename InputIt>
		void assign_iter_(InputIt first, InputIt last);
		template <typename Integer>
		void assign_dispatch_(Integer count, Integer value, true_type);
		template <typename InputIt>
		void assign_dispatch_(InputIt first, InputIt last, false_type);

		void insert_int_(iterator pos, size_type count, const_reference value);
		template <typename InputIt>
		void insert_iter_(iterator pos, InputIt first, InputIt last);
		template <typename Integer>
		void insert_dispatch_(iterator pos, Integer count, Integer value, true_type);
		template <typename InputIt>
		void insert_dispatch_(iterator pos, InputIt first, InputIt last, false_type);

	public:
		explicit list();
		explicit list(size_type count, const_reference value = value_type());
		template <class InputIterator>
		list(InputIterator first, InputIterator last);
		list(const list &src);
		virtual ~list();

		list &operator=(const list &rhs);

		void assign(size_type count, const_reference value);
		template <class InputIt>
		void assign(InputIt first, InputIt last);

		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		void clear();

		iterator insert(iterator pos, const_reference value);
		void insert(iterator pos, size_type count, const_reference value);
		template <typename InputIt>
		void insert(iterator pos, InputIt first, InputIt last);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const_reference value);
		void pop_back();
		void push_front(const_reference value);
		void pop_front();
		void resize(size_type count, value_type value = value_type());
		void swap(list &other);

		void merge(list &other);
		template <class Compare>
		void merge(list &other, Compare comp);
		void splice(iterator pos, list &other);
		void splice(iterator pos, list &other, iterator it);
		void splice(iterator pos, list &other, iterator first, iterator last);
		void remove(const T &value);
		template <class UnaryPredicate>
		void remove_if(UnaryPredicate p);
		void reverse();
		void unique();
		template <class BinaryPredicate>
		void unique(BinaryPredicate p);
		void sort();
		template <class Compare>
		void sort(Compare comp);

		template <typename TT>
		friend class ListIterator;
	};

	template <typename T>
	list<T>::list() : size_(0)
	{
		this->first_ = new node_(value_type());
		this->last_ = this->first_;
	}

	template <typename T>
	list<T>::list(size_type count, const_reference value)
		: size_(0)
	{
		this->first_ = new node_(value_type());
		this->last_ = this->first_;

		this->insert(this->begin(), count, value);
	}

	template <typename T>
	template <class InputIterator>
	list<T>::list(InputIterator first, InputIterator last)
		: size_(0)
	{
		this->first_ = new node_(value_type());
		this->last_ = this->first_;

		this->insert(this->begin(), first, last);
	}

	template <typename T>
	list<T>::list(const list &src)
		: size_(0)
	{
		this->first_ = new node_(value_type());
		this->last_ = this->first_;

		if (src.size())
			this->insert(this->begin(), src.begin(), src.end());
	}

	template <typename T>
	list<T>::~list()
	{
		this->clear();
		delete this->first_;
	}

	template <typename T>
	list<T> &list<T>::operator=(list const &rhs)
	{
		if (this != &rhs)
		{
			this->clear();
			if (rhs.size())
				this->insert(this->begin(), rhs.begin(), rhs.end());
		}
		return *this;
	}

	template <typename T>
	void list<T>::assign_int_(size_type count, const_reference value)
	{
		this->clear();
		this->insert(this->begin(), count, value);
	}

	template <typename T>
	template <class InputIt>
	void list<T>::assign_iter_(InputIt first, InputIt last)
	{
		this->clear();
		this->insert(this->begin(), first, last);
	}

	template <typename T>
	template <typename Integer>
	void list<T>::assign_dispatch_(Integer count, Integer value, true_type)
	{
		assign_int_(count, value);
	}

	template <typename T>
	template <typename InputIt>
	void list<T>::assign_dispatch_(InputIt first, InputIt last, false_type)
	{
		assign_iter_(first, last);
	}

	template <typename T>
	void list<T>::assign(size_type count, const_reference value)
	{
		assign_int_(count, value);
	}

	template <typename T>
	template <typename InputIt>
	void list<T>::assign(InputIt first, InputIt last)
	{
		// Check whether it's an integral type. If so, it's not an iterator.
		typedef typename ft::is_integer<InputIt>::type Integral;

		assign_dispatch_(first, last, Integral());
	}

	template <typename T>
	typename list<T>::reference list<T>::front()
	{
		return this->first_->data;
	}

	template <typename T>
	typename list<T>::const_reference list<T>::front() const
	{
		return this->first_->data;
	}

	template <typename T>
	typename list<T>::reference list<T>::back()
	{
		return this->last_->prev->data;
	}

	template <typename T>
	typename list<T>::const_reference list<T>::back() const
	{
		return this->last_->prev->data;
	}

	template <typename T>
	typename list<T>::iterator list<T>::begin()
	{
		return iterator(this->first_);
	}

	template <typename T>
	typename list<T>::const_iterator list<T>::begin() const
	{
		typedef typename list<const T>::node_ constNode;
		return const_iterator(reinterpret_cast<constNode *>(this->first_));
	}

	template <typename T>
	typename list<T>::iterator list<T>::end()
	{
		return iterator(this->last_);
	}

	template <typename T>
	typename list<T>::const_iterator list<T>::end() const
	{
		typedef typename list<const T>::node_ constNode;
		return const_iterator(reinterpret_cast<constNode *>(this->last_));
	}

	template <typename T>
	typename list<T>::reverse_iterator list<T>::rbegin()
	{
		return list<T>::reverse_iterator(this->end());
	}

	template <typename T>
	typename list<T>::const_reverse_iterator list<T>::rbegin() const
	{
		return list<T>::const_reverse_iterator(this->end());
	}

	template <typename T>
	typename list<T>::reverse_iterator list<T>::rend()
	{
		return list<T>::reverse_iterator(this->begin());
	}

	template <typename T>
	typename list<T>::const_reverse_iterator list<T>::rend() const
	{
		return list<T>::const_reverse_iterator(this->begin());
	}

	template <typename T>
	bool list<T>::empty() const
	{
		return (this->size_ == 0);
	}

	template <typename T>
	typename list<T>::size_type list<T>::size() const
	{
		return this->size_;
	}

	template <typename T>
	typename list<T>::size_type list<T>::max_size() const
	{
		const size_type diffmax = std::numeric_limits<difference_type>::max() / sizeof(node_);
		const size_type allocmax = std::numeric_limits<size_type>::max() / (sizeof(node_));
		return (std::min)(diffmax, allocmax);
	}

	template <typename T>
	void list<T>::clear()
	{
		if (this->size_)
			this->erase(this->begin(), this->end());
	}

	template <typename T>
	typename list<T>::iterator list<T>::insert(iterator pos, const_reference value)
	{
		this->insert(pos, 1, value);
		return pos;
	}

	template <typename T>
	void list<T>::insert_int_(iterator pos, size_type count, const_reference value)
	{
		if (count == 0)
			return;

		while (count)
		{
			if (pos.ptr_current == this->first_)
				this->push_front(value);
			else if (pos.ptr_current == this->last_)
				this->push_back(value);
			else
			{
				node_ *newNode = new node_(value);

				newNode->next = pos.ptr_current;
				newNode->prev = pos.ptr_current->prev;
				pos.ptr_current->prev->next = newNode;
				pos.ptr_current->prev = newNode;

				++this->size_;
			}
			--count;
		}
	}

	template <typename T>
	template <typename InputIt>
	void list<T>::insert_iter_(iterator pos, InputIt first, InputIt last)
	{
		while (first != last)
		{
			if (pos.ptr_current == this->first_)
				this->push_front(*first);
			else if (pos.ptr_current == this->last_)
				this->push_back(*first);
			else
			{
				node_ *newNode = new node_(*first);

				newNode->next = pos.ptr_current;
				newNode->prev = pos.ptr_current->prev;
				pos.ptr_current->prev->next = newNode;
				pos.ptr_current->prev = newNode;

				++this->size_;
			}
			++first;
		}
	}

	template <typename T>
	template <typename Integer>
	void list<T>::insert_dispatch_(iterator pos, Integer count, Integer value, true_type)
	{
		insert_int_(pos, count, value);
	}

	template <typename T>
	template <typename InputIt>
	void list<T>::insert_dispatch_(iterator pos, InputIt first, InputIt last, false_type)
	{
		insert_iter_(pos, first, last);
	}

	template <typename T>
	void list<T>::insert(iterator pos, size_type count, const_reference value)
	{
		insert_int_(pos, count, value);
	}

	template <typename T>
	template <typename InputIt>
	void list<T>::insert(iterator pos, InputIt first, InputIt last)
	{
		// Check whether it's an integral type. If so, it's not an iterator.
		typedef typename ft::is_integer<InputIt>::type Integral;

		this->insert_dispatch_(pos, first, last, Integral());
	}

	template <class T>
	typename list<T>::iterator list<T>::erase(iterator pos)
	{
		iterator first = pos;
		return (this->erase(first, ++pos));
	}

	template <class T>
	typename list<T>::iterator list<T>::erase(iterator first, iterator last)
	{
		iterator it = first;

		while (this->size_ && it != last)
		{
			++it;
			if (first.ptr_current == this->first_)
				this->pop_front();
			else if (first.ptr_current == this->last_->prev)
				this->pop_back();
			else
			{
				node_ *nextNode = first.ptr_current->next;
				first.ptr_current->prev->next = nextNode;
				nextNode->prev = first.ptr_current->prev;

				delete first.ptr_current;
				--this->size_;
			}
			first = it;
		}

		return first;
	}

	template <class T>
	void list<T>::push_back(const_reference value)
	{
		node_ *newNode = new node_(value);

		if (this->size_ == 0)
		{
			this->first_ = newNode;
			this->first_->next = this->last_;
			this->last_->prev = this->first_;
		}
		else
		{
			newNode->prev = this->last_->prev;
			this->last_->prev->next = newNode;
			newNode->next = this->last_;
			this->last_->prev = newNode;
		}
		this->size_++;
	}

	template <class T>
	void list<T>::pop_back()
	{
		if (this->size_ == 1)
		{
			delete this->first_;
			this->first_ = this->last_;
			this->first_->prev = NULL;
		}
		else
		{
			node_ *lastNode = this->last_->prev;
			this->last_->prev = lastNode->prev;
			lastNode->prev->next = this->last_;
			delete lastNode;
		}
		--this->size_;
	}

	template <class T>
	void list<T>::push_front(const_reference value)
	{
		node_ *newNode = new node_(value);

		newNode->next = this->first_;
		this->first_->prev = newNode;
		this->first_ = newNode;
		++this->size_;
	}

	template <class T>
	void list<T>::pop_front()
	{
		if (this->size_ == 1)
		{
			delete this->first_;
			this->first_ = this->last_;
		}
		else
		{
			node_ *nextNode = this->first_->next;

			delete this->first_;
			this->first_ = nextNode;
		}
		this->first_->prev = NULL;
		--this->size_;
	}

	template <class T>
	void list<T>::resize(size_type count, value_type value)
	{
		if (count < this->size_)
		{
			iterator first = this->begin();
			for (size_type i = 0; i < count; ++i)
				++first;

			this->erase(first, this->end());
		}
		else if (count > this->size_)
			this->insert(this->end(), this->size_ - count, value);
	}

	template <class T>
	void list<T>::swap(list &other)
	{
		if (this != &other)
		{
			ft::swap(this->size_, other.size_);
			ft::swap(this->first_, other.first_);
			ft::swap(this->last_, other.last_);
		}
	}

	template <typename T>
	void list<T>::merge(list &other)
	{
		if (this == &other)
			return;

		this->merge(other, ft::less<T>());
	}

	template <typename T>
	template <class Compare>
	void list<T>::merge(list &other, Compare comp)
	{
		if (this == &other)
			return;

		iterator it = this->begin();
		iterator itOther = other.begin();

		while (itOther != other.end())
		{
			while (it != this->end() && comp(*it, *itOther))
				++it;

			iterator newIt = itOther;
			++itOther;

			if (it.ptr_current->prev)
				it.ptr_current->prev->next = newIt.ptr_current;
			else
				this->first_ = newIt.ptr_current;

			newIt.ptr_current->prev = it.ptr_current->prev;
			newIt.ptr_current->next = it.ptr_current;
			it.ptr_current->prev = newIt.ptr_current;
		}

		this->size_ += other.size();
		other.size_ = 0;

		other.first_ = other.last_;
		other.first_->prev = NULL;
	}

	template <typename T>
	void list<T>::splice(iterator pos, list &other)
	{
		if (!other.empty())
			this->splice(pos, other, other.begin(), other.end());
	}

	template <typename T>
	void list<T>::splice(iterator pos, list &other, iterator it)
	{
		const_iterator nextIt = it.ptr_current->next;
		this->splice(pos, other, it, nextIt);
	}

	template <typename T>
	void list<T>::splice(iterator pos, list &other, iterator first, iterator last)
	{
		while (first != last)
		{
			iterator nextIt = first.ptr_current->next;
			if (first.ptr_current == other.first_)
			{
				other.first_ = first.ptr_current->next;
				other.first_->prev = NULL;
			}
			else if (first == other.end())
				other.last_->prev->prev->next = other.last_;

			if (pos.ptr_current == this->first_)
			{
				first.ptr_current->next = this->first_;
				first.ptr_current->prev = NULL;
				this->first_->prev = first.ptr_current;
				this->first_ = first.ptr_current;
			}
			else if (pos == this->end())
			{
				if (this->size_ == 0)
				{
					first.ptr_current->prev = NULL;
					this->first_ = first.ptr_current;
					this->first_->next = this->last_;
					this->last_->prev = this->first_;
				}
				else
				{
					first.ptr_current->prev = this->last_->prev;
					this->last_->prev->next = first.ptr_current;
					first.ptr_current->next = this->last_;
					this->last_->prev = first.ptr_current;
				}
			}
			else
			{
				first.ptr_current->next = pos.ptr_current;
				first.ptr_current->prev = pos.ptr_current->prev;
				pos.ptr_current->prev->next = first.ptr_current;
				pos.ptr_current->prev = first.ptr_current;
			}

			++this->size_;
			--other.size_;

			first = nextIt;
		}
	}

	template <typename T>
	void list<T>::remove(const T &value)
	{
		iterator it = this->begin();

		while (it != this->end())
		{
			if (*it == value)
				it = erase(it);
			else
				++it;
		}
	}

	template <typename T>
	template <class UnaryPredicate>
	void list<T>::remove_if(UnaryPredicate predicate)
	{
		iterator it = this->begin();

		while (it != this->end())
		{
			if (predicate(*it))
				it = erase(it);
			else
				++it;
		}
	}

	template <typename T>
	void list<T>::reverse()
	{
		iterator it = this->begin();
		iterator itNewLast = this->begin();

		while (true)
		{
			iterator itSwap = it;
			++it;
			if (itSwap.ptr_current->next != this->last_)
				ft::swap(itSwap.ptr_current->next, itSwap.ptr_current->prev);
			else
			{
				itSwap.ptr_current->next = itSwap.ptr_current->prev;
				itSwap.ptr_current->prev = NULL;
				this->first_ = itSwap.ptr_current;
				break;
			}
		}
		this->last_->prev = itNewLast.ptr_current;
		itNewLast.ptr_current->next = this->last_;
	}

	template <typename T>
	void list<T>::unique()
	{
		this->unique(ft::equal_to<value_type>());
	}

	template <typename T>
	template <class BinaryPredicate>
	void list<T>::unique(BinaryPredicate predicate)
	{
		if (this->size_ < 2)
			return;

		iterator it = this->begin();
		iterator itNext = it.ptr_current->next;

		while (itNext != this->end())
		{
			if (predicate(*it, *itNext))
				itNext = erase(itNext);
			else
			{
				++it;
				++itNext;
			}
		}
	}

	template <typename T>
	void list<T>::sort()
	{
		if (this->size_ < 2)
			return;

		this->sort(ft::less<value_type>());
	}

	template <typename T>
	template <class Compare>
	void list<T>::sort(Compare comp)
	{
		if (this->size_ < 2)
			return;

		for (size_type i = 0; i < this->size_; ++i)
		{
			iterator it = this->begin();
			iterator itNext = it.ptr_current->next;

			while (itNext != this->end())
			{
				if (!comp(*it, *itNext))
				{
					node_ *prevNode = it.ptr_current->prev;
					node_ *nextNode = itNext.ptr_current->next;

					if (prevNode)
						prevNode->next = itNext.ptr_current;
					else
						this->first_ = itNext.ptr_current;

					nextNode->prev = it.ptr_current;

					itNext.ptr_current->prev = prevNode;
					itNext.ptr_current->next = it.ptr_current;
					it.ptr_current->prev = itNext.ptr_current;
					it.ptr_current->next = nextNode;

					it = itNext.ptr_current;
				}
				++it;
				itNext = it.ptr_current->next;
			}
		}
	}

	//=========================

	template <class T>
	bool operator==(const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename list<T>::const_iterator first1 = lhs.begin();
		typename list<T>::const_iterator last1 = lhs.end();
		typename list<T>::const_iterator first2 = rhs.begin();
		typename list<T>::const_iterator last2 = rhs.end();

		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class T>
	bool operator!=(const list<T> &lhs, const list<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T>
	bool operator<(const list<T> &lhs, const list<T> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T>
	bool operator<=(const list<T> &lhs, const list<T> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T>
	bool operator>(const list<T> &lhs, const list<T> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool operator>=(const list<T> &lhs, const list<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T>
	void swap(list<T> &lhs, list<T> &rhs)
	{
		lhs.swap(rhs);
	}
} // namespace ft

#endif