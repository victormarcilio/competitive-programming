//https://codeforces.com/group/nituVTsHQX/contest/339649/problem/E
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n, q, d, t;
	cin >> n >> q >> d >> t;
	
	map<int, int> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		m[x]++;
	}
		
	while(1){
		int T = t, D = d, dm = 0;
		for(auto k = m.rbegin(); k != m.rend(); k++){
			int qt = k->second;
			if(T && qt){
				int v = min(T, qt);
				dm += v * 3 * k->first;
				T -= v;
				qt -= v;
			}
			if(D && qt){
				int v = min(D, qt);
				dm += v * 2 * k->first;
				D -= v;
				qt -= v;
			}
			if(qt)
				dm += qt * k->first;
		}
		cout << dm << '\n';
		if(!q--)
			break;
		char c, s;
		cin >> c >> s;
		if(c == '1'){
			int x;
			cin >> x;
			if(s == '+')
				m[x] += 1;
			else
				m[x] -= 1;
		}else if(c == '2'){
			if(s == '+')
				d++;
			else
				d--;
		}else if(s == '+')
			t++;
		else
			t--;
	}
}