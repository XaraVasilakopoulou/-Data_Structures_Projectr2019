#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int [],int);

int main()
{
	clock_t t;
	int i,e,size;

	printf("\n\t------- Insertion sorting method -------\n\n");
 	printf("Enter total number of elements :\n ");
 	scanf("%d",&size);

	int arr[size];

        printf("The array is :\n");
	
 	for(i=0; i<size; i++)
 	{
   		arr[i]=rand();
		printf("%d, \t",arr[i]);
 	}

        printf("\n");
	
	t=clock();

	insertion(arr,size);

	t=clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("\n\t------- Insertion sorted elements -------\n\n");
 	for(i=0; i<size; i++) printf("	%d ",arr[i]);
	printf("\n");
        printf("Insertion-Sort took %f seconds to execute \n", time_taken);

	return 0;
}

void insertion(int array[],int size)
{
	int i,j,t;
	
	for(i=1;i<size;i++)
	{
		t=array[i];
		for(j=i-1;j>=0&&t<array[j];j--)
		{
			array[j+1]=array[j];
			array[j]=t;
		}
	}
}

