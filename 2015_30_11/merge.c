#include<stdio.h>
#include<stdbool.h>
struct node {
	int data;
	struct node *next;
};

struct testcases{

	int ll1;
	int ll2;
	int res;
}
tests[5] = {
	{1278,5679,12567789 },
	{347,256,234567 }, 
	{1,111,1111 }, 
	{123,45,12345 },
	{23,479,23479}
};
typedef struct node *list;

void start(int);
list createNode(int);
list createList(int);
list merge(list,list);
bool compare(list, int num);
void checkresult(list, int);

int main(){
	int i;
	for (i = 0; i < 5;i++)
		start(i);
	getchar();

}

list merge(list head1,list head2){

	list result;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->data <= head2->data){
		result = head1;
		result->next = merge(head2, head1->next);
	}
	else{
		result = head2;
		result->next = merge(head1, head2->next);
	}
	return result;
}

void start(int i){

	list head1,head2,result;
	head1 = createList(tests[i].ll1);
	head2 = createList(tests[i].ll2);
	result = merge(head1,head2);
	checkresult(result, i);
}

void checkresult(list result,int i)
{
	if (compare(result, tests[i].res))
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
