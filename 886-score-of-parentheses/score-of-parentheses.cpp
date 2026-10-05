class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } 
            else {
                int inner = st.top();
                st.pop();

                if (inner == 0) {
                    inner = 1;          // ()
                } 
                else {
                    inner = 2 * inner;  // (A)
                }

                st.top() += inner;
            }
        }

        return st.top();
    }
};