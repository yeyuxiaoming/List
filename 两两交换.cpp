/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 ����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)return head;
        if(head->next==nullptr)return head;
        ListNode* p=head->next;
        head->next=swapPairs(p->next);
        p->next=head;
        return p;
    }
    
};