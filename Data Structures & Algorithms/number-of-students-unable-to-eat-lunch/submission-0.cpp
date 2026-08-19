class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::stack<int> sandwichStack;
        std::queue<int> studentQueue;

        // Variables to record student preferences & inventory
        int sStudent = 0, cStudent = 0, square = 0, circ = 0;

        // Fill up a stack & queue
        for (int i = 0; i < students.size(); ++i) {
            studentQueue.push(students[i]);
            sandwichStack.push(sandwiches[sandwiches.size() - 1 - i]);

            (students[i] == 0) ? ++cStudent : ++sStudent;
            (sandwiches[i] == 0) ? ++circ : ++square;
        }

        while (!sandwichStack.empty()) {
            int front = studentQueue.front();

            if (front == sandwichStack.top()) {
                if (front == 0) {
                    --cStudent; --circ;
                }
                else {
                    --sStudent; --square;
                }

                studentQueue.pop();
                sandwichStack.pop();
            } 
            else {
                if ((sandwichStack.top() == 0 && cStudent == 0) || (sandwichStack.top() == 1 && sStudent == 0)) {
                    break;
                }
                
                studentQueue.pop();
                studentQueue.push(front);
            }
        }

        return (sStudent + cStudent);
    }
};