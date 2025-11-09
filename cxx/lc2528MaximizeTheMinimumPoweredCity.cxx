class Solution {
public:
    bool check(vector<int>& stations, int r, int k, long long minPower) {
        int numStations = stations.size();
        vector<int> newPower(numStations, 0);
        long long windowPower = accumulate(stations.begin(),
                                           stations.begin() + r, 0LL);

        for (int i = 0; i < numStations; i++) {
            if (i + r < numStations) {
                windowPower += stations[i+r];
            }
            if (windowPower < minPower) {
                long long needed = minPower - windowPower;
                if (needed > k) return false;
                newPower[min(numStations-1,i+r)] += needed;
                windowPower = minPower;
                k -= needed;

            }

            if (i-r >= 0) {
                windowPower -= stations[i-r] + newPower[i-r];
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        long long hi  = accumulate(stations.begin(),
                                   stations.end(), 0LL) + k;
        long long lo = 0;
        long long minPower = 0;
        while (lo <= hi) {
            long long mid = (lo + hi)/2;
            if (check(stations, r, k , mid)) {
                minPower = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return minPower;
    }
};
