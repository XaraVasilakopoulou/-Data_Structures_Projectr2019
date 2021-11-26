#include<stdlib.h>
#include<stdio.h>
#include <string.h>

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

main()
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
