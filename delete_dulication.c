/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 //删除第flag个节点

struct ListNode* deleteDuplicates(struct ListNode* head) {

    if (head == NULL || head->next == NULL){
        return head;
    }

    //创建检查指针
    struct ListNode *current = head->next;
    struct ListNode *prev = head;
    //遍历链表查找重复
    while(current->next != NULL){
        if (current->val == prev->val){
            prev->next = current->next;
            free(current); // 释放重复节点的内存
            current = prev->next; // 继续检查下一个节点
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return head;
}
