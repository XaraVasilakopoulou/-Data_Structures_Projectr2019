#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int find(int data,int n,int list[] ) 
{
   	int lo = 0;
   	int hi = n - 1;
   	int mid = -1;
   	int comparisons = 1;      
   	int index = -1;

   	while(lo <= hi) 
	{
      		comparisons++;
 
      		mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));

      		if(list[mid] == data) {
         	index = mid;
         	break;
      	} 
	else 
	{
        	 if(list[mid] < data) 
		{ 
            		lo = mid + 1;
         	}
		else 
		{ 
            		hi = mid - 1;
         	}
      		}               
   	}
  
  	 return index;
}

int main() 
{
	clock_t t;
	int x,i,j,n;

	printf("Enter number of elements\n");
        scanf("%d",&n);
        int array[n];

        for ( i = 0 ; i < n ; i++ ) array[i]=i;

        printf("The array is: \n");
        for(i=0;i<n;i++) printf("%d\t",array[i]);
        printf("\n");

	printf("Enter value to find\n");
        scanf("%d",&x);
	
   	t= clock();
   	int location = find(x,n,array);
	t= clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;   	

	if(location != -1) printf("\nElement found at location: %d\n" ,(location+1));
   	else printf("Element not found.\n");
   	printf("Anazhthsh me parembolh took %f seconds to execute \n",time_taken);
   	return 0;
}
