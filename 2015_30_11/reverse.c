#include<stdio.h>
#include<stdbool.h>
#include<stdio.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node * list;
struct testcases{

	int input;
	int result;
}
testcase[5] = {
	{1234,4321},
	{1,1},
	{4321,1234},
	{11,11},
	{112,211}
};

void start(int);
list createNode(int);
list createList(int);
list reverseLL(list,list);
bool compare(list,int);
void checkresult(list, int);

int main()
{
	for (int i = 0; i < 5;i++)
		start(i);
	getchar();
}
list reverseLL(list head,list prev){
	if (head->next == NULL){
		head->next = prev;
		return head;
	}
	else{
		list temp = head->next;
		head->next = prev;
		head = reverseLL(temp, head);
		return head;
	}
}

void start(int i){
	list head,head1;
	head =head1= createList(testcase[i].input);
	head = reverseLL(head, NULL);
	checkresult(head, i);
}

void checkresult(list head,int i)
{
	if (compare(head, testcase[i].result))
		printf("\nPass");
	else
		printf("\nFail");
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

bool compare(list result, int num) {
	list head = createList(num);
	while (head && result && head->data == result->data) {
		head = head->next;
		result = result->next;
	}
	return !head && !result;
}