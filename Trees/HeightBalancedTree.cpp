#include<bits/stdc++.h>
using namespace std;

class AVL {
    //data members
    AVL *lchild;
    int data;
    int height;
    AVL *rchild;

public:
    //default constructor
    AVL() {
        this->data=0;
        this->height=0;
        this->lchild=NULL;
        this->rchild=NULL;
    }
    //parameterised constructor
    AVL(int value) {
        this->data=value;
        this->height=1;
        this->lchild=NULL;
        this->rchild=NULL;
    }

    //Member functions
    AVL *insert(AVL *, int);
    int getHeight(AVL *);
    int getBalance(AVL *);
    AVL *leftRotate(AVL *);
    AVL *rightRotate(AVL *);
    void Inorder(AVL *);
    void Preorder(AVL *);
    void Postorder(AVL *);
    int Search(AVL *, int);
};

int AVL::getHeight(AVL *r) {
    if(r==NULL)
        return 0;
    else
        return(max(getHeight(r->lchild),getHeight(r->rchild))+1);
}

int AVL::getBalance(AVL *r){
    return(getHeight(r->lchild)-getHeight(r->rchild));
}

AVL *AVL::leftRotate(AVL *x) {
    AVL *y=x->rchild;
    AVL *temp=y->lchild;
    y->lchild=x;
    x->rchild=temp;
    x->height=max(getHeight(x->lchild), getHeight(x->rchild))+1;
    y->height=max(getHeight(y->lchild), getHeight(y->rchild))+1;
    return y;
}

AVL *AVL::rightRotate(AVL *x) {
    AVL *y=x->lchild;
    AVL *temp=y->rchild;
    y->rchild=x;
    x->lchild=temp;
    x->height=max(getHeight(x->lchild), getHeight(x->rchild))+1;
    y->height=max(getHeight(y->lchild), getHeight(y->rchild))+1;
    return y;
}

AVL *AVL::insert(AVL *r, int val) {
    if(r==NULL)
        return (new AVL(val));
    if(val<r->data)
        r->lchild=insert(r->lchild,val);
    else if(val>r->data)
        r->rchild=insert(r->rchild, val);
    else
        return r;
    r->height=getHeight(r);
    int balance=getBalance(r);
    if(balance<0 && val>r->rchild->data)
        return(leftRotate(r));
    if(balance>0 && val<r->lchild->data)
        return(rightRotate(r));
    if(balance<0 && val<r->rchild->data) {
        r->rchild=rightRotate(r->rchild);
        return(leftRotate(r));
    }
    if(balance>0 && val>r->lchild->data) {
        r->lchild=leftRotate(r->lchild);
        return(rightRotate(r));
    }
    return r;
}
void AVL::Inorder(AVL *r) {
    if (r == NULL)
        return;
    Inorder(r->lchild);
    printf("%-3d", r->data);
    Inorder(r->rchild);
}
void AVL::Preorder(AVL *r) {
    if (r == NULL)
        return;
    printf("%-3d", r->data);
    Preorder(r->lchild);
    Preorder(r->rchild);
}
void AVL::Postorder(AVL *r) {
    if (r == NULL)
        return;
    Postorder(r->lchild);
    Postorder(r->rchild);
    printf("%-3d", r->data);
}
int AVL::Search(AVL *r, int val) {
    if (r == NULL)
        return 0;
    if (val == r->data)
        return 1;
    if (val < r->data)
        Search(r->lchild, val);
    if (val > r->data)
        Search(r->rchild, val);
}
int main() {
    AVL tree, *root=NULL;
    int ch,n;
    while(true) {
        cout<<"\n1. INSERT a node\n2. SEARCH for a node\n3. HEIGHT of tree\n4. Display in INORDER\n5. Display in PREORDER\n6. Display in POSTORDER\nAny other key to EXIT\nEnter your choice = ";
        cin>>ch;
        switch(ch) {
            case 1:
                cout<<"Enter the data to be inserted = ";
                cin>>n;
                root=tree.insert(root, n);
                cout<<"Item inserted";
                break;
            case 2:
                cout<<"Enter the data to be searched = ";
                cin>>n;
                if(tree.Search(root, n))
                    cout<<"Item Present"<<endl;
                else
                    cout<<"Item not presnent"<<endl;
                break;
            case 3:
                cout<<"Height = "<<tree.getHeight(root)<<endl;
                break;
            case 4:
                cout<<"Inorder Format = ";
                tree.Inorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Preorder Format = ";
                tree.Preorder(root);
                cout<<endl;
                break;
            case 6:
                cout<<"Postorder Format = ";
                tree.Postorder(root);
                cout<<endl;
                break;
            default:
                cout<<"Exiting..."<<endl;
                return 0;
        }
    }
}