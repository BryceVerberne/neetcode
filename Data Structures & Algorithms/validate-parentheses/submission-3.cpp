class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;

        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            }
            else if (!stack.empty() &&
                     ((stack.back() == '(' && c == ')') ||
                     (stack.back() == '{' && c == '}') ||
                     (stack.back() == '[' && c == ']'))) {
                stack.pop_back();
            }
            else {
                return false;
            }
        }

        
        return (stack.empty()) ? true : false;
    }
};
