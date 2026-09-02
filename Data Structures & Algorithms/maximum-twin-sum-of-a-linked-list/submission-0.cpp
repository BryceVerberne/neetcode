/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if (!head) {
            return 0;
        }

        ListNode* tail = head;
        vector<int> arr{tail->val};
        while (tail->next) {
            tail = tail->next;
            arr.push_back(tail->val);
        }

        int maxTwin = INT_MIN;
        int L = 0, R = static_cast<int>(arr.size()) - 1;
        while (L < R) {
            maxTwin = max(maxTwin, arr[R] + arr[L]);
            L++;
            R--;
        }


        return (maxTwin == INT_MIN) ? 0 : maxTwin;
    }
};