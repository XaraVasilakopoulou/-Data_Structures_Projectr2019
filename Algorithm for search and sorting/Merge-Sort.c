#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int [],int ,int ,int );
void part(int [],int ,int );

int main()
{
	clock_t t;
 	int i,size;

 	printf("\n\t------- Merge sorting method -------\n\n");

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
	size=size-1;
        t=clock();
 	part(arr,0,size);
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;

 	printf("\n\t------- Merge sorted elements -------\n\n");

 	for(i=0; i<size; i++) printf("%d ",arr[i]); 
	printf("\n");
	printf("Merge-Sort took %f seconds to execute \n", time_taken);

 	return 0;
}


void part(int arr[],int min,int max)
{
 	int mid;

 	if(min<max)
 	{
   		mid=(min+max)/2;
   		part(arr,min,mid);
   		part(arr,mid+1,max);
   		merge(arr,min,mid,max);
 	}
}


void merge(int arr[],int min,int mid,int max)
{
  	int tmp[30];
  	int i,j,k,m;
  	j=min;
  	m=mid+1;

  	for(i=min; j<=mid && m<=max ; i++)
  	{
     		if(arr[j]<=arr[m])
     		{
         		tmp[i]=arr[j];
         		j++;
     		}

     		else
     		{
         		tmp[i]=arr[m];
         		m++;
     		}
  	}

  	if(j>mid)
  	{
     		for(k=m; k<=max; k++)
     		{
         		tmp[i]=arr[k];
         		i++;
     		}
  	}

  	else
  	{
     		for(k=j; k<=mid; k++)
     		{
        		tmp[i]=arr[k];
        		i++;
     		}
  	}

  	for(k=min; k<=max; k++) arr[k]=tmp[k];
}

