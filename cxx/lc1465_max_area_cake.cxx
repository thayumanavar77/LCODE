class Solution {
private:
    const long long int MOD = 1000000007;
public:
    int maxArea(int h, int w,
                vector<int>& hCuts,
                vector<int>& vCuts)
    {
        hCuts.push_back(h);
        vCuts.push_back(w);
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());

        int maxH = hCuts[0];
        for (int i = 1; i < hCuts.size(); i++) {
            maxH = max(maxH,hCuts[i] - hCuts[i-1]);
        }

        int maxV = vCuts[0];

        for (int i = 1; i < vCuts.size(); i++) {
            maxV = max(maxV, vCuts[i] - vCuts[i-1]);
        }
        return (1LL*maxH*maxV)%MOD;
    }
};
