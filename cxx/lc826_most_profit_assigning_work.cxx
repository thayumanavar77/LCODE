class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker)
    {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back(make_pair(difficulty[i],profit[i]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int job_idx = 0, max_profit = 0, res = 0;;
        for (int &ability : worker) {
            while (job_idx < n && (ability >= jobs[job_idx].first)) {
                max_profit = max(max_profit, jobs[job_idx++].second);
            }
            res += max_profit;
        }
        return res;
    }
};
