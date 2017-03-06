// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.


void problem2()
{

	long sum = ranges::accumulate(
		fibonacci()
		| take_while([](auto i) { return i < 4000000; })
		| evens<long>, 0);
	std::cout << "Problem #2: " << sum << '\n';
}

void problem2_old()
{
	long prev2 = 1;
	long prev1 = 1;
	long curr = prev2 + prev1;

	long sum = 0;
	while (curr < 4000000)
	{
		if (is_even(curr))
		{
			sum += curr;
		}
		prev2 = prev1;
		prev1 = curr;
		curr = prev2 + prev1;
	}

	std::cout << "Problem #2: " << sum << '\n';
}
