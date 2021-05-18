//https://app.codesignal.com/company-challenges/uber/HNQwGHfKAoYsz9KX6
vector<double> fareEstimator(int ride_time, int ride_distance, vector<double> cost_per_minute, vector<double> cost_per_mile) {
    for(int i = 0; i < cost_per_minute.size(); i++)
        cost_per_minute[i] = cost_per_minute[i] * ride_time + cost_per_mile[i] * ride_distance;
    return cost_per_minute;
}
