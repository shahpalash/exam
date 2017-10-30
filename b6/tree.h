


#include <string.h>
#include <stdlib.h>

struct node
{
	char name[10];
	struct node * left;
	struct node * rght;
};

struct Stack
{
	struct node * arr[10];
	int top;
}s;


void push(struct node * x)
{
	if(s.top>10) {printf("Stack Overflow\n"); return;}
	s.arr[s.top]=x;
	s.top++;
}

struct node * pop()
{
	if(s.top==0) {printf("Stack Underflow\n"); return NULL;}
	s.top--;
	return s.arr[s.top];
}

struct node * node_create(char * n, struct node * l, struct node * r)
{
	struct node * newnode = (struct node *) malloc(sizeof(struct node));
	strcpy(newnode->name, n);
	newnode->left = l;
	newnode->rght = r;
}

/*void children(struct node * p, struct node * l, struct node * r)
{
	p->left = l;
	p->rght = r;
}*/

display_in(struct node * root)
{
	if(root->left != NULL)
		display_in(root->left);
	printf("%s ", root->name);
	if(root->rght != NULL)
		display_in(root->rght);
}

display_post(struct node * root)
{
	if(root->left != NULL)
		display_post(root->left);
	if(root->rght != NULL)
		display_post(root->rght);
	printf("%s ", root->name);
}

display_pre(struct node * root)
{
	printf("%s ", root->name);
	if(root->left != NULL)
		display_pre(root->left);
	if(root->rght != NULL)
		display_pre(root->rght);
}
