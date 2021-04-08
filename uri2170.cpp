//https://www.urionlinejudge.com.br/judge/pt/problems/view/2170
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int ind = 1;
    double x, y;
    while (cin >> x >> y)
        cout << "Projeto " << ind++ << ":\nPercentual dos juros da aplicacao: " << fixed << setprecision(2) << (y / x - 1) * 100 << " %\n\n";

    return 0;
}
