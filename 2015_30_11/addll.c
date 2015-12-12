#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node * list;
struct testcases
{

	int input1;
	int input2;
	int result;

}
testcase[6] = {
	{ 123, NULL, 123 },
	{NULL,123,123},
	{ NULL, NULL, NULL },
	{ 333, 444, 777 },
	{ 1, 1, 2 },
	{ 45, 1234, 1279 }
};
void start(int);
list createNode(int);
list createList(int);
bool compare(list, int);
list addLL(list, list);
int getLength(list);
list addUtil(list, list, int);
void checkresult(list, int);

int main(){
	for (int i = 0; i < 6; i++)
		start(i);
	getchar();
}


void start(int i){
	list head1;
	list head2;
	head1 = createList(testcase[i].input1);
	head2 = createList(testcase[i].input2);
	head1 = addLL(head1, head2);
	checkresult(head1, i);
}

void checkresult(list head, int i)
{
	if (compare(head, testcase[i].result))
		printf("\nPass");
	else
		printf("\nFail");
}

list addLL(list head1, list head2){
	int diff = getLength(head1) - getLength(head2);
	int carry = 0;
	list result = addUtil(head1, head2, diff);
	return result;
}

list addUtil(list list1, list list2, int diff){

	if (list1 == NULL && list2 == NULL)
		return list1;
	list result = createNode(0);
	if (diff > 0){
		result->next = addUtil(list1->next, list2, diff - 1);
		result->data =list1->data;
	}
	else if (diff < 0){
		result->next = addUtil(list1, list2->next,diff + 1);
		result->data =list2->data;
	}
	else{
		result->next = addUtil(list1->next, list2->next,0);
		result->data =(list1->data) + (list2->data);
	}
	result->data %= 10;
	return result;
}

int getLength(list head){
	int i = 0;
	while (head != NULL){
		i++;
		head = head->next;
	}
	return i;
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
	struct node *head = createList(num);
	while (head && result && head->data == result->data) {
		head = head->next;
		result = result->next;
	}
	return !head && !result;
}