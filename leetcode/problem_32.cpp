class Solution {
public:
    int longestValidParentheses(string s) { 
        stack<int> stack;
        stack.push(-1);
        int m_l = 0;
        for (int i = 0; i < s.length(); ++i) {
            int len = 0;
            if (s[i] == '(') {
                stack.push(i);

            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    len = i - stack.top();
                    m_l = (m_l < len) ? len : m_l;
                }
            }
        
        }
            return m_l;
    }  
};
