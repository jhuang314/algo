#ifndef NUMBERS_H
#define NUMBERS_H
#include <vector>

typedef unsigned long long ull;
using namespace std;

ull powmod(ull base, ull exponent, ull modulus);
ull ullPow(ull x, ull p);
ull gcd(ull a, ull b);
ull lcm(ull a, ull b);
bool isPrime(ull n);
ull numDigits(ull a);
vector<ull> sieve(ull limit);

#endif
