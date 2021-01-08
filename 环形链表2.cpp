/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 �����б�||:����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��*/
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

