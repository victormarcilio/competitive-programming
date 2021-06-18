//https://app.codesignal.com/company-challenges/instacart/buphhQWwuZQ7hDTwr
double shoppingList(string items) {
    smatch sm;
    regex e("\\d+(\\.\\d+)?");
    sregex_iterator it(items.begin(), items.end(), e);
    double total = 0;
    sregex_iterator end = sregex_iterator();
    while(it != end)
    {
        total += stod(it->str());
        it++;
    }
    return total;
}
