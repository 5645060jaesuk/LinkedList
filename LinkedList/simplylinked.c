#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void insert_node(ListNode* head, const int index, const int data) {
	int cnt = 0;
	int k = index; 
	ListNode* pre_node = head; 
	ListNode* insert = (ListNode*)malloc(sizeof(ListNode)); 
	insert->data = data; 

	while (k-- && pre_node != NULL)
	{
		pre_node = pre_node->link;
		cnt++;
	}


	if (pre_node == NULL) { 
		free(insert);
		return;
	}

	insert->link = pre_node->link; 
	pre_node->link = insert;
	printf("Move along the link : %d\n", cnt);
	printf("\n");
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}


void delete_node(ListNode* head, const int index) {
	int cnt = 0;
	int k = index; 
	ListNode* temp = head;
	ListNode* garbage = NULL; 

	while (k-- && temp != NULL)
	{
		temp = temp->link; 
		cnt++;
	}


	if (temp == NULL || temp->link == NULL) 
		return; 

	garbage = temp->link; 
	temp->link = garbage->link;  
	free(garbage); 
	printf("Move along the link : %d\n", cnt);
	printf("\n");
}

int size(ListNode* head) {
	ListNode* temp = head->link;
	int len = 0;
	while (temp != NULL) { 
		++len; 
		temp = temp->link; 
	}
	return len;
}


void print_list(ListNode* head)
{
	ListNode* p = head->link;
	if (head->link == NULL) return;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

int main()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	int n;
	int num;
	int pos;
	head->data = 0;
	head->link = NULL;



	while (1)
	{
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the Menu : ");
		scanf_s("%d", &n);
		if (n == 1)
		{
			printf("enter the number and position : ");
			scanf_s("%d %d", &num, &pos);
			if (head->link == NULL && pos > 0)
			{
				printf("List is empty. Insett at position 0..\n");
				printf("\n");
				pos = 0;
			}
			if (head->link != NULL && size(head) < pos)
			{
				printf("The las index is %d. Insert at the end of the list\n",size(head)-1);
				printf("\n");
				pos = size(head);
			}
			insert_node(head, pos, num);
		}
		else if (n == 2)
		{
			if (head->link == NULL)
			{
				printf("List is empty\n");
				printf("\n");
			}
			else
			{
				printf("Enter the position : ");
				scanf_s("%d", &pos);
				delete_node(head,pos);
			}

		}
		else if (n == 3)
		{
			print_list(head);
		}

		else if (n == 0)
		{
			printf("Exit the program.");
			break;
		}
		else
		{
			printf("Invalid Menu. Please select again.\n");
			printf("\n");
		}
	}

}
