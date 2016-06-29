#include <stdbool.h>
#include <stdlib.h>
#include "list_head.h"

#define LIST_POISON_1	((void *)0)
#define LIST_POISON_2	((void *)0)

bool list_empty(struct list_head *head)
{
	return head->prev == head;
}

void list_add(struct list_head *entry, struct list_head *head)
{
	head->next->prev = entry;
	entry->prev = head;

	entry->next = head->next;
	head->next = entry;
}

void list_add_tail(struct list_head *entry, struct list_head *head)
{
	head->prev->next = entry;
	entry->next = head;

	entry->prev = head->prev;
	head->prev = entry;
}

void list_del(struct list_head *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
	entry->prev = LIST_POISON_1;
	entry->next = LIST_POISON_2;
}

void list_del_init(struct list_head *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
	entry->prev = entry;
	entry->next = entry;
}
