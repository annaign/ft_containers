#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include "MapTree.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "utility.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key> >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef value_type *pointer;
		typedef value_type const *const_pointer;
		typedef value_type &reference;
		typedef value_type const &const_reference;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

		class value_compare : public ft::binary_function<value_type, value_type, bool>
		{
		protected:
			key_compare comp;

			value_compare(key_compare comp) : comp(comp) {}

		public:
			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return comp(lhs.first, rhs.first);
			}

			template <class Key_, class T_, class Compare_>
			friend class ft::map;
		};

	public:
		typedef typename MapTree<value_type, value_compare>::iterator iterator;
		typedef typename MapTree<value_type, value_compare>::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		MapTree<value_type, value_compare> tree_;

	public:
		explicit map(const key_compare &comp = key_compare());
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare());
		map(const map &src);
		virtual ~map();

		map &operator=(const map &rhs);

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

		mapped_type &operator[](const key_type &k);

		pair<iterator, bool> insert(const value_type &val);
		iterator insert(iterator position, const value_type &val);
		template <class InputIt>
		void insert(InputIt first, InputIt last);
		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);
		void swap(map &x);
		void clear();

		key_compare key_comp() const;
		value_compare value_comp() const;

		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
		size_type count(const key_type &k) const;
		iterator lower_bound(const key_type &k);
		const_iterator lower_bound(const key_type &k) const;
		iterator upper_bound(const key_type &k);
		const_iterator upper_bound(const key_type &k) const;
		pair<iterator, iterator> equal_range(const key_type &k);
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
	};

	template <class Key, class T, class Compare>
	map<Key, T, Compare>::map(const key_compare &comp)
		: tree_(value_compare(comp))
	{
	}

	template <class Key, class T, class Compare>
	template <class InputIterator>
	map<Key, T, Compare>::map(InputIterator first, InputIterator last, const key_compare &comp)
		: tree_(first, last, value_compare(comp))
	{
	}

	template <class Key, class T, class Compare>
	map<Key, T, Compare>::map(const map &src)
		: tree_(src.tree_)
	{
	}

	template <class Key, class T, class Compare>
	map<Key, T, Compare>::~map()
	{
	}

	template <class Key, class T, class Compare>
	map<Key, T, Compare> &map<Key, T, Compare>::operator=(const map &rhs)
	{
		if (this != &rhs)
		{
			this->tree_ = rhs.tree_;
		}
		return *this;
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::begin()
	{
		return this->tree_.begin();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::begin() const
	{
		return this->tree_.begin();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::end()
	{
		return this->tree_.end();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::end() const
	{
		return this->tree_.end();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::reverse_iterator map<Key, T, Compare>::rbegin()
	{
		return this->tree_.rbegin();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_reverse_iterator map<Key, T, Compare>::rbegin() const
	{
		return this->tree_.rbegin();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::reverse_iterator map<Key, T, Compare>::rend()
	{
		return this->tree_.rend();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_reverse_iterator map<Key, T, Compare>::rend() const
	{
		return this->tree_.rend();
	}

	template <class Key, class T, class Compare>
	bool map<Key, T, Compare>::empty() const
	{
		return this->tree_.empty();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::size() const
	{
		return this->tree_.size();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::max_size() const
	{
		return this->tree_.max_size();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::mapped_type &map<Key, T, Compare>::operator[](const key_type &key)
	{
		ft::pair<iterator, bool> pair = this->insert(ft::make_pair(key, mapped_type()));

		return pair.first->second;

		// iterator it = this->lower_bound(key);
		// // it->first is greater than or equivalent to key.
		// if (it == this->end() || this->key_comp()(key, (*it).first))
		// 	it = this->insert(it, value_type(key, mapped_type()));

		// return (*it).second;
	}

	template <class Key, class T, class Compare>
	pair<typename map<Key, T, Compare>::iterator, bool> map<Key, T, Compare>::insert(const value_type &val)
	{
		return this->tree_.insert_unique(val);
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::insert(iterator position, const value_type &val)
	{
		return this->tree_.insert_unique(position, val).first;
	}

	template <class Key, class T, class Compare>
	template <class InputIt>
	void map<Key, T, Compare>::insert(InputIt first, InputIt last)
	{
		this->tree_.insert_unique(first, last);
	}

	template <class Key, class T, class Compare>
	void map<Key, T, Compare>::erase(iterator position)
	{
		this->tree_.erase(position);
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::erase(const key_type &key)
	{
		iterator it = this->find(key);
		if (it == this->end())
			return 0;

		this->tree_.erase(it);
		return 1;
	}

	template <class Key, class T, class Compare>
	void map<Key, T, Compare>::erase(iterator first, iterator last)
	{
		this->tree_.erase(first, last);
	}

	template <class Key, class T, class Compare>
	void map<Key, T, Compare>::swap(map &rhs)
	{
		ft::swap(this->tree_, rhs.tree_);
	}

	template <class Key, class T, class Compare>
	void map<Key, T, Compare>::clear()
	{
		this->tree_.clear();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::key_compare map<Key, T, Compare>::key_comp() const
	{
		return this->tree_.comp().comp;
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::value_compare map<Key, T, Compare>::value_comp() const
	{
		return this->tree_.comp();
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::find(const key_type &k)
	{
		return this->tree_.find(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::find(const key_type &k) const
	{
		return this->tree_.find(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::size_type map<Key, T, Compare>::count(const key_type &k) const
	{
		return (this->find(k) == this->end()) ? 0 : 1;
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::lower_bound(const key_type &k)
	{
		return this->tree_.lower_bound(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::lower_bound(const key_type &k) const
	{
		return this->tree_.lower_bound(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::iterator map<Key, T, Compare>::upper_bound(const key_type &k)
	{
		return this->tree_.upper_bound(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	typename map<Key, T, Compare>::const_iterator map<Key, T, Compare>::upper_bound(const key_type &k) const
	{
		return this->tree_.upper_bound(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare>
	pair<typename map<Key, T, Compare>::iterator, typename map<Key, T, Compare>::iterator>
	map<Key, T, Compare>::equal_range(const key_type &k)
	{
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}

	template <class Key, class T, class Compare>
	pair<typename map<Key, T, Compare>::const_iterator, typename map<Key, T, Compare>::const_iterator>
	map<Key, T, Compare>::equal_range(const key_type &k) const
	{
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}

	//=========================

	template <class Key, class T, class Compare>
	bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare>
	bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare>
	bool operator<(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare>
	bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare>
	bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare>
	bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare>
	void swap(map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
	{
		lhs.swap(rhs);
	}
} // namespace ft

#endif