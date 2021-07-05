#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstddef>
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utility.hpp"

namespace ft
{
	template <typename T>
	class VectorIterator
	{
	public:
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T value_type;

	protected:
		pointer ptr_current;

	public:
		VectorIterator() : ptr_current(NULL) {}
		VectorIterator(pointer ptr) : ptr_current(ptr) {}
		VectorIterator(VectorIterator const &src) : ptr_current(src.ptr_current) {}
		virtual ~VectorIterator() {}

		VectorIterator &operator=(VectorIterator const &rhs)
		{
			this->ptr_current = rhs.ptr_current;
			return *this;
		}

		// Forward iterator requirements
		reference operator*()
		{
			return *this->ptr_current;
		}

		const_reference operator*() const
		{
			return *this->ptr_current;
		}

		pointer operator->()
		{
			return this->ptr_current;
		}

		const_pointer operator->() const
		{
			return this->ptr_current;
		}

		VectorIterator &operator++()
		{
			++this->ptr_current;
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator it = *this;
			operator++();

			return it;
		}

		// Bidirectional iterator requirements
		VectorIterator &operator--()
		{
			--this->ptr_current;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator it = *this;
			operator--();

			return it;
		}

		// Random access iterator requirements
		reference operator[](difference_type n)
		{
			return this->ptr_current[n];
		}

		const_reference operator[](difference_type n) const
		{
			return this->ptr_current[n];
		}

		VectorIterator &operator+=(difference_type n)
		{
			this->ptr_current += n;
			return *this;
		}

		VectorIterator operator+(difference_type n) const
		{
			return VectorIterator(this->ptr_current + n);
		}

		VectorIterator &operator-=(difference_type n)
		{
			this->ptr_current -= n;
			return *this;
		}

		VectorIterator operator-(difference_type n) const
		{
			return VectorIterator(this->ptr_current - n);
		}

		// Forward iterator requirements
		bool operator==(const VectorIterator &rhs) const
		{
			return this->ptr_current == rhs.ptr_current;
		}

		bool operator!=(const VectorIterator &rhs) const
		{
			return this->ptr_current != rhs.ptr_current;
		}

		// Random access iterator requirements
		bool operator<(const VectorIterator &rhs) const
		{
			return this->ptr_current < rhs.ptr_current;
		}

		bool operator>(const VectorIterator &rhs) const
		{
			return this->ptr_current > rhs.ptr_current;
		}

		bool operator<=(const VectorIterator &rhs) const
		{
			return this->ptr_current <= rhs.ptr_current;
		}

		bool operator>=(const VectorIterator &rhs) const
		{
			return this->ptr_current >= rhs.ptr_current;
		}

		difference_type operator-(const VectorIterator &rhs) const
		{
			return this->ptr_current - rhs.ptr_current;
		}
	};

	template <typename T>
	class vector
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T const &const_reference;
		typedef T *pointer;
		typedef T const *const_pointer;
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator<value_type const> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		value_type *data_;
		size_type size_;
		size_type capacity_;

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
		vector();
		explicit vector(size_type count, const_reference value = value_type());
		template <class InputIt>
		vector(InputIt first, InputIt last);
		vector(const vector &src);
		virtual ~vector();

		vector &operator=(vector const &rhs);

		reference at(size_type pos) throw(std::out_of_range);
		const_reference at(size_type pos) const throw(std::out_of_range);
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		void assign(size_type count, const_reference value);
		template <typename InputIt>
		void assign(InputIt first, InputIt last);

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
		void reserve(size_type size) throw(std::length_error);
		size_type capacity() const;

		void clear();

