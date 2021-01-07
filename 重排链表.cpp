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
 /*143:����һ��������?L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
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
        ListNode* post = slow->next;//��¼��벿������
        slow->next = nullptr;//�и�
        
         //�Ժ�������
        ListNode* prev = new ListNode(-1);
        while(post){
            ListNode* next = post->next;
            post->next = prev->next;
            prev->next = post;
            post = next;
        }

        //������ĺ��β���ǰ���
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
