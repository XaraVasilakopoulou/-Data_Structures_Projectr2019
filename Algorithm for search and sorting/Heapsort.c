#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	clock_t t;
    	int  size, i, j, c, root, temp;

    	printf("\n Enter no of elements :");
	scanf("%d", &size);
	int heap[size];
    	
    	for (i = 0; i < size; i++) heap[i]=rand();
    	for (i = 1; i < size; i++)
    	{
        	c = i;
        	do
        	{
            		root = (c - 1) / 2;

            		if (heap[root] < heap[c]) 
            		{
                		temp = heap[root];
                		heap[root] = heap[c];
                		heap[c] = temp;
            		}

            		c = root;
        	} while (c != 0);
    	}

    	printf("Heap array : \n");

    	for (i = 0; i < size; i++) printf("%d\t ", heap[i]);
	printf("\n");

	t=clock();
    	for (j = size - 1; j >= 0; j--)
    	{
        	temp = heap[0];
        	heap[0] = heap[j]; 
        	heap[j] = temp;
        	root = 0;
        	do
        	{
            		c = 2 * root + 1;
            		if ((heap[c] < heap[c + 1]) && c < j-1)
                	c++;
            		if (heap[root]<heap[c] && c<j)
            		{
                		temp = heap[root];
                		heap[root] = heap[c];
                		heap[c] = temp;
            		}
            		root = c;
        	} while (c < j);
    	}
	t=clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

    	printf("\n The sorted array is : \n");
    	for (i = 0; i <size; i++) printf("\t %d", heap[i]);
	printf("\n");
        printf("Heap sort took %f seconds to execute \n", time_taken);
	

}

