#include <iostream>
#include <cstdlib>

using namespace std;
typedef unsigned long long ull;
unsigned powmod(ull base, ull exponent, ull modulus);
bool isPrime(ull x)
{
	if (x < 2)
		return false;
	ull d = x - 1;
	ull s = 0;
	ull a;
	ull t;

	// express x -1 as 2^s * d
	while (d % 2 == 0)
	{
		d /= 2;
		s++;
	}
	for (int k = 0; k < 100; k++)
	{
		a = rand() % (x - 4) + 2;
		t = powmod(a, d, x);
		if (t == 1 || t == x-1)
			continue;
		for (int l; l < s-1; l++)
		{
			t = powmod(t, 2, x);
			if (t == 1)
				return false;
			if (t == x-1)
				break;
		}
	cout << "hi" << endl;
		if (t == x-1)
			continue;
		return false;
	}
	return true;

}

unsigned powmod(ull base, ull exponent, ull modulus)
{
	ull answer = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			answer = (answer * base) % modulus;
		exponent >>= 1;
		base = (base * base) % modulus;

	}
	return answer;
}

int main()
{
	cout << isPrime(100) << "," << isPrime(97) << endl;
	return 0;
}
