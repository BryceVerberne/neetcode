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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* prev = nullptr;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        // Sort up to matching list sizes
        while ((cur1 != nullptr) && (cur2 != nullptr)) {
            if (cur1->val <= cur2->val) {
                prev = cur1;
                cur1 = cur1->next;
            }
            else {
                if (prev) {
                    prev->next = cur2;
                }
                else {
                    list1 = cur2;
                }

                ListNode* tmp = cur2->next;
                prev = cur2;
                cur2->next = cur1;
                cur2 = tmp;
            }
        }

        // Fill out the remaining
        while(cur2 != nullptr) {
            prev->next = cur2;
            prev = prev->next;
            cur2 = cur2->next;
        }

        return list1;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Combine each list
        while (lists.size() > 1) {
            vector<ListNode*> mergedList;

            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = ((i + 1) < lists.size()) ? lists[i+1] : nullptr;
                mergedList.push_back(merge(l1, l2));
            }
            lists = mergedList;
        }

        return lists[0];
    }
};
