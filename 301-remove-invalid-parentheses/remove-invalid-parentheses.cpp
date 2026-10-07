class Solution {
public:
    unordered_set<string> ans;

    void dfs(string& s, int index,
             int leftRemove, int rightRemove,
             int balance, string& path) {

        if (index == s.size()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {
                ans.insert(path);
            }
            return;
        }

        char c = s[index];

        // Case 1: Parenthesis
        if (c == '(') {

            // Remove it
            if (leftRemove > 0) {
                dfs(s, index + 1,
                    leftRemove - 1,
                    rightRemove,
                    balance,
                    path);
            }

            // Keep it
            path.push_back(c);

            dfs(s, index + 1,
                leftRemove,
                rightRemove,
                balance + 1,
                path);

            path.pop_back();
        }

        else if (c == ')') {

            // Remove it
            if (rightRemove > 0) {
                dfs(s, index + 1,
                    leftRemove,
                    rightRemove - 1,
                    balance,
                    path);
            }

            // Keep it only if it doesn't make balance negative
            if (balance > 0) {
                path.push_back(c);

                dfs(s, index + 1,
                    leftRemove,
                    rightRemove,
                    balance - 1,
                    path);

                path.pop_back();
            }
        }

        // Normal character
        else {
            path.push_back(c);

            dfs(s, index + 1,
                leftRemove,
                rightRemove,
                balance,
                path);

            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals required
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string path;

        dfs(s, 0,
            leftRemove,
            rightRemove,
            0,
            path);

        return vector<string>(ans.begin(), ans.end());
    }
};