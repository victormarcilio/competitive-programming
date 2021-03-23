#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 1;
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == s[i - 1])
			count++;
		else
			count = 1;
		if(count == 6)
		{
			cout << "Sorry, sorry!\n";
			return 0;
		}
	}	
	cout << "Good luck!\n";
}
