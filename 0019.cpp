#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* find_0 = head;
        ListNode* find_1 = head;
        bool flag = false;
        while (n--)
            find_1 = find_1->next;
        while (find_1!=NULL){
            flag = true;
            if((find_1 = find_1->next)!=NULL)
                find_0 = find_0->next;
        }
        if(flag== false)
            head = head->next;
        else
            find_0->next = find_0->next->next;
        return head;
    }
};

int main( )
{
    Solution test;

    ListNode node_0(1);
    ListNode node_1(2);
    ListNode node_2(3);
    ListNode node_3(4);
    ListNode node_4(5);
    node_0.next = &node_1;
    node_1.next = &node_2;
    node_2.next = &node_3;
    node_3.next = &node_4;
    ListNode* outputs = test.removeNthFromEnd(&node_0,3);
    while (outputs!=NULL) {
        cout << outputs->val << endl;
        outputs = outputs->next;
    }

    return 0;
}

