#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble(int*,int);

int main()
{
        int x;
        clock_t t;

        printf("Enteer number of elements\n");
        scanf("%d",&x);

        int array[x], i, j, swap;

        for (i=0; i<x; i++) array[i] = rand();

        printf("The array is :\n");
        for (i=0; i<x; i++) printf("%d, \t",array[i]);
        printf("\n");

        t=clock();
	
	bubble(array,x);	

        t=clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        printf("Sorted list in ascending order:\n");
        for (i=0; i<x; i++ ) printf("%d\t", array[i]);
        printf("\n");

        printf("Bubble-Sort took %f seconds to execute \n", time_taken);

        return 0;
}

int bubble(int array[],int x)
{
	int i,j,swap;
		
	for (i=0; i<(x-1); i++)
	{
		for (j=0 ; j<(x-i-1); j++)
		{
			if (array[j] > array[j+1])
                	{ 
				swap = array[j];
				array[j] = array[j+1];
				array[j+1] = swap;
                	}
		}
	}
	return 0;
}
