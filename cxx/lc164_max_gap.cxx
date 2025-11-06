class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int N= nums.size();

        int mine = *min_element(nums.begin(), nums.end());
        int maxe = *max_element(nums.begin(), nums.end());

        if (mine == maxe) return 0;
        int max_gap = max((maxe - mine)/(N-1),1);
        int nb = ((maxe - mine)/ max_gap) + 1;
        vector<int> bucket_min(nb, INT_MAX);
        vector<int> bucket_max(nb, INT_MIN);
        for (int i = 0; i < N; i++) {
            int idx = (nums[i] - mine)/ max_gap;
            bucket_min[idx] = min(bucket_min[idx], nums[i]);
            bucket_max[idx] = max(bucket_max[idx], nums[i]);
        }

        int prev =  bucket_max[0];

        for (int i = 0; i < nb; i++) {
            if (bucket_min[i] == INT_MAX) continue;
            max_gap = max(max_gap, bucket_min[i]- prev);
            prev = bucket_max[i];
        }
        return max_gap;
    }
};
