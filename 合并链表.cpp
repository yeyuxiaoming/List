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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;
        a--, b++;
        while(a--) {
            p = p->next;
            b--;
        } 
        ListNode* t = p;
        while(b--) {
            t = t->next;
        }
        p->next = list2;
        while(p->next != NULL) p = p->next;
        p->next = t;
        return list1;
    }
};