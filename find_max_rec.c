#include <stdio.h>

int find_max_rec(int array[], int size){
	int i,j,max;
	max = array[0];
	for(i=1 ; i<size ; i++){
		for(j=i ; j<size ; j++){
			if(array[j]>max){
				max = array[j];
			}
		}
	}
	return max;
}

int main(){

	int size,max;

	printf("Enter the size of array\n");
	scanf("%d",&size);
	int array[size];

	printf("Enter the elements of array\n");
	for(int i=0 ; i<size ;i++){
		scanf("%d",&array[i]);
	}

	max = find_max_rec(array,size);

	printf("Max : %d\n",max);
}
