//https://app.codesignal.com/company-challenges/uber/4c3qzzQg8Zg9AfLKH
string fancyRide(int l, vector<double> fares) {
    string s[] = {"UberX", "UberXL", "UberPlus", "UberBlack", "UberSUV"}; 
    for(int i = fares.size() - 1; ~i; i--)
        if(l*fares[i] <= 20)
            return s[i];
    
}
