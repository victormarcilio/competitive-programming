//https://www.beecrowd.com.br/judge/pt/problems/view/3300
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    char s[1000];
    scanf("%s", s);
    printf("%s %ses de Mala Suerte\n", s, strstr(s, "13") ? "" : "NO ");
 
    return 0;
}
