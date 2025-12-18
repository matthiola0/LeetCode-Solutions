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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = new ListNode(0, nullptr),
                 *head2 = new ListNode(0, nullptr),
                 *small = head1, *big = head2, 
                 *cur = head;
        
        while (cur != nullptr) {
            if (cur->val < x) {
                small->next = cur;
                small = small->next;
            } else {
                big->next = cur;
                big = big->next;
            }
            cur = cur->next;
        }
        small->next = head2->next;
        big->next = nullptr;

        cur = head1->next;
        delete head1;
        delete head2;
        return cur;
    }
};