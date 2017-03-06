// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.




inline void problem1()
{
	auto threesAndFives = ints(1,1000) | filter([](int i) { return (i % 3 == 0) || (i % 5 == 0); });
	long sum = ranges::accumulate(threesAndFives, 0);
	std::cout << "Problem #1: " << sum << '\n';
}


inline void problem1_old()
{
	long sum = 0;
	for (long i = 1; i < 1000; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			sum += i;
		}
	}

	std::cout << "Problem #1: " << sum << '\n';
}



