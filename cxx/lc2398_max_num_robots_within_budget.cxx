class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts, long long budget)
    {
        long long numRobots = chargeTimes.size(), sum = 0, j = 0, maxc;
        multiset<int> s;
        for (int i = 0; i < numRobots;i++) {
            sum += runningCosts[i];
            s.insert(chargeTimes[i]);
            if (*rbegin(s) + sum * (i - j + 1) > budget) {
                sum -= runningCosts[j];
                s.erase(s.find(chargeTimes[j++]));
            }
        }
        return numRobots - j;
    }
};
