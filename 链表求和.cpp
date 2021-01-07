/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 ���������������ʾ��������ÿ���ڵ����һ����λ��
��Щ��λ�Ƿ����ŵģ�Ҳ���Ǹ�λ���������ײ���
��д������������������ͣ�����������ʽ���ؽ����
*/
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head = new ListNode(-1), *p1 = l1, *p2 = l2, *p = head;//�ô�ͷ�ڵ�Ŀ�����һ���ʼ������
        int sum = 0, carr = 0;
        while (p1 || p2 || carr) //�������&&��while������Ҫ��һЩ����
        {
            sum = 0;//��ǰ��λ���ֺ�
            if(p1)
            {
                sum += (p1->val);
                p1 = p1->next;
            }
            if(p2)
            {
                sum += (p2->val);
                p2 = p2->next;
            }
            sum += carr; //������һλ�Ľ�λ
            ListNode *t = new ListNode(sum % 10); //�õ���ǰλ����
            carr = sum / 10; //�õ���ǰλ����һλ�Ľ�λ
            p->next = t;//��ǰλ������ȥ
            p = p->next;//�α�ָ�����
        }
        return head->next;
    }
};
