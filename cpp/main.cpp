#include <iostream>
#include <vector>

#include <range/v3/all.hpp>

#include "math.hpp"

namespace projecteuler {
using std::vector;
using namespace ranges::view;

template <class T>
bool is_even(const T& i)
{
	return i % 2 == 0;
}

template <class T>
bool is_odd(const T& i)
{
	return i % 2 == 1;
}

// return the ith prime, with prime(0) = 2
long prime(int i)
{
	// memoize the primes
	static vector<long> primes{2, 3, 5, 7, 11, 13, 17};
	if (i >= primes.size())
	{
		// memoize up to the ith prime.
		for (long p = primes.back() + 2; primes.size() <= i; p += 2)
		{
			if (!ranges::any_of(primes, [=](int i){ return p % i == 0; }))
			{
				primes.push_back(p);
			}
		}
	}

	return primes[i];
}



namespace generator
{
using ranges::view::generate;

auto fibonacci()
{
	long prev2 = 0;
	long prev1 = 1;
	return generate([=]() mutable
	{
		long curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
		return curr;
	});
}

auto primes()
{
	int curr = 0;
	return generate([=]() mutable
	{
		return prime(curr++);
	});
}

// generate all the prime factors of c. Duplicates will be output
// if c is divisible by a particular prime factor multiple times.
class prime_factors : public ranges::view_facade<prime_factors>
{
	friend ranges::range_access;
	long _product;
	long _current_prime;
	long _limit;
	using primes_t = decltype(primes().begin());
	primes_t _primes = primes().begin();

	long const& read() const { return _current_prime; }
	bool done() const { return _current_prime == 0; }
	void next()
	{
		while (_current_prime <= _limit) {
			while (_product % _current_prime == 0) {
				_product /= _current_prime;
				_limit = math::isqrt(_product);
				return;
			}
			_current_prime = *++_primes;
		}

		// remaining prime factor is in _product
		_current_prime = _product;
		_product = 0; // next call to next() will mark the sequence done
	}

public:
	prime_factors() : _current_prime(0) {};
	explicit prime_factors(long product)
		: _product(product)
		, _current_prime(product < 2 ? 0 : 2)
		, _limit(math::isqrt(product)) {}
};

// auto ints(int start, int end, int stride)
// {
//	return ranges::view::ints(start, end) | ranges::view::stride(stride);
// }

} // namespace generator

namespace view
{
template <class T>
auto evens = ranges::view::filter(is_even<T>);

template <class T>
auto odds = ranges::view::filter(is_odd<T>);

} // namespace view

} // namespace projecteuler


using namespace ranges::view;
using namespace projecteuler;
using namespace projecteuler::generator;
using namespace projecteuler::view;

#include "problem-001.hpp"
#include "problem-002.hpp"
#include "problem-003.hpp"

namespace projecteuler {

void main()
{
	problem1();
	problem2();
	problem3();
}

} // namespace projecteuler

int main()
{
	projecteuler::main();

	return 0;
}
