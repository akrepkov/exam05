/*
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.
Duplications must remain.
Inputs will always be consistent.
Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.
For example, the following function used as cmp will sort the list 
in ascending order:
int ascending(int a, int b)
{
	return (a <= b);
}*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int 	value;
	struct s_list *next;
} t_list;


t_list	*sort_list(t_list* lst, int (cmp)(int, int)){
	int swapped = 0;
	t_list *original = lst;
	if (lst == NULL  || lst->next == NULL)
		return lst;
	t_list* new = lst->next;
	while (swapped == 0){
		if (cmp(lst->value, new->value) == 0){
			printf("compare %d - list and %d - next\n", lst->value, new->value);
			int temp = lst->value;
			lst->value = new->value;
			new->value = temp;
			swapped = 0;
			sort_list(original, cmp);
		}
		new = new->next;
		lst = lst->next;
		if (new == NULL || lst == 0)
			swapped = 1;
	}
	return lst;
}

int cmp(int a, int b){
	return (a <= b);
}

int main(){
	t_list* d = (t_list *)malloc(256);
	d->value = 1;
	d->next = NULL;
	t_list* c = (t_list *)malloc(256);
	c->value = 2;
	c->next = d;
	t_list* b = (t_list *)malloc(256);
	b->value = 3;
	b->next = c;
	t_list* a = (t_list *)malloc(256);
	a->value = 4;
	a->next = b;

	sort_list(a,cmp);
	while(a != NULL){
		printf("Value  %d - ", a->value);
		a = a->next;
	}
	return 0;
}

// 4321
// 3421
// 3241
// 2341
// 2314
// 2134
// 1234