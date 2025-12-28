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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> value(nums.begin(), nums.end());
        int component = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            if ((cur->next == nullptr  || !value.count(cur->next->val)) 
                && value.count(cur->val)) {
                component++;
            }
            cur = cur->next;
        }
        return component;
    }
};