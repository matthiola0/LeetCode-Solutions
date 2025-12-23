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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        while (prev->next != nullptr) {
            int cur_val = prev->next->val;
            ListNode* cur_node = prev->next->next;
            bool flag = false;
            while (cur_node != nullptr && cur_node->val == cur_val) {
                flag = true;
                cur_node = cur_node->next;
            }
            if (flag) {
                prev->next = cur_node;
            } else {
                prev = prev->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};