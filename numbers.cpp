#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "numbers.h"

using namespace std;

// returns true if n is prime, false otherwise
bool isPrime(ull n)
{
     // write n-1 as 2^s * d
     ull d = n - 1, s = 0, a, x;
     
     // check if n is even (duh)
     if (n == 2)
          return true;
     if (n % 2 == 0)
          return true;
     if (n == 0 || n == 1)
          return false;
     
     while (d % 2 == 0)
     {
          d /= 2;
          s++;
     }
     
     for (int k = 0; k < 100; k++)
     {
          // witness a is chosen between 2 and n-2
          a = rand() % (n - 4) + 2;
          x = powmod(a, d, n);
          if (x == 1 || x == (n-1))
               continue;
          for (int l = 0; l < s-1 && x != (n-1); l++)
          {
               x = powmod(x, 2, n);
               if (x == 1)
                    return false;
               
          }
          if (x != n-1)
               return false;
     }
     return true;
     
}

// returns (baes ^ exponent) mod modulus
ull powmod(ull base, ull exponent, ull modulus)
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

// returns x^p
ull ullPow(ull x, ull p)
{
     if (p == 0) return 1;
     if (p == 1) return x;
     
     ull tmp = ullPow(x, p/2);
     if (p%2 == 0) return tmp * tmp;
     else return x * tmp * tmp;
}


// returns the greatest common divisor of a and b
ull gcd(ull a, ull b)
{
     if (a < b)
          return gcd(b, a);
     else if (a % b == 0)
          return b;
     else 
          return gcd(b, a % b);
}

// returns he least common multiple of a and b
ull lcm(ull a, ull b)
{
     ull g = gcd(a, b);
     return (a / g) * b;
}

// returns the number of digits of a
ull numDigits(ull a)
{
     if (a == 0)
          return 1;
     ull digits = 0;
     while (a > 0)
     {
          a /= 10;
          digits++;
     }
     return digits;
}

// returns a list of primes
vector<ull> sieve(ull limit)
{
     vector<ull> primes(limit);
     vector<bool> sieve(limit, true);
     ull index = 0;
     
     for (ull i = 2; i < limit; i++)
     {
          if (sieve.at(i))
          {
               primes.at(index++) = i;
               
               for (ull j = i*i; j < limit; j += i)
               {
                    sieve.at(j) = false;
               }
          }
     }
     
     primes.resize(index);

     return primes;
}

// int main()
// {
//      cout << lcm(18, 12) << endl;
//      return 0;
// }
