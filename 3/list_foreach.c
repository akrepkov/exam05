/*
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in your file ft_list_foreach.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    int          value;
}                 t_list;
void    ft_list_foreach(t_list *begin_list, void (*f)(int *)){
	while(begin_list != NULL){
		f(&begin_list->value);
		begin_list= begin_list->next;
	}
}

void f(int *a){
	*a =(*a)*2;
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

	ft_list_foreach(a,f);
	t_list* cur;
	cur = a;
	while (cur != 0)
	{
		printf("%d, ", cur->value);
		cur = cur->next;
	}
}