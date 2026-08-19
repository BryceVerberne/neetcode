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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        long long num = 10000000000000000000;
        for (long long i = 0; i < num; ++i) {}

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
