#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	clock_t t;
   	int i,j,swap,search, n;

   	printf("Enter the number of elements in array\n");
   	scanf("%d",&n);
	int array[n];

   	for (i = 0; i < n; i++) array[i]=i;
 
	printf("The array is: \n");
	for(i=0;i<n;i++) printf("%d\t",array[i]);
	printf("\n");

   	printf("Enter the number to search\n");
   	scanf("%d", &search);
	
	t = clock();
   	for (i = 0; i < n; i++)
   	{
      		if (array[i] == search) 
      		{
         		printf("%d is present at location %d.\n", search, i+1);
         		break;
      		}
   	}
	t = clock() - t; 
    	double time_taken = (double)((double)t)/(CLOCKS_PER_SEC);

   	if (i== n) printf("%d is not present in array.\n", search);
	printf("Grammikh anazhthsh took %f seconds to execute \n",time_taken);
	
   	return 0;
}
