#include <list.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct List{
    ListNode * head;
};

struct ListNode{
    ListNode * next;
    void * data;
};

#define throw(MSG) assert(0 && MSG);

struct List * List_new(void) {
    struct List * list = (struct List *)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

void List_free(List ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

struct ListNode * ListNode_new(void * data) {
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->data = data;
    return node;
}

void ListNode_free(struct ListNode ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void List_addLast(struct List * self, void * data) {
    struct ListNode * node = ListNode_new(data);
    if (self->head == NULL) {
          self->head = node;
          return;
    }
    struct ListNode * cur = self->head;
    while (cur->next != NULL) {
          cur = cur->next;
    }
    cur->next = node;
}

int List_count(List * self){
    ListNode * curr = self->head;
    int count = 0;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}


void * List_get(List * self, int position){
    int len = List_count(self);
    if(position >= len || position < 0) throw("Index out of bounds!");
    ListNode * curr = self->head;
    for(int i = 0; i < len; i++){
        if(position == i) break;
        curr = curr->next;
    }
    return curr->data;
}

void List_clean(List * self){
    int len = List_count(self);
    for(int i = 0; i < len; i++){
        ListNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            free(curr->data);
            ListNode_free(&curr);
            self->head = NULL;
            return;
        }
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        free(curr->next->data);
        ListNode_free(&(curr->next));
        curr->next = NULL;
    }
}
