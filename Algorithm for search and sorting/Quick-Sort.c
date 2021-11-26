#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick(int [], int, int);

int main()
{
	clock_t t;
	int i, r, l, p, size;
	
	printf("Enter number of elements\n");
   	scanf("%d",&size);
        int arr[size+1];

        printf("The array is :\n");

	for(i=0; i<size; i++)
        {
                arr[i]=rand();
                printf("%d, \t",arr[i]);
        }
	printf("\n");

   	l = 0;
   	r = size-1;
	
	t=clock();
	quick(arr,l,r);
	t=clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;	

	printf("\n\t-------- Quick sorted elements --------\n\n");
	for(i=0;i<size;i++) printf("\t %d",arr[i]);
	printf("\n");
	printf("Quick-Sort took %f seconds to execute \n", time_taken);

	return 0;
}

void quick(int array[], int left, int right)
{
	int left_arrow, right_arrow, pivot, x;
	left_arrow = left;
	right_arrow = right;
	pivot = array[(left+right)/2];
	
	do
	{
		while(array[right_arrow]>pivot) right_arrow = right_arrow--;
		while(array[left_arrow]<pivot) left_arrow = left_arrow ++;
		if(left_arrow<=right_arrow)
		{
			x = array[right_arrow];
			array[right_arrow] = array[left_arrow];
			array[left_arrow] = x;
			
			right_arrow = right_arrow--;
			left_arrow = left_arrow++;
		}
	}while(right_arrow>=left_arrow);

	if(left<right_arrow) quick(array, left, right_arrow);
	if(right>left_arrow) quick(array, left_arrow, right);
}
