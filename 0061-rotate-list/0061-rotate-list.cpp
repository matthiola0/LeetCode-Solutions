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
    pair<int, ListNode*> listLen(ListNode* head) {
        int n = 0;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            n++;
            prev = head;
            head = head->next;
        }
        return {n, prev};
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto [n, last] = listLen(head);
        if (n == 0 || n == 1 || k == 0 || k == n) return head;
        int rotate = k % n;
        ListNode *cur = head, *prev = head;
        for (int i = 0; i < n - rotate; i++) {
            prev = cur;
            cur = cur->next;
        }
        last->next = head;
        head = cur;
        prev->next = nullptr;
        return head;
    }
};