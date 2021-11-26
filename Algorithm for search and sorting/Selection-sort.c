#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int [],int);

int main()
{
	clock_t t;
	int i,size;
	
	printf("\n\t------- Selection sorting method -------\n\n");
 	printf("Enter total no. of elements : ");
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
	selection(arr,size);
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("\n\t------- Selection sorting result -------\n\n");
	for(i=0;i<size;i++) printf(" %d ",arr[i]);
	printf("\n");
	
	printf("Selection-Sort took %f seconds to execute \n", time_taken);

	return 0;
	
}

void selection(int array[], int size)
{
	int i,j,min,pmin,y;
	
	for(i=0;i<size;i++)
	{
		min=array[i];
		pmin=i;
		for(j=i+1;j<size;j++)
		{
			if(min>array[j]) 
			{
				min=array[j];
				pmin=j;
			}
		}
		y=array[i];
		array[i]=min;
		array[pmin]=y;
	}
}
