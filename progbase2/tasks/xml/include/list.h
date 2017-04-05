#ifndef LIST_H
#define LIST_H
typedef struct List List;
typedef struct ListNode ListNode;

struct List * List_new(void);  //list constructor
void List_free(List ** self); //list destructor

struct ListNode * ListNode_new(void *ref); //node constructor
void ListNode_free(ListNode ** self); //node destructor

void List_addFirst(List * self, void * ref);
void List_addLast(List * self, void * ref);
void List_insert(List * self, int position, void * ref);

void List_removeFirst(List * self);
void List_removeLast(List * self);
void List_removeAt(List * self, int position);

int List_count(List * self);
void * List_get(List * self, int position);

void List_clean(List * self);

ListNode * ListNode_head_return(List* self);
ListNode * ListNode_next_return(ListNode * self);
void * ListNode_data_return(ListNode * self);



#endif