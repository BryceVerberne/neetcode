class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for (const char& c : s) {
            if (map.contains(c)) {
                if (!stack.empty() && (stack.top() == map[c])) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
