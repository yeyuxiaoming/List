/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 环形列表||:给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*unordered_set<ListNode*> visited;
        while(head != NULL) {
            if(visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;*/
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* p = head;
                ListNode* q = fast;
                while(p != q) {
                    p = p->next;
                    q = q->next;
                }
                return q;
            }
        }
        return nullptr;
    }
};

