#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Δομή αρχείου εγγραφής
typedef struct data
{
	char am;
	char name;
	char sname;
	char deg;
}data;

//Δομή Δυαδικού δένδρου
typedef struct node
{
	data dedomena;
	struct node * right, * left;
}node; 

//Απεικόνιση Α.1
void inorder(struct node *root , int i) 
{ 
	i=i+1;
    	if (root != NULL) 
    	{	 
        	inorder(root->left,i);
		printf("Στοιχείο %d : %s ",i, root->dedomena.am);  
        	inorder(root->right,i); 
    	}
	else printf("Τέλος \n"); 
} 

//Προσθήκη νέου στοιχείου
void insert(node ** tree, data* val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->dedomena.am = val->am;
	temp->dedomena.name = val->name;
 	temp->dedomena.sname = val->sname;
 	temp->dedomena.deg = val->deg;
        *tree = temp;
    }

    if(strcmp(val->am,(*tree)->dedomena.am)<0)
    {
        insert(&(*tree)->left,val);
    }
    else if(strcmp(val->am,(*tree)->dedomena.am)>0)
    {
        insert(&(*tree)->right,val);
    }

}

//Βοηθητική συνάρτηση για διαγραφή
node*  minValueNode(struct node* node) 
{ 
    	struct node* current = node; 
  
	while (current && current->left != NULL) current = current->left; 
  
	return current; 
}

//Διαγραφή Α.4
node* deleteNode(node* root, char v) 
{  
    	if (root == NULL) return root; 
  
    	if (strcmp(v,root->dedomena.am)<0) 
        	root->left = deleteNode(root->left,v);
   	else if (strcmp(v,root->dedomena.am)>0)
        	root->right = deleteNode(root->right,v); 
    	else
    	{ 
        	if (root->left == NULL) 
        	{ 
            		node *temp = root->right; 
            		free(root); 
            		return temp; 
        	} 
        	else if (root->right == NULL) 
        	{ 
            		struct node *temp = root->left; 
            		free(root); 
            		return temp; 
        	} 
   
		node *temp;
  	      	temp = minValueNode(root->right); 
        	root = temp; 
        	root->right = deleteNode(root->right,temp->dedomena.am); 
    	} 
    	return root; 
}  

//Αναζήτηση Α.2
node* search(node ** tree, char val)
{
    	if(!(*tree))
    	{
		printf("Ο φοιτητής δεν είναι καταχωρημένος!\n");
        	return NULL;
    	}

    	if(strcmp(val,(*tree)->dedomena.am)<0)
    	{
        	search(&((*tree)->left), val);
    	}
    	else if(strcmp(val,(*tree)->dedomena.am)>0)
    	{
        	search(&((*tree)->right), val);
    	}
    	else
    	{
		printf("Ο φοιτητής υπάρχει!\n");
        	return *tree;
    	}
}

//Τροποποίηση Α.3
void modification(node ** tree, int t, char val)
{
        if(!(*tree))
        {
                printf("Το δένδρο είναι άδειο\n");
        }

        if(strcmp(val,(*tree)->dedomena.am)<0)
        {
                search(&((*tree)->left), val);
        }
        else if(strcmp(val,(*tree)->dedomena.am)>0)
        {
                search(&((*tree)->right), val);
        }
        else
        {
		if(t==1)
		{
			char n;
			printf("Δώσε καινούργιο όνομα: \n");
			scanf("%s",n);
			(*tree)->dedomena.name = n;
		}
		else if(t==2)
		{
			char sn;
			printf("Δώσε καινούργιο επίθετο: \n");
                        scanf("%s",sn);
			(*tree)->dedomena.sname = sn;
		}
		else if(t==3)
		{
			char v;
			printf("Δώσε καινούργιο βαθμό στο μάθημα: \n");
                        scanf("%d",v);
			(*tree)->dedomena.deg = v;
		}
		else printf("Λάθος καταχώρηση\n");
        }

}

