class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> score;

        for (const auto& op : operations) {
            if (op == "+") {
                score.push_back(score.back() + score[score.size() - 2]);
            }
            else if (op == "C") {
                score.pop_back();
            }
            else if (op == "D") {
                score.push_back(score.back() * 2);
            }
            else {
                score.push_back(std::stoi(op));
            }
        }

        return std::accumulate(score.begin(), score.end(), 0);
    }
};
