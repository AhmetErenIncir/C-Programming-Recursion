#include <stdio.h>
#include <stdlib.h>

#define EXIT -1 //SENTINEL
#define MAX_SIZE_OF_ARRAY 100

//Functions definitions.
void menu();
void part1();
void part2();
void part3();
void part4();
void part5();
int common(int number1 , int number2);
char find_first_capital(char* str);
int check_equal(int number , int num_of_digit);
int find_digit_number(int number);
void merge(int array[],int  tail,int  mid, int head );
void merge_sort( int array[],int tail, int head );
double power_of_numbers(int num1 , int num2);

//Main Function
int main(){
	menu(); // Main has only menu function.
}
void menu() {

	int select;

	//Gets selection from user.
	printf("\nEnter the part of program\n");
	printf("1) Part 1 \n2) Part 2\n3) Part 3\n4) Part 4\n5) Part 5\n");
	printf("Enter '-1' to exit\n");
	scanf("%d",&select);

	//Checking exit condition after each part.
	while(select != EXIT){
		if(select == 1){
			part1();
		}
		else if(select == 2){
			part2();
		}
		else if(select == 3){
			int number;
			printf("Enter the number\n");
			scanf("%d",&number);
			part3(number);
		}
		else if(select == 4){
			part4();
		}
		else if(select == 5){
			part5();
		}
		else{
			printf("Invalid Entry!\n");
		}
		printf("Enter the part of program\n");
		printf("1) Part 1 \n2) Part 2\n3) Part 3\n4) Part 4\n5) Part 5\n");
		printf("Enter '-1' to exit\n");
		scanf("%d",&select);
	}
}

void part1() {
	int number1 , number2;

	printf("Enter 2 positive number to find\n");
	scanf("%d%d",&number1,&number2);

	//Numbers should be positive for part 1.
	if(number1 < 0 || number2 < 0){
		printf("You entered negative number. Please check your entry\n");
	}

	printf("Multipliers of numbers is : %d\n" , common(number1,number2) );
}

//Commong fuction calculates the common factors recursively.
int common(int number1 , int number2){
	if(number2 != 0){
		return common(number2 , number1%number2 );
	}
	else{
		return number1;
	}
}

void part2() {
	int i,size,array[MAX_SIZE_OF_ARRAY];

	//User enters array size .
	printf("Enter the length of the list : ");
	scanf("%d",&size);

	printf("Enter the elements of list : \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]); //User enters array elements.
	}
	//merge_sort function divides the list into two lists recursively until it can no more be divided.
	merge_sort( array,0, size-1);

	//Prints array elements after sorting process.
	for( i = 0 ; i<size ; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void merge_sort( int array[],int tail, int head )
{
	int mid;
	if( tail != head )
	{
		//Divides the list into two lists recursively until it can no more be divided.
		mid = (tail+head)/2;
		merge_sort(array ,tail , mid );
		merge_sort( array,mid+1, head );
		merge(array,tail, mid, head );
	}
}

//Sorting...
void merge(int array[],int  tail,int  mid, int head )
{
	int temp_array1[MAX_SIZE_OF_ARRAY] , i = tail , j = mid +1 , k = tail;

	while( (i <= mid) && (j <=head) )
	{
		if(array[i] <= array[j])
			temp_array1[k++] = array[i++] ;
		else
			temp_array1[k++] = array[j++] ;
	}

	while( i <= mid )
		temp_array1[k++]=array[i++];

	while( j <= head )
		temp_array1[k++]=array[j++];

	for(i= tail; i <= head ; i++)
		array[i]=temp_array1[i];

}

void part3(int number){

	//If number is 1 print just 1.
	if(number == 1){
		printf("%d",number);
	}
	//If number is even pass again half of number to function.
	else if(number %2 == 0){
		printf("%d ",number);
		part3(number/2);
	}
	//If number is odd pass again (3*number+1) to function.
	else{
		printf("%d ",number);
		part3( (3 * number) +1);
	}
}

void part4(){

	int num , sum , number_of_digit;

	printf("Enter the number to check it fits with formula\n");
	scanf("%d",&num);

	number_of_digit = find_digit_number(num);
	sum = check_equal(num,number_of_digit);

	if(num == sum){
		printf("Equal\n");
	}
	else{
		printf("Not Equal\n");
	}
}

int find_digit_number(int num){
	int digits = 0;
	while(num > 0){
		num = num / 10;
		digits++;
	}
	return digits;
}

int check_equal(int num , int num_of_digit){
	if(num == 0) {
		return 0;
	}
	return ( power_of_numbers((num%10),num_of_digit) + check_equal( (num/10) , num_of_digit) );
}

double power_of_numbers(int num1 , int num2){
	int i;
	double res = 1;
	for(i=0 ; i<num2 ; i++){
		res *= num1;
	}
	return res;
}

void part5(){

	char str[MAX_SIZE_OF_ARRAY] , ch;

	printf("Enter the string without spaces to find first capital letter\n");
	scanf("%s",str);

	ch = find_first_capital(str); // Function returns first capital number.

	if(ch == '!'){
		//If string does not have any capital letter it returns '!'.
		printf("Your string does not have any capital letter\n");
	}
	else{
		printf("First capital letter in your string is %c\n",ch);
	}
}

char find_first_capital(char* str){
	if(*str >= 'A' && *str <= 'Z' ){
		return *str;
	}
	else if(*str == '\0'){
		return '!'; //If string does not have any capital number it returns '!'.
	}
	else{
		return find_first_capital(str+1); //Checking all string letters until find capital letter.
	}
}
