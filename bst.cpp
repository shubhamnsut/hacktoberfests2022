//WRITTEN BY : VAIBHAV GUPTA

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct treenode{
    int data;
    treenode * lchild;
    treenode * rchild;
} * root=NULL;

// struct stack{
//     int size;
//     int top=-1;
//     treenode * *s;
// };

// void push(stack * st, treenode * x){
//     if(st->top!=st->size){
//         st->top++;
//         st->s[st->top]=x;
//         // cout << "Value entered : "<< st->s[st->top]<< endl;
//     }
// }
// treenode * pop(stack * st){
//     int x=-1;
//     if(st->top!=-1){
//         x=st->s[st->top];
//         st->top--;
//     }
//     return x;
// }
// treenode * peek(stack st, int pos){
//     int x;
//     if(pos<=st.top+1){
//         x=st.s[st.top-pos+1];
//     }
//     return x;
// }
// treenode * stackTop(stack st){
//     return st.s[st.top];
// }
// int isEmpty(stack st){
//     int x=(st.top==-1)?  1 : 0; 
//     return x;
// }
// int isFull(stack st){
//     int x=(st.top>=st.size-1)? 1 : 0; 
//     return x;
// }



void Insert(int key){
    treenode * t=root ; 
    treenode * r, *p;

    if(root==NULL){
        p=new treenode;
        p->data=key;
        p->lchild=p->rchild=NULL;  
        root=p;
        return ;
    }
    while(t!=NULL){
        r=t;
        if(key==t->data) return;
        else if(key<t->data) t=t->lchild;
        else t=t->rchild; 
    }
    p=new treenode;
    p->data=key;
    p->lchild=p->rchild=NULL;  

    if(key>r->data) r->rchild=p;
    else r->lchild=p;
    return;
}

treenode * insertR(treenode * p, int key){
    treenode * t;
    if(p==NULL){
        t=new treenode;
        t->data=key;
        t->lchild=t->rchild=NULL; 
        p=t; 
    }
    if(key<p->data){
        p->lchild=insertR(p->lchild,key);
    }else if(key>p->data){
        p->rchild=insertR(p->rchild, key);
    }
    return p;
}

void preorder(treenode * root){
    if(root){
        cout<< root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void Inorder(treenode * t){
    if(t!=NULL){
        Inorder(t->lchild);
        cout << t->data<< " ";
        Inorder(t->rchild);
    }
}

int height(treenode * p){
    int x,y;
    if(p!=NULL){
        x=height(p->lchild);
        y=height(p->rchild);

        return x>y ? x+1 : y+1;
    }
    return 0;
}

treenode * InPre(treenode * p){
    while(p && p->rchild){
        p=p->rchild;
    }
    return p;
}

treenode * InSucc(treenode * p){
    while(p && p->lchild){
        p=p->lchild;
    }
    return p;
}

treenode * Delete(treenode *t ,int key){

    treenode * q;  
    if(t==NULL) return NULL;
    
    if(t->lchild==NULL && t->rchild==NULL){
        if(t==root)
            root=NULL;
        free(t);
        return NULL;
    }

    
    if(t->data==key) {
        if(height(t->lchild)>height(t->rchild)){
            q=InPre(t->lchild);
            t->data=q->data;
            t->lchild=Delete(t->lchild, q->data);

        }else{
                q=InSucc(t->rchild);
            t->data=q->data;
            t->rchild=Delete(t->rchild, q->data);
        }
    
    }
    else if(key<t->data) t->lchild=Delete(t->lchild,key);
    else t->rchild=Delete(t->rchild,key);

    
    return t;
}

void generateBST(vector<int> arr){
    
    stack<treenode*> stk;

    treenode *p, *t;
    t=new treenode;
    t->data=arr[0];
    t->lchild=t->rchild=NULL;

    p=root=t;

    
    for(int i=1 ; i< arr.size(); i++){
        if(arr[i]<p->data){
            t=new treenode;
            t->data=arr[i];
            t->lchild=t->rchild=NULL; 
            p->lchild=t;
            stk.push(p);
            p=p->lchild;
        }
        else if(arr[i]>p->data && arr[i] < stk.empty() ? 32767 : stk.top()->data){
            t=new treenode;
            t->data=arr[i];
            t->lchild=t->rchild=NULL; 
            p->rchild=t;
            p=p->rchild;
        }else{
            p=stk.top();
            stk.pop();
            i--;
        }
    }
}

int main(){
    
    // Insert(5);
    // Insert(6);
    // insertR(root,3);
    // Delete(root, 4);
    // cout << endl;
    // preorder(root);

    vector<int> v={30, 20, 10, 15, 25, 40, 50, 45};
    generateBST(v);
    preorder(root);


    return 0;

}//main end