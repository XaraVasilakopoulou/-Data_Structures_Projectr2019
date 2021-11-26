#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int bisSearch (int* arr, int sizeN, int key) 
{
	int s;
    	int left = 1;
    	int right = sizeN;
	int size = (right - left)-1;
	int next =(size*(key-arr[left])/(arr[right]-arr[left]));

	do
	{
                s=sqrt(size);
		int i = 0;
        	size = right - left+1;
		if(size<=3) break;
        	if (key >= arr[next])
	 	{  
          		while (key > arr[next+i*s-1])
	    		{
                		i=i*2;
            		}
            		right = next + i*s;
            		left  = next + (i-1)*s;
         	}

        	else if (key < arr[next])
	 	{	
            		while (key < arr[next -i*s+1])
	    		{
                		++i;
            		}
            		right = next - (i-1)*s;
            		left  = next - i*s;
        	}
        	next =left+((right-left+1)*(key-arr[left]))/(arr[right]-arr[left]);
   	}
	while (key != arr[next]);
	
	int i;

	if(sizeN<=3)
	{
		for(i=0;i<sizeN;i=i*2)
		{
			if(arr[i]==key) return i;
		}
		return -1;
	}
	else
	{
    		if (key = arr[next]) return next;
		else return -1;
	}
}

int main()
{
	clock_t t;
        int i,j,l,r, n, search,s;
	
	printf("Enter number of elements\n");
        scanf("%d",&n);
        int array[n];

        for ( i = 0 ; i < n ; i++ ) array[i]=i;

        printf("The array is: \n");
        for(i=0;i<n;i++) printf("%d\t",array[i]);
        printf("\n");

        printf("Enter value to find\n");
        scanf("%d",&search);

	t=clock();
	s = bisSearch (array,n,search);
	t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

	if(s==-1) printf("Not found! %d is not present in the list.\n", search);
	else printf("%d is present in the list, at %d position. \n",search,s);
	printf("Diadykh anazhthsh me parembolh took %f seconds to execute \n",time_taken);

	return 0;
}
