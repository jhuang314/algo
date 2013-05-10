#include <iostream>
#include <cstdlib>

using namespace std;
typedef unsigned long long ull;

bool isPrime(ull x)
{
     if (x < 2)
          return false;
     ull d = x - 1;
     ull s = 0;
     ull a;
     
     // express x -1 as 2^s * d
     while (d % 2 == 0)
     {
          d /= 2;
          s++;
     }
     for (int k = 0; k < 100; k++)
     {
          a = rand() % (x - 4) + 2;
          
     }

}

unsigned powmod(ull a, ull b, ull n)

int main()
{
//     isPrime(9);
     return 0;
}
