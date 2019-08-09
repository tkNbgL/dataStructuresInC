/*
 UTKU NEBİOGLU 13070001018
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct BINERY_TREE_NODE_s *BINERY_TREE_NODE;
typedef struct BINERY_TREE_NODE_s{
    void *data;
    BINERY_TREE_NODE left;
    BINERY_TREE_NODE right;
}BINERY_TREE_NODE_t[1];

typedef struct BINERY_TREE_s *BINERY_TREE;
typedef struct BINERY_TREE_s{
    BINERY_TREE_NODE head;
}BINERY_TREE_t[1];

BINERY_TREE tree_root(){
    BINERY_TREE root;
    root=(BINERY_TREE)malloc(sizeof(BINERY_TREE_t));
    root->head=NULL;

    return root;
}

BINERY_TREE_NODE init_node(void *data){
    BINERY_TREE_NODE node=(BINERY_TREE_NODE)malloc(sizeof(BINERY_TREE_t));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


/*bunun altında bir fonksyon daha var*/
void *delete_iterative(BINERY_TREE_NODE node, void *data){
	int a=1,b=1;
	int *res;
	BINERY_TREE_NODE temp=(BINERY_TREE_NODE)node;//temp nodun hemen arkasından geliyor
	while(*(int*)data != *(int*)(node->data)){
		if(a<b){//arkasından gelmesi icin boyle bısey yaptım
			if(*(int*)data < *(int*)(temp->data)){
				temp=temp->left;
			}
			if(*(int*)data > *(int*)(temp->data)){
				temp=temp->right;
			}
		}

		if(*(int*)data < *(int*)(node->data)){
			node=node->left;
		}//dolasması ıcın burlar
		if(*(int*)data > *(int*)(node->data)){
			node=node->right;
		}
		b++;
	}

	if(node->left==NULL && node->right==NULL){//nodun left rightı bossa burayı isliyor
		if(temp->left==node){
			temp->left=NULL;
			res=node->data;
			free(node);
			return res;

		}
		if(temp->right==node){
			temp->right=NULL;
			res=node->data;
			free(node);
			return res;
		}
	}

	if(node->left==NULL && node->right!=NULL){//bi tarafi bossa burayi
		if(temp->left==node){
			temp->left=node->right;
			res=node->data;
			free(node);
			return res;
		}
		if(temp->right==node){
			temp->right=node->right;
			res=node->data;
			free(node);
			return res;
		}
	}

	if(node->left!=NULL && node->right==NULL){
		if(temp->left==node){
			temp->left=node->left;
			res=node->data;
			free(node);
			return res;
		}
		if(temp->right==node){
			temp->right=node->left;
			res=node->data;
			free(node);
			return res;
		}
	}

	if(node->left!=NULL && node->right!=NULL){//iki tarafı doluysa burayi
		BINERY_TREE_NODE temp2=(BINERY_TREE_NODE)node;
		if(temp->left==node){
			temp->left=node->left;
			temp2=node->left;
			while(temp2->right!=NULL){
				temp2=temp2->right;
			}
			temp2->right=node->right;
			res=node->data;
			free(node);
			return res;
		}
		if(temp->right==node){
			temp->right=node->right;
			temp2=node->right;
			while(temp2->left!=NULL){
				temp2=temp2->left;
			}
			temp2->left=node->left;
			res=node->data;
			free(node);
			return res;
		}

	}
}

void *delete(BINERY_TREE tree,void *data){
	void *res;
	if(data==NULL){
		printf("error");
	}
	if(*(int*)data == *(int*)(tree->head->data)){
		//burada rootu silmeye calistım ama olmadı maalesef
		BINERY_TREE kok=(BINERY_TREE)tree;
		if(tree->head->right->left==NULL){
			kok->head->right->left=kok->head->left;
			tree->head=kok->head->right;
			res=kok->head->data;
			free(kok);
			return res;
		}
		if(tree->head->right->left!=NULL){
			BINERY_TREE_NODE kok2=(BINERY_TREE_NODE)kok->head->right;
			while(kok2->left!=NULL){
				kok2=kok2->left;
			}
			kok2->left=kok->head->left;
			tree->head=kok->head->right;
			res=kok->head->data;
			free(kok);
			return res;

		}
	}
	else{
		delete_iterative(tree->head,data);
		//burada asıl fonksyona yolluyor
	}
}

void insert_iterative(BINERY_TREE_NODE node, void *data){
    while(node!=NULL){
        if(*(int*)data < *(int*)(node->data)){
            if(node->left == NULL){
                node->left=init_node(data);
                node=NULL;
            }
            else{
                node=node->left;
            }
        }
        else if(*(int*)data > *(int*)(node->data)){
            if(node->right == NULL){
                node->right = init_node(data);
                node=NULL;
            }
            else{
                node=node->right;

            }
        }
        else{
            printf("duplicate data");
        }
    }

}


void insert(BINERY_TREE tree, void *data){
    if(data==NULL){
        printf("invalid data");
    }
    else if(tree->head==NULL){
        tree->head=init_node(data);
    }
    else{
        insert_iterative(tree->head,data);
    }
}


void postorder(BINERY_TREE_NODE node){
	if(node !=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d",*(int*)(node->data));
	}
}

void inorder(BINERY_TREE_NODE node){
	if(node != NULL){
		inorder(node->left);
		printf("%d",*(int*)(node->data));
		inorder(node->right);
	}
}

preorder(BINERY_TREE_NODE node){
	if(node!=NULL){
		printf("%d",*(int*)(node->data));
		preorder(node->left);
		preorder(node->right);
	}
}

void print_tree(BINERY_TREE_NODE node,int x){
	int i;
	if(node != NULL){
		print_tree(node->right,x+1);
		for(i=1; i<x; i++){
			printf("   ");
		}
		printf("%d",*(int*)(node->data));
		printf("\n");
		print_tree(node->left,x+1);
	}
}

int main()
{
	int x=2;
    BINERY_TREE s;
    int a,b,c,d,e,f,g,n,m,k,l,i;
    a=5;
    b=4;
    c=6;
    e=3;
    f=8;
    g=10;
    n=9;
    m=11;
    k=12;
    l=7;
    s=tree_root();
    insert(s,&a);
    insert(s,&b);
    insert(s,&c);
    insert(s,&e);
    insert(s,&f);
    insert(s,&g);
    insert(s,&n);
    insert(s,&m);
    insert(s,&k);
    insert(s,&l);
    printf("ilk hali\n");
    print_tree(s->head,x);
    printf("\n\n\n");
    delete(s,&e);
    delete(s,&k);
    printf("uclarindan iki node sildim\n\n");
    print_tree(s->head,x);
    printf("\n\n\n");
    printf("iki kardesi olan nodu silcem simdi\n\n");
    delete(s,&g);
    print_tree(s->head,x);
    printf("\n\n");
    printf("tek kardesi olan nodu sildim\n\n");
    delete(s,&c);
    print_tree(s->head,x);

}


