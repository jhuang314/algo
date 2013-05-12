#include <iostream>
#include <cstdlib>

using namespace std;
typedef unsigned long long ull;

unsigned powmod(ull base, ull exponent, ull modulus);
bool isPrime(ull n);


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
     return 0;
}
