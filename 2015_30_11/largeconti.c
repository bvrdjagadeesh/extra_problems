#include<stdio.h>
struct array
{
	int *array;
	int len;
	int sum;
}
testcase[4] = {
	{ (int[4]){ 1,2,-3,3 }, 4,3},
	{ (int[4]){-1,-2,3,-4},4,3},
	{ (int[4]){0,-1,0,-2}, 4, 0},
	{ (int[5]){0, 2, 5, -10, 9}, 5, 9 }
};

void start(int);
int gethighestsequence(int*, int);
void checkresult(int, int);

void main(){
	for (int i = 0; i < 4;i++)
		start(i);
	getchar();
}

void start(int i){
	int result;
	result = gethighestsequence(testcase[i].array, testcase[i].len);
	checkresult(result, testcase[i].sum);
}
int gethighestsequence(int* array, int len){
	int sum = 0,cursum=0,a=0,b=0,c=0;
	for ( int i = 0; i < len; i++) {
		cursum += array[i];
		if (cursum > sum) {
			sum = cursum;
			a = c;
			b = i;
		}
		if (cursum < 0) {
			cursum = 0;
			c = i + 1;
		}
	}
	return sum;
}
void checkresult(int sum,int result) {
	if (sum == result)
		printf("\nPass");
	else
		printf("\nFail");
}