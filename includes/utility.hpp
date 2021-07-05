#ifndef UTILITY_HPP
#define UTILITY_HPP

#ifndef UNDERLINE_W
#define UNDERLINE_W "\e[4;37m"
#endif
#ifndef RED_C
#define RED_C "\e[0;31m"
#endif
#ifndef GREEN_C
#define GREEN_C "\e[0;32m"
#endif
#ifndef YELLOW_C
#define YELLOW_C "\e[0;33m"
#endif
#ifndef BLUE_C
#define BLUE_C "\e[0;36m"
#endif
#ifndef PURPLE_C
#define PURPLE_C "\e[0;35m"
#endif
#ifndef RESET_C
#define RESET_C "\e[00m"
#endif

namespace ft
{
	struct true_type
	{
	};
	struct false_type
	{
	};

	// Compare for equality of types.
	template <typename, typename>
	struct are_same
	{
		enum
		{
			value = 0
		};
		typedef false_type type;
	};

	template <typename T>
	struct are_same<T, T>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	//
	// Integer types
	//
	template <typename T>
	struct is_integer
	{
		enum
		{
			value = 0
		};
		typedef false_type type;
	};

	template <>
	struct is_integer<bool>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<char>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<signed char>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<unsigned char>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<short>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<unsigned short>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<int>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<unsigned int>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<long>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<unsigned long>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<long long>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <>
	struct is_integer<unsigned long long>
	{
		enum
		{
			value = 1
		};
		typedef true_type type;
	};

	template <typename T>
	void swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template <typename Arg1, typename Arg2, typename Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <typename T>
	struct greater : public binary_function<T, T, bool>
	{
		bool operator()(const T &lhs, const T &rhs) const
		{
			return lhs > rhs;
		}
	};

	template <typename T>
	struct less : public binary_function<T, T, bool>
	{
		bool operator()(const T &lhs, const T &rhs) const
		{
			return lhs < rhs;
		}
	};

	template <typename T>
	struct equal_to : public binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const
		{
			return x == y;
		}
	};

	template <typename InputIt1, typename InputIt2>
	bool equal(InputIt1 lhs, InputIt1 lhs_end, InputIt2 rhs)
	{
		for (; lhs != lhs_end; ++lhs, (void)++rhs)
			if (!(*lhs == *rhs))
				return false;
		return true;
	}

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(T1()), second(T2()) {}
		pair(const T1 &a, const T2 &b) : first(a), second(b) {}
		template <typename U1, typename U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}
	};

	template <typename T1, typename T2>
	inline pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return ft::pair<T1, T2>(x, y);
	}

	template <typename T1, typename T2>
	inline bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return x.first == y.first && x.second == y.second;
	}

	template <typename T1, typename T2>
	inline bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <typename T1, typename T2>
	inline bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x == y);
	}

	template <typename T1, typename T2>
	inline bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return y < x;
	}

	template <typename T1, typename T2>
	inline bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(y < x);
	}

	template <typename T1, typename T2>
	inline bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x < y);
	}
} // namespace ft

#endif