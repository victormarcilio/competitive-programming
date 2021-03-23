//https://www.hackerearth.com/pt-br/problem/algorithm/encoded-strings-3/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for(char c : s)
		sum += c - 'a' + 1;
	cout << (sum % 3 == 0 && (s.back() - 'a' + 1) % 2 == 0 ? "YES" : "NO"); 
}
