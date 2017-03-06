// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

void problem3()
{
	long dividend = 600851475143;

	while (dividend > 1)
	{
		auto prime_factors = primes() | take_while([=](long p){ return p < dividend/2; });
		auto it = ranges::find_if(
			prime_factors,
			[=](long p) { return dividend % p == 0; });
		if (it == prime_factors.end()) break;

		dividend /= *it;
	}

	// what remains in dividend after the above loop is the largest prime.
	std::cout << "Problem #3: " << dividend << '\n';
}