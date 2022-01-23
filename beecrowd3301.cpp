#include <bits/stdc++.h>
using namespace std;

struct Duck {
    string name;
    int age;

    bool operator < (const Duck& other) const {
        return age < other.age;
    }
};

int main() {
    Duck ducks[3] = {{"huguinho", 0}, {"zezinho", 0}, {"luisinho", 0}};
    cin >> ducks[0].age >> ducks[1].age >> ducks[2].age;
    sort(ducks, ducks + 3);
    cout << ducks[1].name << '\n';
}