int A()
{
	FILE *f;
	node *root=NULL;	
	f=fopen("Foitites-Vathmologio-DS.txt","r");
        int i;
        char ps,a,n,s,d;
        data *val=NULL;
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

                val->am=a;
                val->name=n;
                val->sname=s;
                val->deg=d;
                insert(&root,val);

        }
        fclose(f);

	int ep;
	printf("\t MENOU ΕΦΑΡΜΟΓΗΣ:\n1)Απεικόνιση του ΔΔΑ \n 2)Αναζήτηση φοιτητή \n 3)Τροποποίηση στοιχείων φοιτητή \n 4)Διαγραφή φοιτητή \n 5) Έξοδος από εφαρμογή\n");
	printf("Πάτησε ένα νούμερο: \n");
	scanf("%d",ep);		
     		
	while(ep!=5)
	{
		if(ep==1)
		{
			inorder(root,0);
		}
		else if(ep==2)
		{
			char n; 
			printf("Δώσε το ΑΜ του φοιτητή που ψάχνεις\n");
			scanf("%s",n);
			node *tmp=search(&root,n);		
			if(tmp)
			{
				printf("Όνομα: %s \nΕπίθετο: %s \nΒαθμός: %s \n");
			}
		}
		else if(ep==3)
		{
			int t;	
			char val;
			printf("Δώσε το ΑΜ του φοιτητή\n");		
                        scanf("%s",val);

			printf("Σε ποιο στοιχείο θέλετε να κάνετε αλλαγή: 1)Όνομε 2)Επίθετο 3)Βαθμό \n");
			scanf("%d",t);

			modification(&root,t,val);
		}
		else if(ep==4)
		{
			char val;
			node *s;
                        printf("Ποιόν φοιτητή θέλετε να διαγράψετε;\n");
                        scanf("%s",val);
                        s=deleteNode(root,val);

		}
		
		else if((ep!=1)&&(ep!=2)&&(ep!=3)&&(ep!=4)&&(ep!=5))printf("Λάθος!Επιλέξτε ή το 1 ή το 2 ή το 3 ή το 4 και για έξοδο το 5  :)");
		
		printf("\t MENOU ΕΦΑΡΜΟΓΗΣ:\n1)Απεικόνιση του ΔΔΑ \n 2)Αναζήτηση φοιτητή \n 3)Τροποποίηση στοιχείων φοιτητή \n 4)Διαγραφή φοιτητή \n 5) Έξοδος από εφαρμογή\n");
        	printf("Πάτησε ένα νούμερο: \n");
        	scanf("%d",ep);

	}

	return 0;
}


//Απεικόνιση Α.1

void inorder1(node *root , int i)
 
{ 

	i=i+1;
    	
	if (root != NULL)
 
    	{
	 
        	inorder(root->left,i);
		printf("Στοιχείο %d : %s \n ",i, root->dedomena.deg);
        	inorder(root->right,i);
 
    	}
 
}


//Προσθήκη νέου στοιχείου

void insert1(node ** tree, data* val)

{

    	node *temp = NULL;
    	if(!(*tree))
    	{
        	temp = (node *)malloc(sizeof(node));

        	temp->left = temp->right = NULL;
        	temp->dedomena.am = val->am;
		temp->dedomena.name = val->name;
 		temp->dedomena.sname = val->sname;
 		temp->dedomena.deg = val->deg;
        	*tree = temp;
    	}

    	if(strcmp(val->deg,(*tree)->dedomena.deg)<0)
    	{	
        	insert(&(*tree)->left,val);
    	}

    	else if(strcmp(val->deg,(*tree)->dedomena.deg)>0)
    	{
        	insert(&(*tree)->right,val);
    	}
}

//Βρίσκω μικρότερο
node* findMin( node* root)
{

        if (root!= NULL)
        {
                while(root->left!=NULL)
                {
                        root=root->left;
                }
		return root;
        }
        else return root;
}

//Βρίσκω μεγαλύτερο
node* findMax(node* root)
{
        if(root!= NULL)
        {
                while(root->right!=NULL)
                {
                        root=root->right;
                }
		return root;
        }
        else return root;
}

int B()
{
	FILE *f;
        int k;
        printf("1.Εύρεση των φοιτητών με την ΕΛΑΧΙΣΤΗ βαθμολογία\n2.Εύρεση των φοιτητών με την ΜΕΓΙΣΤΗ βαθμολογία\n");
        scanf("%d",k);
	f=fopen("Foitites-Vathmologio-DS.txt","r");
	int i;
	node *tmp=NULL;
        char ps,a,n,s,d;
	node *root=NULL;
        data *val=NULL;

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


		val->am=a;

		val->name=n;

		val->sname=s;

		val->deg=d;

		insert1(&root,val);


        }

        fclose(f);

        if (k==1)
        {
        	tmp=findMin(root);
		printf("Ο μικρότερος βαθμός ανήκει στον %s\t%s\t%s\t και είναι ο %s\n",tmp->dedomena.am,tmp->dedomena.name,tmp->dedomena.sname,tmp->dedomena.deg);
        }
        else if(k==2)
        {
        	tmp=findMax(root);
                printf("Ο μεγαλύτερος βαθμός ανήκει στον %s\t%s\t%s\t και είναι ο %s\n",tmp->dedomena.am,tmp->dedomena.name,tmp->dedomena.sname,tmp->dedomena.deg);

        }

        else printf("Error:Ή το 1 ή το 2 είπαμε!\n");
        return 0;

}

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

int C()
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

int main()
{
	int ep,ep1,x;
	printf("Θέλετε Δυαδικό Δέντρο(1) ή Hashing;\n");
	scanf("%d",ep);
	if(ep==1)
	{
		printf("Θέλετε με τον Α κωδικα(1) ή τον Β ;\n");
		scanf("%d",ep1);
		if(ep1==1) x=A();
		else x=B();
	}
	else x=C();
	
	return 0;
}
	