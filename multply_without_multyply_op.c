#include <stdio.h>

int multp_rec(int number1,int number2){
	int sum;
	if(number2==0){
		sum = 0;
	}
	else{
		sum = number1 + multp_rec(number1,number2-1);
	}
	return sum;
}


int main(){
	int num1,num2;

	printf("Enter number 1 and number 2\n");
	scanf("%d%d",&num1,&num2);

	printf("%d x %d = %d\n",num1,num2,multp_rec(num1,num2));


}
