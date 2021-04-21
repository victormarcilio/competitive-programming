#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    double b, h;
    cin >> b >> h;
    printf("Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = %.5lf.\n", b * h / 2);

}
