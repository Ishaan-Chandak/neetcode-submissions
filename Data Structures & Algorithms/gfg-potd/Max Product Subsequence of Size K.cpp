/*

DP solution - not the most ideal soluton
but this teaches us how to handle negative values in product question
carry both maxi and mini

calculate maxi and mini both

then at the end return only the maxi stored or mini stored

when arr[index] == +ve
maxi = maxi of previous * value

but when arr[index[ == -ve
it may be possible that 
arr[index] * -ve >> arr[index] * maxi(which may be =Ve), hence imp to carry both maxi and mini
  */


class Solution {
public:

    using ll = long long;
    const ll INF = LLONG_MAX / 4;
    const ll NEG_INF = LLONG_MIN / 4;

    pair<ll,ll> f(int index, int n, vector<int>& arr, int k,
                  vector<vector<pair<ll,ll>>>& dp,
                  vector<vector<bool>>& vis) {

        if (k == 0)
            return {1, 1};

        if (index == n || n - index < k)
            return {NEG_INF, INF};

        if (vis[index][k])
            return dp[index][k];

        vis[index][k] = true;

        // Don't take current element
        auto notTake = f(index + 1, n, arr, k, dp, vis);

        ll maxi = notTake.first;
        ll mini = notTake.second;

        // Take current element
        auto next = f(index + 1, n, arr, k - 1, dp, vis);

        if (next.first != NEG_INF) {
            ll a = 1LL * arr[index] * next.first;
            ll b = 1LL * arr[index] * next.second;

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[index][k] = {maxi, mini};
    }

    long long maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        vector<vector<pair<ll,ll>>> dp(
            n + 1,
            vector<pair<ll,ll>>(k + 1)
        );

        vector<vector<bool>> vis(
            n + 1,
            vector<bool>(k + 1, false)
        );

        return f(0, n, arr, k, dp, vis).first;
    }
};
