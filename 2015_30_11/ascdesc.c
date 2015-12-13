#include <stdio.h>
#include<stdbool.h>
struct testcases{
	int input;
	int result;
}
testcase[6] = {
	{ 123986, 123689 },
	{ 2386, 2368 },
	{ 132, 123 },
	{ 1984, 1489 },
	{NULL,NULL},
	{ 132, 123 }
};

struct node {
	int data;
	struct node *next;
};
typedef struct node* list;
typedef struct node * position;

void test(int);
list createNode(int);
list createList(int);
void checkresult(int, int);
void start(int);
void sortedlist(list, int);
void swap(list, list);
bool compare(list, int);
list reverse(list, list);

void main()
{
	for (int i = 0; i < 6; i++)
		start(i);
	getchar();

}

void sortedlist(list head, int i)
{
	list node1 = NULL;
	list curr = head;
	int c = 0;
	while (curr->next != NULL)
	{
		if (curr->data > curr->next->data)
		{
			node1 = curr;
			head->next= reverse(node1, NULL);
			break;
		}
		if (c == 1)
		{
			head = head->next;
		}
		curr = curr->next;
		c = 1;
	}
}

	list reverse(list head, list prev)
	{
		if (head->next == NULL){
			head->next = prev;
			return head;
		}
		else{
			list temp = head->next;
			head->next = prev;
			head = reverse(temp, head);
			return head;
		}
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
