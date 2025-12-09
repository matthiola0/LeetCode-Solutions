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
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1 != nullptr) {
            node->next = list1;
        }
        if (list2 != nullptr) {
            node->next = list2;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int offset = 1;
        int n = lists.size();
        if (n == 0) return nullptr;
        while (offset < n) {
            for (int i = 0; i + offset < n; i += offset * 2) {
                lists[i] = merge(lists[i], lists[i + offset]);
            }
            offset *= 2;
        }
        return lists[0];
    }
};