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
        // TODO: Ensure the head isn't nullptr or contains 1 element
        if (!head) return head;
        
        ListNode* battery = head->next;
        head->next = nullptr; // Set the tail
        
        while (battery) {
            ListNode* temp = battery->next;
            battery->next = head;

            head = battery;
            battery = temp;
        }

        return head;
    }
};
