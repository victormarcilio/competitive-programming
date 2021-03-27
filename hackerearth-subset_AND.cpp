//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/subset-and-4/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int x, n, z;
       cin >> z >> n;
       for(int i = 0; i < n; i++)
       {
           cin >> x;
           z &= x;
       }
       cout << (!z? "Yes\n" : "No\n");
    }
}
