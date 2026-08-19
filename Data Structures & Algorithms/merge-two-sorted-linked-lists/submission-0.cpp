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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead;

        // The technique I am going to use is to alternate, I am going 
        // to continue to iterate through list1 until the furthest left
        // node in list2 is less than the furthest left list1 node.
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while (curr1 || curr2) {
            if (!curr1) { // Only list2 has remaining values
                curr->next = new ListNode(curr2->val);
                curr = curr->next;
                curr2 = curr2->next;
            }
            else if (!curr2) { // Only list1 has remaining values
                curr->next = new ListNode(curr1->val);
                curr = curr->next;
                curr1 = curr1->next;
            }
            else { // Both lists have values to compare
                if (curr1->val > curr2->val) {
                    curr->next = new ListNode(curr2->val);
                    curr = curr->next;
                    curr2 = curr2->next;
                }
                else {
                    curr->next = new ListNode(curr1->val);
                    curr = curr->next;
                    curr1 = curr1->next;
                }
            }
        }

        ListNode* head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};
