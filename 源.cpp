//从单链表中移除一个节点   
//remove one node from a single_list

# include <stdio.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE  1

struct NODE {
	int value;
	struct NODE* fwd;
}Node;
int sll_remove(struct NODE** rootp, struct NODE* node);

int main()
{
	NODE a, b, c, d, e;

	e = { 20,NULL };
	d = { 20,NULL };
	c = { 15,&d };
	b = { 10, &c };
	a = { 5, &b };
	NODE* first = &a;
	NODE** rootp = &first;

	int info = sll_remove(rootp, &e);

	if (info)
		puts("Delete successfully.");
	else
		puts("The sll does not has this node.");

	/*
	* 测试打印
	while (*rootp)
	{
		printf("%d ", (*rootp)->value);

			(*rootp) = (*rootp)->fwd;
	}
	*/

	return 0;
}

int sll_remove(struct NODE** rootp, struct NODE* node)   //rootp指向根指针的指针，node是需要被删除的节点的指针
{
	register NODE* current = *rootp;


	if (current == node)               //链表起始
	{
		*rootp = node->fwd;
		return TRUE;
	}

	while ((current->fwd) != node)     
	{
		if (current->fwd == NULL)     //读取到最后一个节点，还是没有找到需要删除的node
			return FALSE;
		current = current->fwd;
	}
	current->fwd = node->fwd;

	return TRUE;
}