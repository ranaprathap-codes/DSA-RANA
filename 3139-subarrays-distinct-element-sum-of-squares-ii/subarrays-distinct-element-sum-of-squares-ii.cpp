
class Solution {
    static const int MOD = 1'000'000'007;

    vector<long long> sum, sq, lazy;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        sq[node] = (sq[node]
            + 2LL * val * sum[node]
            + val * val % MOD * len) % MOD;

        sum[node] = (sum[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2]
                   + sum[node * 2 + 1]) % MOD;

        sq[node] = (sq[node * 2]
                  + sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = last[nums[r]];

            // Increment distinct counts for affected starts.
            update(1, 0, n - 1, p + 1, r);

            // Sum of squared distinct counts for subarrays
            // ending at index r.
            ans = (ans + sq[1]) % MOD;

            last[nums[r]] = r;
        }

        return (int)ans;
    }
};
