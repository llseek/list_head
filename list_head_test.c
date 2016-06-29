#include <stdio.h>
#include "list_head.h"

int main(int argc, char *argv[])
{
	/* init */
	LIST_HEAD(test_list);
	LIST_HEAD(entry1);
	LIST_HEAD(entry2);
	printf("test_list is %sempty\n", list_empty(&test_list) ? "" : "not ");

	/* add */
	list_add(&entry1, &test_list);
	list_add_tail(&entry2, &test_list);
	printf("test_list is %sempty\n", list_empty(&test_list) ? "" : "not ");
	
	/* delete */
	list_del(&entry1);
	list_del(&entry2);
	printf("test_list is %sempty\n", list_empty(&test_list) ? "" : "not ");
	
	return 0;
}
