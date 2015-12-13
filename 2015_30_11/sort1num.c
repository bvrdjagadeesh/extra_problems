#include <stdio.h>
#include<stdbool.h>
struct testcases{
	int input;
	int result;
}
testcase[5] = {
	{127389, 123789 },
	{ 12546, 12456 },
	{ 32, 23 },
	{ 72, 27 },
	{ 132, 123 }
};


struct node {
	int data;
	struct node *next;
};
typedef struct node* list;

void test(int);
list createNode(int);
list createList(int);
void checkresult(int, int);
void start(int);
void sortedlist(list, int);
void swap(list, list);
bool compare(list, int);

int main(){
	for (int i = 0; i < 5; i++)
		start(i);
	getchar();

}

void sortedlist(list head, int i)
{
	list node1 = NULL;
	list node2 = NULL;
	list curr = head;
	int flag1 = 0, flag2 = 0;
	while (curr->next != NULL)
	{
		if (curr->data > curr->next->data && flag1 != 1)
		{
			node1 = curr;
			flag1 = 1;
		}
		else if (curr->data > curr->next->data&& flag1 == 1 && flag2 != 1)
		{
			node2 = curr->next;
			flag2 = 1;
			break;
		}
		curr = curr->next;
	}
	if (flag2 == 0 && flag1 == 1)
	{
		flag2 = 1;
		node2 = node1->next;
	}
	if (flag1 && flag2)
		swap(node1, node2);
}

void swap(list node1, list node2)
{
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}


void start(int i)
{
	list head;
	head = createList(testcase[i].input);
	sortedlist(head, i);
	checkresult(head, i);
}

void checkresult(list result, int i)
{
	if (compare(result, testcase[i].result))
		printf("\nPass");
	else
		printf("\nFail");
}

bool compare(list result, int num) {
	list head = createList(num);
	while (head && result && head->data == result->data) {
		head = head->next;
		result = result->next;
	}
	return !head && !result;
}

list createNode(int num) {
	list newNode = (list)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

list createList(int num) {
	list head = createNode(num % 10);
	num /= 10;
	while (num) {
		list newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
