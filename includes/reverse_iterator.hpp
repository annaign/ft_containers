#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
	template <typename Iterator>
	class reverse_iterator : public Iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef ptrdiff_t difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::const_pointer const_pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::const_reference const_reference;
		typedef typename Iterator::value_type value_type;

	public:
		reverse_iterator() : Iterator() {}
		explicit reverse_iterator(iterator_type it) : Iterator(it) {}
		reverse_iterator(const reverse_iterator &src) : Iterator(src.ptr_current) {}
		virtual ~reverse_iterator() {}

		reverse_iterator &operator=(reverse_iterator const &rhs)
		{
			this->ptr_current = rhs.ptr_current;
			return *this;
		}

		reference operator*()
		{
			Iterator tmp(this->ptr_current);
			return *--tmp;
		}

		const_reference operator*() const
		{
			Iterator tmp(this->ptr_current);
			return *--tmp;
		}

		pointer operator->()
		{
			Iterator tmp(this->ptr_current);
			--tmp;
			// return &*tmp;
			return tmp.operator->();
		}

		const_pointer operator->() const
		{
			Iterator tmp(this->ptr_current);
			--tmp;
			return &*tmp;
		}

		reverse_iterator &operator++()
		{
			this->Iterator::operator--();
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--this->ptr_current;
			return tmp;
		}

		reverse_iterator &operator--()
		{
			this->Iterator::operator++();
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++this->ptr_current;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(this->ptr_current - n);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			this->ptr_current -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(this->ptr_current + n);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			this->ptr_current += n;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
	};
} // namespace ft

#endif