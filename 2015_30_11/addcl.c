#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *list;
struct testcases{

	int input;
	int add;
	int result;
}
testcase[6] = {
	{ 123, 4, 1234 },
	{ 34, 1, 134 },
	{ 123, 2, 1223 },
	{ 135, 2, 1235 },
	{ 11, 1, 111 },
	{ 3789, 6, 36789 }
};

void start(int);
list createNode(int);
list createList(int);
void reverseLL(list);
bool compare(list, int);
list addnode(list, int);
list cll(list);
void checkresult(list, int);

int main(){
	for (int i = 0; i < 6; i++)
		start(i);

	getchar();
}

void start(int i){

	list head;
	head = createList(testcase[i].input);
	head = addnode(head, testcase[i].add);
	checkresult(head, i);
}

void checkresult(list head, int i)
{
	if (compare(head, testcase[i].result))
		printf("\nPass");
	else
		printf("\nFail");
}


list addnode(list head, int num){

	list curr = head;
	list newNode = createNode(num);
	if (num < curr->data){
		while (curr->next != head)
			curr = curr->next;
		curr->next = newNode;
		newNode->next = head;
		return newNode;
	}
	else{
		while (curr->next->data < num && curr->next != head)
			curr = curr->next;
		newNode->next = curr->next;
		curr->next = newNode;
		return head;
	}

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
	while (num>0) {
		list newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	head = cll(head);
	return head;
}

list cll(list head)
{
	list curr = head;
	while (head->next != NULL)
		head = head->next;
	head->next = curr;
	return curr;
}

bool compare(list result, int num) {
	list head = createList(num);
	int hd1, hd2;
	hd1 = result->data;
	hd2 = num;
	while (head->data == result->data && head->data != hd1  && result->data != hd2)
	{
		head = head->next;
		result = result->next;
	}
	return head->data == result->data;
}