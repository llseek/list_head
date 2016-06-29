#ifndef __LIST_HEAD_H__
#define __LIST_HEAD_H__

#include <stdbool.h>

struct list_head {
	struct list_head *prev;
	struct list_head *next;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name)	\
	struct list_head name = LIST_HEAD_INIT(name)

bool list_empty(struct list_head *head);
void list_add(struct list_head *entry, struct list_head *head);
void list_add_tail(struct list_head *entry, struct list_head *head);
void list_del(struct list_head *entry);
void list_del_init(struct list_head *entry);

#endif /* __LIST_HEAD_H__ */
