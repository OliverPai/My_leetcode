#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){};
};

class solution{
public:

    //新建链表
    ListNode* make_list(int number, ListNode* former) {
        ListNode *node = new ListNode(number % 10);
        if(number/10>0)
            node->next = make_list(number / 10, node);
        else if(former != NULL)
            former->next = node;
        return node;
    }

    //求和
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2) {
        ListNode *node = new ListNode(l1->val + l2->val);
        uint8_t flag = (l1->next == NULL) + (l2->next == NULL);
        switch (flag) {
            case 0: {//l1->next!=NULL&&l2->next!=NULL
                if(node->val>=10){//进位
                    ListNode *node_3 = new ListNode(l1->next->val+1);
                    node_3->next = l1->next->next;
                    node->next=addTwoNumbers(node_3,l2->next);
                    node->val%=10;
                    delete node_3;
                }
                else
                    node->next=addTwoNumbers(l1->next,l2->next);
                break;
            }
            case 1: {
                if(l2->next==NULL){
                    ListNode *node_3 = new ListNode(l1->next->val);
                    if(node->val>=10){
                        node_3->val += 1;
                        node->val%=10;
                    }
                    node_3->next = l1->next->next;
                    ListNode *node_4 = new ListNode(0);
                    node->next = addTwoNumbers(node_3,node_4);
                    delete node_4;
                    delete node_3;
                }
                else{
                    ListNode *node_3 = new ListNode(l2->next->val);
                    if(node->val>=10){
                        node_3->val += 1;
                        node->val%=10;
                    }
                    node_3->next = l2->next->next;
                    ListNode *node_4 = new ListNode(0);
                    node->next = addTwoNumbers(node_4,node_3);
                    delete node_4;
                    delete node_3;
                }
                break;
            }
            case 2: {
                if(node->val>=10){//进位
                    ListNode *node_2 = new ListNode(node->val/10);
                    node->val%=10;
                    node->next = node_2;
                }
                break;
            }
        }
        return node;
    }
};

int main() {
    solution test;
    ListNode* list_1 = test.make_list(342,NULL);
    ListNode* list_2 = test.make_list(465,NULL);

    //测试make_list函数
//    ListNode* list_ = list_1;
//    while(list_!=NULL){
//        std::cout<<list_->val<<' ';
//        list_ = list_->next;
//    }

    //测试addTwoNumbers函数
    ListNode* result = test.addTwoNumbers(list_1,list_2);
    while(result!=NULL){
        std::cout<<result->val<<' ';
        result = result->next;
    }

    return 0;
}
