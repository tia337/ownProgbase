#ifndef LIST_H
#define LIST_H

typedef struct List List;
typedef struct ListNode ListNode;

struct List * List_new(void);  //list constructor
void List_free(List ** self); //list destructor

struct ListNode * ListNode_new(void *ref); //node constructor
void ListNode_free(ListNode ** self); //node destructor

void List_addLast(List * self, void * ref);

int List_count(List * self);
void * List_get(List * self, int position);

void List_clean(List * self);
void List_free(List ** selfPtr);

#endif
