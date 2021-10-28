#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <deque>
#include <bitset>
#include<numeric>
#include<queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    double n1, n2;
    cin >> n1 >> n2;
    printf("%.6f\n", (100 + n1) * (100 + n2) / 100 - 100);
}
