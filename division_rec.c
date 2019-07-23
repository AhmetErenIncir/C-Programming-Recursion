#include <stdio.h>

int div_rec(int number1,int number2){

	if(number1==0 || number1<number2){
		return 0;
	}
	else{
		return (1+div_rec((number1-number2),number2)); //buraya girdiyse num1>num2 dir. En az 1 kere boler.
	}
}

int main(){

	int num1,num2,res;

	printf("Enter two numbers\n");
	scanf("%d%d",&num1,&num2);
	if(num2==0){
		printf("Wrong\n");
	}
	else{
		res = div_rec(num1,num2);
	}
	printf("%d / %d = %d\n",num1,num2,res);
}
