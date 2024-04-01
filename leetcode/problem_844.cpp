class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        for (char c : s) {
            if (c != '#') {
                st1.push(c);
            } else {
                if (st1.empty())
                {
                    continue;
                }
                st1.pop();
            }
        }
        for (char c : t) {
            if (c != '#') {
                st2.push(c);
            } else {
                if (st2.empty())
                {
                    continue;
                }
                st2.pop();
            }
        }
        
        if (st1.size() != st2.size()) {
            return false;
        }

        while (st1.size())
        {
            if (st1.top() != st2.top()) {
                return false;
            }

            if (st1.size() > 0) {
            st1.pop();
            st2.pop();
            }
        }

        return true;
    }
};