		iterator insert(iterator pos, const_reference value);
		void insert(iterator pos, size_type count, const_reference value);
		template <typename InputIt>
		void insert(iterator pos, InputIt first, InputIt last);
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void push_back(const_reference value);
		void pop_back();
		void resize(size_type count, value_type value = value_type());
		void swap(vector &other);
	};

	template <typename T>
	vector<T>::vector() : data_(NULL), size_(0), capacity_(0)
	{
	}

	template <typename T>
	vector<T>::vector(size_type count, const_reference value)
		: data_(NULL), size_(0), capacity_(0)
	{
		this->assign(count, value);
	}

	template <typename T>
	template <class InputIt>
	vector<T>::vector(InputIt first, InputIt last)
		: data_(NULL), size_(0), capacity_(0)
	{
		this->assign(first, last);
	}

	template <typename T>
	vector<T>::vector(const vector &src)
		: data_(NULL), size_(0), capacity_(0)
	{
		if (src.capacity() != 0)
			this->data_ = static_cast<pointer>(::operator new(sizeof(value_type) * src.capacity()));
		this->capacity_ = src.capacity();

		for (size_type i = 0; i < src.size(); i++)
			new (&this->data_[i]) value_type(src.data_[i]);
		this->size_ = src.size();
	}

	template <typename T>
	vector<T>::~vector()
	{
		this->clear();
		::operator delete(this->data_);
	}

	template <typename T>
	vector<T> &vector<T>::operator=(vector const &rhs)
	{
		if (this != &rhs)
		{
			this->clear();
			if (this->capacity_ < rhs.capacity())
				this->reserve(rhs.capacity());

			for (size_type i = 0; i < rhs.size(); i++)
				new (&this->data_[i]) value_type(rhs.data_[i]);
			this->size_ = rhs.size();
		}

		return *this;
	}

	template <typename T>
	typename vector<T>::reference vector<T>::at(size_type pos) throw(std::out_of_range)
	{
		if (!(pos < this->size_))
			throw std::out_of_range("ft::vector out of range error");
		return this->data_[pos];
	}

	template <typename T>
	typename vector<T>::const_reference vector<T>::at(size_type pos) const throw(std::out_of_range)
	{
		if (!(pos < this->size_))
			throw std::out_of_range("ft::vector out of range error");
		return this->data_[pos];
	}

	template <typename T>
	typename vector<T>::reference vector<T>::operator[](size_type pos)
	{
		return this->data_[pos];
	}

	template <typename T>
	typename vector<T>::const_reference vector<T>::operator[](size_type pos) const
	{
		return this->data_[pos];
	}

	template <typename T>
	typename vector<T>::reference vector<T>::front()
	{
		return this->data_[0];
	}

	template <typename T>
	typename vector<T>::const_reference vector<T>::front() const
	{
		return this->data_[0];
	}

	template <typename T>
	typename vector<T>::reference vector<T>::back()
	{
		return this->data_[this->size_ - 1];
	}

	template <typename T>
	typename vector<T>::const_reference vector<T>::back() const
	{
		return this->data_[this->size_ - 1];
	}

	template <typename T>
	void vector<T>::assign_int_(size_type count, const_reference value)
	{
		this->clear();

		if (count > this->capacity_)
			this->reserve(count);

		for (size_type i = 0; i < count; i++)
			new (&this->data_[i]) value_type(value);
		this->size_ = count;
	}

	template <typename T>
	template <class InputIt>
	void vector<T>::assign_iter_(InputIt first, InputIt last)
	{
		this->clear();

		size_type size = last - first;

		if (this->capacity_ < size)
			this->reserve(size);

		for (; this->size_ < size; ++this->size_)
		{
			new (&this->data_[this->size_]) value_type(*first);
			++first;
		}
	}

	template <typename T>
	template <typename Integer>
	void vector<T>::assign_dispatch_(Integer count, Integer value, true_type)
	{
		assign_int_(count, value);
	}

	template <typename T>
	template <typename InputIt>
	void vector<T>::assign_dispatch_(InputIt first, InputIt last, false_type)
	{
		assign_iter_(first, last);
	}

	template <typename T>
	void vector<T>::assign(size_type count, const_reference value)
	{
		assign_int_(count, value);
	}

	template <typename T>
	template <typename InputIt>
	void vector<T>::assign(InputIt first, InputIt last)
	{
		// Check whether it's an integral type. If so, it's not an iterator.
		typedef typename ft::is_integer<InputIt>::type Integral;

		assign_dispatch_(first, last, Integral());
	}

	template <typename T>
	typename vector<T>::iterator vector<T>::begin()
	{
		return vector<T>::iterator(this->data_);
	}

	template <typename T>
	typename vector<T>::const_iterator vector<T>::begin() const
	{
		return vector<T>::const_iterator(this->data_);
	}

	template <typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return vector<T>::iterator(this->data_ + this->size_);
	}

	template <typename T>
	typename vector<T>::const_iterator vector<T>::end() const
	{
		return vector<T>::const_iterator(this->data_ + this->size_);
	}

	template <typename T>
	typename vector<T>::reverse_iterator vector<T>::rbegin()
	{
		return vector<T>::reverse_iterator(this->end());
	}

	template <typename T>
	typename vector<T>::const_reverse_iterator vector<T>::rbegin() const
	{
		return vector<T>::const_reverse_iterator(this->end());
	}

	template <typename T>
	typename vector<T>::reverse_iterator vector<T>::rend()
	{
		return vector<T>::reverse_iterator(this->begin());
	}

	template <typename T>
	typename vector<T>::const_reverse_iterator vector<T>::rend() const
	{
		return vector<T>::const_reverse_iterator(this->begin());
	}

	template <typename T>
	bool vector<T>::empty() const
	{
		return (this->size_ == 0);
	}

	template <typename T>
	typename vector<T>::size_type vector<T>::size() const
	{
		return this->size_;
	}

	template <typename T>
	typename vector<T>::size_type vector<T>::max_size() const
	{
		// distance(begin(), end()) cannot be greater than PTRDIFF_MAX,
		// and realistically we can't store more than PTRDIFF_MAX/sizeof(T)

		const size_type diffmax = std::numeric_limits<difference_type>::max() / (sizeof(value_type));
		const size_type allocmax = std::numeric_limits<size_type>::max() / sizeof(value_type);
		return (std::min)(diffmax, allocmax);
	}

	template <typename T>
	void vector<T>::reserve(size_type size) throw(std::length_error)
	{
		if (size_ > this->max_size())
			throw std::length_error("ft::vector reserve error");

		if (size > 0 && this->capacity_ < size)
		{
			// https://stackoverflow.com/questions/4576307/c-allocate-memory-without-activating-constructors
			pointer newData = static_cast<pointer>(::operator new(sizeof(value_type) * size));
			for (size_type i = 0; i < this->size_; i++)
				new (&newData[i]) value_type(this->data_[i]);

			::operator delete(this->data_);

			this->data_ = newData;
			this->capacity_ = size;
		}
	}

	template <typename T>
	typename vector<T>::size_type vector<T>::capacity() const
	{
		return this->capacity_;
	}

	template <typename T>
	void vector<T>::clear()
	{
		for (size_type i = 0; i < this->size_; i++)
			this->data_[i].value_type::~value_type();
		this->size_ = 0;
	}

	template <typename T>
	typename vector<T>::iterator vector<T>::insert(iterator pos, const_reference value)
	{
		this->insert(pos, 1, value);
		return pos;
	}

	template <typename T>
	void vector<T>::insert_int_(iterator pos, size_type count, const_reference value)
	{
		if (count == 0)
			return;

		size_type start = 0;
		iterator it = this->begin();
		while (it != pos)
		{
			++it;
			++start;
		}

		this->reserve(this->size_ + count);

		this->size_ += count;
		size_type size = this->size_;

		while (size != start + count)
		{
			--size;
			new (&this->data_[size]) value_type(this->data_[size - count]);
		}

		while (count-- != 0)
			new (&this->data_[start + count]) value_type(value);
	}

	template <typename T>
	template <typename InputIt>
	void vector<T>::insert_iter_(iterator pos, InputIt first, InputIt last)
	{
		size_type start = 0;
		iterator it = this->begin();
		while (it != pos)
		{
			++it;
			++start;
		}

		size_type count = last - first;

		this->reserve(this->size_ + count);

		this->size_ += count;
		size_type size = this->size_;

		while (size != start + count)
		{
			--size;
			new (&this->data_[size]) value_type(this->data_[size - count]);
		}

		while (count-- != 0)
		{
			--last;
			new (&this->data_[start + count]) value_type(*last);
		}
	}

	template <typename T>
	template <typename Integer>
	void vector<T>::insert_dispatch_(iterator pos, Integer count, Integer value, true_type)
	{
		insert_int_(pos, count, value);
	}

	template <typename T>
	template <typename InputIt>
	void vector<T>::insert_dispatch_(iterator pos, InputIt first, InputIt last, false_type)
	{
		insert_iter_(pos, first, last);
	}

	template <typename T>
	void vector<T>::insert(iterator pos, size_type count, const_reference value)
	{
		insert_int_(pos, count, value);
	}

	template <typename T>
	template <typename InputIt>
	void vector<T>::insert(iterator pos, InputIt first, InputIt last)
	{
		// Check whether it's an integral type. If so, it's not an iterator.
		typedef typename ft::is_integer<InputIt>::type Integral;

		this->insert_dispatch_(pos, first, last, Integral());
	}

	template <class T>
	typename vector<T>::iterator vector<T>::erase(iterator pos)
	{
		return (this->erase(pos, pos + 1));
	}

	template <class T>
	typename vector<T>::iterator vector<T>::erase(iterator first, iterator last)
	{
		size_type start = 0;
		iterator it = this->begin();
		while (it != first)
		{
			++it;
			++start;
		}

		size_type count = last - first;
		size_type i = count;
		while (i)
		{
			--i;
			this->data_[start + i].value_type::~value_type();
		}

		it = this->end();
		this->size_ -= count;
		if (last != it)
		{
			while (i != this->size_)
			{
				new (&this->data_[start + i]) value_type(this->data_[start + i + count]);
				++i;
			}
		}

		return first;
	}

	template <class T>
	void vector<T>::push_back(const_reference value)
	{
		if (this->size_ >= this->capacity_)
			this->reserve(this->capacity_ == 0 ? 1 : this->capacity_ * 2);

		new (&this->data_[this->size_++]) value_type(value);
	}

	template <class T>
	void vector<T>::pop_back()
	{
		this->data_[this->size_--].value_type::~value_type();
	}

	template <class T>
	void vector<T>::resize(size_type count, value_type value)
	{
		if (count < this->size_)
		{
			for (size_type i = count; i < this->size_; i++)
				this->data_[i].value_type::~value_type();
			this->size_ = count;
		}
		else if (count > this->size_)
		{
			if (this->capacity_ < count)
				this->reserve(count);

			for (; this->size_ < count; this->size_++)
				new (&this->data_[this->size_]) value_type(value);
			this->size_ = count;
		}
	}

	template <class T>
	void vector<T>::swap(vector &other)
	{
		if (this != &other)
		{
			ft::swap(this->data_, other.data_);
			ft::swap(this->size_, other.size_);
			ft::swap(this->capacity_, other.capacity_);
		}
	}

	//=========================

	template <class T>
	bool operator==(const vector<T> &lhs, const vector<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (typename vector<T>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T>
	bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T>
	bool operator<(const vector<T> &lhs, const vector<T> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T>
	bool operator>(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T>
	void swap(vector<T> &lhs, vector<T> &rhs)
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif