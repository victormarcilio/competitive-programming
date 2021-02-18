#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
	cin >> x >> y;
	if(y/2 - x <= 0)
		cout << "Amelia tem todas bolinhas!\n";
	else
		cout << "Faltam " <<  y/2 - x << " bolinha(s)\n";
}