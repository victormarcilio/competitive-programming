#include <bits/stdc++.h>

using namespace std;

int main() 
{  
    char c[100];
	map<string, int> m;
	
	m["zero"] = 0; 
	m["one"] = 1; 
	m["two"] = 2;  
	m["three"] = 3; 
	m["four"] = 4; 
	m["five"] = 5; 
	m["six"] = 6; 
	m["seven"] = 7; 
	m["eight"] = 8; 
	m["nine"] = 9;  
	m["ten"] = 10; 
	m["eleven"] = 11; 
	m["twelve"] = 12; 
	m["thirteen"] = 13; 
	m["fourteen"] = 14; 
	m["fifteen"] = 15; 
	m["sixteen"] = 16; 
	m["seventeen"] = 17; 
	m["eighteen"] = 18; 
	m["nineteen"] = 19; 
	m["twenty"] = 20; 
	m["thirty"] = 30; 
	m["forty"] = 40; 
	m["fifty"] = 50; 
	m["sixty"] = 60; 
	m["seventy"] = 70; 
	m["eighty"] = 80; 
	m["ninety"] = 90; 
	m["hundred"] = 100; 
	m["thousand"] = 1000; 
	m["million"] = 1000000; 
	while(gets(c))
	{
		char *p = strtok(c, " ");
		
		if(!strcmp(p, "negative"))
		{
			p = strtok(NULL, " ");
			printf("-");
		}
		int res = 0, temp = 0;
		while(p)
		{
			if(m[p] == 100)
				temp *= 100;
			else if(m[p] > 100)
			{
				temp *= m[p];
				res += temp;
				temp = 0;
			}
			else
				temp += m[p];
			p = strtok(NULL, " ");
		}
		printf("%d\n", res + temp);
	}
  
    return 0; 
} 
