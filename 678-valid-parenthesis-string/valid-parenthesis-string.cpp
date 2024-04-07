class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stack_open, stack_star;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack_open.push(i);
            } else if (s[i] == '*') {
                stack_star.push(i);
            } else { 
                if (!stack_open.empty()) {
                    stack_open.pop();
                } else if (!stack_star.empty()) {
                    stack_star.pop();
                } else {
                    return false;
                }
            }
        }

        while (!stack_open.empty() && !stack_star.empty()) {
            if (stack_open.top() > stack_star.top()) {
                return false;
            }
            stack_open.pop();
            stack_star.pop();
        }

        return stack_open.empty();
    }
};