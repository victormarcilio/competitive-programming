#include <bits/stdc++.h>
using namespace std;

double f(int n, int k)
{
	double res = 1.0;
	
	for(int i = n; i > max(k, n - k); i--)
		res *= i;
	for(int i = 1; i <= min(k, n - k); i++)
		res /= i; 
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, k, x;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n >> k >> x;	
		cout << "A chance de Basy acertar o numero no dia " << i <<
		" eh "<< fixed << setprecision(2) << 
		100*f(n, k)*pow(x/100., k)*pow(1 - x/100.,n - k)
		<< "%\n";
	}
}
