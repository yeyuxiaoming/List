/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *pos = head;
        int size = 1;
        while(pos && pos->next)
        {
            pos = pos -> next;
            size ++;
        }
        int move = k % size;
        if(move == 0) return head;
        ListNode *cut = head;
        for(int i=0; i<size-move-1; ++i) cut = cut -> next;
        ListNode *result = cut -> next;
        cut -> next = nullptr;
        pos -> next = head;
        return result;
    }
};
*/

 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n=0;
        for(auto p=head;p;p=p->next) n++;
        k%=n;
        auto first=head,second=head;
        while(k--){
            first=first->next;
        }
        while(first->next){
            first=first->next;
            second=second->next;
        }
        first->next=head;
        head=second->next;
        second->next=NULL;
        return head;
    }
};