#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
struct node
{
    int data,h;
    struct node *left,*right;
};
int count=0,g=0,m;
struct node *createnode(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=0;
    count++;
    return newnode;
}
struct node *createbst(struct node *root,int data)
{
    if (root==0)
    {
        return createnode(data);
    }
    if (root->data<data)
    {
        root->right=createbst(root->right,data);
    }
    else
    {
        root->left=createbst(root->left,data);
    }
    return root;    
}
void Inorder(struct node *root)
{
    if(!root)
        return;
    Inorder(root->left);
    printf(" %d",root->data);
    Inorder(root->right);
}
void Preorder(struct node *root)
{
    if(!root)
        return;
    printf(" %d",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(struct node *root)
{
    if(!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf(" %d",root->data);
}
int sum(struct node *r)
{
    if(!r)
        return 0;
    return (sum(r->left)+sum(r->right))+r->data;
}
int search(struct node *r,int data)
{
    if(r==0)
        return 0;
    if(r->data==data)
    {
        printf("Element found");
        return 1;
    }
    else if(g==0 && r->data>data)
    {
        g=search(r->left,data);
        return 1;
    }
    else if(g==0 && r->data<data)
    {
         g=search(r->right,data);
         return 1;
    }
    else
        return 0;
}
int hot(struct node *r)
{
    if(!r)
        return 0;
    return (max(hot(r->left),hot(r->right)))+1;
}
int dot(struct node *r)
{
    if(!r)
        return 0;
    int lh=hot(r->left);
    int rh=hot(r->right);
    int cdia=lh+rh+1;
    return max(max(cdia,dot(r->left)),dot(r->right));
}
struct node *q[100];
int f=-1,r=-1;
void enqueue(struct node *data)
{
    if (f==-1)
    {
        f=r=0;
        q[r]=data;
    }
    else
        q[++r]=data;
}
void dequeue()
{
    if (f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
}
void leveltraversal(struct node *root)
{
    enqueue(root);
    while (f!=-1)
    {
        root=q[f];
        dequeue();
        printf(" %d",root->data);
        if (root->left!=0)
            enqueue(root->left);
        if (root->right!=0)
            enqueue(root->right);
    }
}
void levelview(struct node *root)
{
    enqueue(root);
    enqueue(0);
    while (f!=-1)
    {
        root=q[f];
        dequeue();
        if (root==0)
        {
            if (f==-1)
            {
                return;
            }
            printf("\n");            
            enqueue(0);
            continue;
        }
        printf(" %d",root->data);
        if (root->left!=0)
        {
            enqueue(root->left);
        }
        if (root->right!=0)
        {
            enqueue(root->right);
        }  
    }
}
void leftview(struct node *root)
{
    enqueue(0);
    enqueue(root);
    while (f!=-1)
    {
        root=q[f];
        dequeue();
        if (root==0)
        {
            if (f==-1)
            {
                return;
            }
            root=q[f];
            dequeue();
            printf("\n%d",root->data);            
            enqueue(0);
        }
        if (root->left!=0)
        {
            enqueue(root->left);
        }
        if (root->right!=0)
        {
            enqueue(root->right);
        }  
    }
}
void rightview(struct node *root)
{
    enqueue(0);
    enqueue(root);
    while(f!=-1)
    {
        struct node *temp=q[f];
        dequeue();
        if(temp==0)
        {
            if(f==-1)
                return;
            temp=q[f];
            dequeue();
            printf("\n%d",temp->data);
            enqueue(0);
        }
        if(temp->right)
            enqueue(temp->right);
        if(temp->left)
            enqueue(temp->left);
    }
}
int map[100],lsize=0;

void topview(struct node *root)
{ 
    lsize=hot(root);
    root->h=lsize;
    for(int i=0;i<2*lsize;i++)
        map[i]=-1;
    enqueue(root);
    while (f!=-1)
    {
        root=q[f];
        dequeue();
        if(map[root->h]==-1)
            map[root->h]=root->data;
        if(root->left)
        {
            enqueue(root->left);
            root->left->h=root->h-1;
        }
        if(root->right)
        {
            enqueue(root->right);
            root->right->h=root->h+1;
        }
    }
    
    for (int i = 0; i < 2*lsize; i++)
    {
        if (map[i]!=-1)
        {
            printf("  %d",map[i]);
        }
        
    }
}
void bottomview(struct node *root)
{
    lsize=hot(root);
    for(int i=0;i<2*lsize;i++)
        map[i]=-1;
    enqueue(root);
    while (f!=-1)
    {
        root=q[f];
        dequeue();
        map[root->h]=root->data;
        if(root->left)
        {
            enqueue(root->left);
            root->left->h=root->h-1;
        }
        if(root->right)
        {
            enqueue(root->right);
            root->right->h=root->h+1;
        }
    }  
    for (int i = 0; i < 2*lsize; i++)
    {
        if (map[i]!=-1)
        {
            printf("  %d",map[i]);
        }
        
    }
    
}

struct node *leftmostinright(struct node *root)
{
    while(root->left!=0)
    {
        root=root->left;
    }
    return root;
}
struct node *deletenode(struct node *root,int key)
{
    if(root==0)
        return 0;
    if(root->data<key)
        root->right=deletenode(root->right,key);
    else if(root->data>key)
        root->left=deletenode(root->left,key);
    else if(root->data==key)
    {
        struct node *temp;
        if(root->left==0)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==0)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=leftmostinright(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
//               10
//              /   \ 
//             5     15
//           /  \    / \ 
//          4    8  12  20
//              /    \ 
//             7      13
//
//
int main()
{
    struct node *root=0;
    int a[]={10,5,15,4,8,7,12,20,13};
    int n=sizeof(a)/sizeof(a[0]),i,d,key,t,h;
    float avg;
    while(1)
    {
        int ch;
        printf("\nEnter\n1 for finding root of bst\t2 for counting number of nodes\n3 for sum of nodes\t\t4 for average of nodes\n5 for Inorder of BST\t\t6 for Preorder of BST\n7 for Postorder of BST\t\t8 for Height of BST\n9 for Diameter of BST\t\t10 for searching nodes\n11 for level traversal\t\t12 for level view\n13 for left view\t\t14 for right view\n15 for top view\t\t\t16 for bottom view\n17 to delete a node\t\t0 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                for ( i = 0; i < n; i++)
                    root=createbst(root,a[i]);
                    printf("\nroot of bst %d \n",root->data);
                break;
            case 2:
                printf("\nTotal nodes is %d",count);
                break;
            case 3:
                printf("\nsum=%d",sum(root));
                break;
            case 4:
                avg=(float)sum(root)/count;
                printf("Average=%f",avg);
                break;
            case 5:
                printf("\nInorder of tree\n");
                Inorder(root);
                break;
            case 6:
                printf("\nPreorder of tree\n");
                Preorder(root);
                break;
            case 7:
                printf("\nPostorder of tree\n");
                Postorder(root);
                break;
            case 8:
                printf("\nHeight of tree=%d",hot(root));
                break;
            case 9:
                printf("\nDiameter of tree=%d",dot(root));
                break;
            case 10:
                printf("\nEnter data for searching");
                scanf("%d",&d);
                g=search(root,d);
                if(g!=1)
                    printf("Not found");
                break;
            case 11:
                printf("\nLevel traversal of tree\n");
                leveltraversal(root);
                break;
            case 12:
                printf("\nLevel view of tree\n");
                levelview(root);
                break;
            case 13:
                printf("\nLeft view of tree\n");
                leftview(root);
                break;
            case 14:  
                printf("\nRight view of tree\n");
                rightview(root);
                break;
            case 15:
                printf("\nTop view of tree\n");
                topview(root);
                break;
            case 16:
                printf("\nBottom view of tree\n");
                bottomview(root);
                break;
            
            case 17:
                printf("\nEnter the data to be deleted:");
                scanf("%d",&key);
                root=deletenode(root,key);
                //printf("\nNODE deleted");
                break;
            case 0:
                exit(0);
            default:
                printf("invalid input");
                break;
        }
    }
}