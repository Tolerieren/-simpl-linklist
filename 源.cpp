//�ӵ��������Ƴ�һ���ڵ�   
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
	* ���Դ�ӡ
	while (*rootp)
	{
		printf("%d ", (*rootp)->value);

			(*rootp) = (*rootp)->fwd;
	}
	*/

	return 0;
}

int sll_remove(struct NODE** rootp, struct NODE* node)   //rootpָ���ָ���ָ�룬node����Ҫ��ɾ���Ľڵ��ָ��
{
	register NODE* current = *rootp;


	if (current == node)               //������ʼ
	{
		*rootp = node->fwd;
		return TRUE;
	}

	while ((current->fwd) != node)     
	{
		if (current->fwd == NULL)     //��ȡ�����һ���ڵ㣬����û���ҵ���Ҫɾ����node
			return FALSE;
		current = current->fwd;
	}
	current->fwd = node->fwd;

	return TRUE;
}