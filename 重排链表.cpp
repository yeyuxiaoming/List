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
 /*143:给定一个单链表?L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)return ;
        ListNode* slow = head, * fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* post = slow->next;//记录后半部分链表
        slow->next = nullptr;//切割
        
         //对后半段逆序
        ListNode* prev = new ListNode(-1);
        while(post){
            ListNode* next = post->next;
            post->next = prev->next;
            prev->next = post;
            post = next;
        }

        //将逆序的后半段插入前半段
        ListNode* curr = head;
        ListNode* p = prev->next;
        while(p) {
            ListNode* cnext = curr->next;
            ListNode* pnext = p->next;
            curr->next = p;
            p->next = cnext;
            p = pnext;
            curr = cnext;
        }
    }
};
