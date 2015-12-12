#include <stdio.h>
struct testcases{
	int input;
	int median;
}
testcase[5] = {
	{ 12789, 7 }, 
	{ 123456, 4 }, 
	{ 124589, 5 }, 
	{ 27, 5 }, 
	{ 3, 3 }
};


struct node {
	int data;
	struct node *next;
};
typedef struct node* list;

int findMedian(list,int,int);
list createNode(int);
list createList(int);
void checkresult(int, int);
int length(list);
void start(int);

int main(){
	for (int i = 0; i < 5;i++)
		start(i);
	getchar();

}


int findMedian(list head,int len,int i){

	int med, j,res;
	list a=head;
	if (len % 2 != 0)
	{
		for (j = 0; j<len/2 - 1; j++)
		{
			a = a->next;
		}
		res = (a->data + a->next->data) / 2;
		return res+1;
	}
	else
	{
		for (j = 0; j<len / 2 - 1; j++)
		{
			a = a->next;
		}
		return a->data;
	}

}

void start(int i){

	list head;
	int  median,len;
	head = createList(testcase[i].input);
	len = length(head);
	median = findMedian(head,len,i);
	checkresult(i, median);
}

int length(list head)
{
	list a = head;
	int i;
	for (i = 0; a->next != NULL; i++)
		a = a->next;
	return i+2;

}

void checkresult(int i,int median)
{
	if (median == testcase[i].median)
		printf("Pass\n");
	else
		printf("Fail\n");
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