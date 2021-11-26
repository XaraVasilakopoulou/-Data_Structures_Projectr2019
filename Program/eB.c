#include<stdlib.h>
#include <string.h>
#include<stdio.h>


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

void inorder(node *root , int i)
 
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

main()
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

		insert(&root,val);


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

