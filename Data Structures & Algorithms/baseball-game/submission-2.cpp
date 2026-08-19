class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> stack;
        int score = 0;

        for (const auto& op : operations) {
            if (op == "C") {
                score -= stack.top();
                stack.pop();
            }
            else if (op == "D") {
                score += stack.top() * 2;
                stack.push(stack.top() * 2);
            }
            else if (op == "+") {
                int top = stack.top(); stack.pop();
                int sum = stack.top() + top;
                score += sum;
                stack.push(top);
                stack.push(sum);
            }
            else {
                score += std::stoi(op);
                stack.push(std::stoi(op));
            }
        }

        return score;
    }
};
