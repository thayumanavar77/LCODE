class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int res = 0;
        int m = tasks.size(), n = workers.size();
        int l = 0, r = min(m, n);
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            multiset<int> availWorkers(workers.end()-mid, workers.end());

            for (int i = mid - 1; i >=0; i--) {
                auto sIter = prev(availWorkers.end());
                if (tasks[i] <= *sIter) {
                    availWorkers.erase(sIter);
                } else {
                    auto sIter = availWorkers.lower_bound(tasks[i] - strength);
                    if (sIter == availWorkers.end())
                        return false;
                    if (p > 0) {
                        availWorkers.erase(sIter);
                        p--;
                    }
                    else return false;
                }
            }
            return true;
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};
