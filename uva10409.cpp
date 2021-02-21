#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char c[100];
	map<pair<int, char>, int> r;
	
	while(scanf("%d\n", &n), n)
	{
		int top = 1, north = 2, west = 3, south = 5, east = 4, bottom = 6;
		while(n--)
		{
			gets(c);
			int TOP = top, NORTH = north, WEST = west, SOUTH = south, EAST = east, BOTTOM = bottom;
			switch(c[0])
			{
				case 'n':
					top = SOUTH;
					south = BOTTOM;
					bottom = NORTH;
					north = TOP;
					break;
				case 's':
					top = NORTH;
					north = BOTTOM;
					bottom = SOUTH;
					south = TOP;
					break;
				case 'w':
					top = EAST;
					east = BOTTOM;
					bottom = WEST;
					west = TOP;
					break;
				default:
					top = WEST;
					west = BOTTOM;
					bottom = EAST;
					east = TOP;
			}
			
		}
		printf("%d\n", top);
	}
    return 0;
}
