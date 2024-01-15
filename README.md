# Linklist_duplication_delete
The provided code aims to remove duplicate nodes from a sorted singly-linked list. 
# Remove Duplicates from Sorted List

This repository contains the C implementation of a function to remove all duplicates from a sorted singly-linked list. It ensures that only distinct values remain in the list, effectively deleting any consecutive nodes that have the same value.

## Description

The `deleteDuplicates` function takes the head of a sorted singly-linked list and removes nodes that have duplicate values, leaving only distinct values in the list.

## Implementation

```c
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
