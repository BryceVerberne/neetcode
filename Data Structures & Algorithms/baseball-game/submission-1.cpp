class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> scoreList;
        int score = 0;
        int update;

        for (const auto& op : operations) {
            if (op == "+") {
                update = scoreList.back() + scoreList[scoreList.size() - 2];
                scoreList.push_back(update);
                score += update;
            }
            else if (op == "C") {
                update = scoreList.back();
                scoreList.pop_back();
                score -= update;
            }
            else if (op == "D") {
                update = scoreList.back() * 2;
                scoreList.push_back(update);
                score += update;
            }
            else {
                update = std::stoi(op);
                score += update;
                scoreList.push_back(update);
            }
        }

        return score;
    }
};
