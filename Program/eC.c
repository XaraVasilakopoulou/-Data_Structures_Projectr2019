#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash *hashTable = NULL;
int eleCount = 10;

typedef struct node 
{
	char am;
	char name;
	char sname;
	char deg;
	struct node *next;
}node;

typedef struct hash 
{
	node *head;
	int count;
}hash;

node * createNode(char am, char name, char sname,char deg) 
{
	node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->am = am;
	newnode->name = name;
	newnode->sname = sname;
	newnode->sname = sname;
	
	newnode->next = NULL;

	return newnode;
}

void insertToHash(char am,char name,char sname,char deg ) 
{
	int hashIndex = am % eleCount;
	struct node *newnode = createNode(am,name,sname,deg);	

	if (!hashTable[hashIndex].head) 
	{
		hashTable[hashIndex].head = newnode;
		hashTable[hashIndex].count = 1;
		return;
	}
	
	newnode->next = (hashTable[hashIndex].head);
	
	hashTable[hashIndex].head = newnode;
	hashTable[hashIndex].count++;
	return;
}

//Τροποποίηση Α.3

void modification( int t, char am)
{
	int hashIndex =[ASCII(am[0])+ASCII(am[1])+ASCII(am[2])+ASCII(am[3])+ASCII(am[4])+ASCII(am[5])+ASCII(am[6])+ASCII(am[7])] % eleCount, flag = 0;
        struct node *myNode;
        myNode = hashTable[hashIndex].head;
        if (!myNode)
        {
                printf("Search element unavailable in hash table\n");
                return;
        }
        while (myNode != NULL)
        {
                if (strcmp(myNode->am,am)==0)
                {
			if(t==1)
			{

				char n;
			
				printf("Δώσε καινούργιο όνομα: \n");			
				scanf("%s",n);			
				myNode->name = n;
			}

			else if(t==2)
			{

				char sn;

				printf("Δώσε καινούργιο επίθετο: \n");
            			scanf("%s",sn);
				myNode->sname = sn;

			}

			else if(t==3)
			{
				char v;

				printf("Δώσε καινούργιο βαθμό στο μάθημα: \n");
            			scanf("%d",v);
				myNode->deg = v;

			}
			else printf("Λάθος καταχώρηση\n");
                        flag = 1;
                        break;
                }
                myNode = myNode->next;
        }
        if (!flag) printf("Search element unavailable in hash table\n");

}

void deleteFromHash(char am) 
{
        int hashIndex =[ASCII(am[0])+ASCII(am[1])+ASCII(am[2])+ASCII(am[3])+ASCII(am[4])+ASCII(am[5])+ASCII(am[6])+ASCII(am[7])] % eleCount, flag = 0;
	struct node *temp, *myNode;

	myNode = hashTable[hashIndex].head;
	
	if (!myNode) 
	{
		printf("Given data is not present in hash Table!!\n");
		return;
	}

	temp = myNode;
	while (myNode != NULL) 
	{
		/* delete the node with given key */
		if(strcmp(myNode->am,am)==0) 
		{
			flag = 1;
			if (myNode == hashTable[hashIndex].head) hashTable[hashIndex].head = myNode->next;
			else temp->next = myNode->next;

			hashTable[hashIndex].count--;
			free(myNode);
			break;
		}
		temp = myNode;
		myNode = myNode->next;
	}
	if (flag) printf("Data deleted successfully from Hash Table\n");
	else  printf("Given data is not present in hash Table!!!!\n");
	    
	return;
}

void searchInHash(char am) 
{
    	int hashIndex =[ASCII(am[0])+ASCII(am[1])+ASCII(am[2])+ASCII(am[3])+ASCII(am[4])+ASCII(am[5])+ASCII(am[6])+ASCII(am[7])] % eleCount, flag = 0;
	struct node *myNode;	    
	myNode = hashTable[hashIndex].head;
	if (!myNode)
	{
		printf("Search element unavailable in hash table\n");
	        return;
	}
	while (myNode != NULL) 
	{
	        if (strcmp(myNode->am,am)==0) 
		{
	        	printf("VoterID  : %s\n", myNode->am);
	            	printf("Name     : %s\n", myNode->name);
			printf("Subname  : %s\n",myNode->sname);
	            	printf("Degree   : %s\n", myNode->deg);
	            	flag = 1;
	            	break;
	        }
        	myNode = myNode->next;
	}
	if (!flag) printf("Search element unavailable in hash table\n");
	    
	return;
	
}

int main()
{
	FILE *f;
	int ep;
	printf("\t MENOU ΕΦΑΡΜΟΓΗΣ:\n1)Αναζήτηση φοιτητή \n 2)Τροποποίηση στοιχείων φοιτητή \n 3)Διαγραφή φοιτητή \n 4)Έξοδος\n ");
	printf("Πάτησε ένα νούμερο: \n");

	scanf("%d",ep);
	f=fopen("Foitites-Vathmologio-DS.txt","r");

        int i;

        char ps,a,n,s,d;

        node *val=NULL;

        for(i=0;i<19;i++)

       	{

		ps=getc(f);

		a=ps;

		while(strcmp(ps,"\0")!=0)

		{

			ps=getc(f);

			a=a+ps;

		}

		ps=getc(f);

		n=ps;

		while(strcmp(ps,"\0")!=0)

		{

			ps=getc(f);

			n=n+ps;

		}

     		
		ps=getc(f);

		s=ps;

		while(strcmp(ps,"\0")!=0)

		{

			ps=getc(f);

			s=s+ps;

		}
		
		ps=getc(f);

		d=ps;

		while(strcmp(ps,"\0")!=0)

		{

			ps=getc(f);

			d=d+ps;

		}

		insertToHash(a,n,s,d);

        }

        fclose(f);


	while(ep!=4)

	{
		if(ep==1)

		{
			char n;
 
			printf("Δώσε το ΑΜ του φοιτητή που ψάχνεις\n");

			scanf("%s",n);

			search(n);
			

		}

		else if(ep==2)

		{
			int t;
			char val;
			
			printf("Δώσε το ΑΜ του φοιτητή\n");
			scanf("%s",val);

			printf("Σε ποιο στοιχείο θέλετε να κάνετε αλλαγή: 1)Όνομα 2)Επίθετο 3)Βαθμό \n");
			scanf("%d",t);
			modification(t,val);
			

		}

		else if(ep==3)

		{

			char val;
			
            		printf("Ποιόν φοιτητή θέλετε να διαγράψετε;\n");
            		scanf("%s",val);
            		deleteFromHash(val);

		}
		
		else printf("Λάθος!Επιλέξτε ή το 1 ή το 2 ή το 3 και για έξοδο το 4  :)");

		printf("\t MENOU ΕΦΑΡΜΟΓΗΣ:\n1)Αναζήτηση φοιτητή \n 2)Τροποποίηση στοιχείων φοιτητή \n 3)Διαγραφή φοιτητή \n 4)Έξοδος\n ");
		printf("Πάτησε ένα νούμερο: \n");
		scanf("%d",ep);


	}



	return 0;
}
