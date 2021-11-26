#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t t;
   	int i,j, first, last, middle, n, search,swap;

   	printf("Enter number of elements\n");
   	scanf("%d",&n);
	int array[n];
	
   	for ( i = 0 ; i < n ; i++ ) array[i]=i;

        printf("The array is: \n");
        for(i=0;i<n;i++) printf("%d\t",array[i]);
        printf("\n");

   	printf("Enter value to find\n");
   	scanf("%d",&search);

   	first = 0;
   	last = n - 1;
   	middle = (first+last)/2;

	t=clock();
   	while( first <= last )
   	{
      		if ( array[middle] < search ) first = middle + 1;
      		
		else if ( array[middle] == search )
      		{
         		printf("%d found at location %d.\n", search, middle+1);
         		break;
      		}
      		
		else last = middle - 1;

      		middle = (first + last)/2;
   	}
	t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

  	if ( first > last ) printf("Not found! %d is not present in the list.\n", search);
	printf("Dadykh anazhthsh took %f seconds to execute \n",time_taken);
   	return 0;
}

