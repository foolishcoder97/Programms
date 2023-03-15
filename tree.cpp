#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node *BuildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }else{
        node *root=new node(d);
        root->left=BuildTree();
        root->right=BuildTree();
        return root;
    }
}
void Print(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
}
void Print_LevelWise(node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *x=q.front();
        q.pop();
        if(x==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
            cout<<x->data<<" ";
            if(x->left!=NULL)
            q.push(x->left);
            if(x->right!=NULL)
            q.push(x->right);
        }
    }
}
void MirrorTree(node *root)
{
    if(root==NULL)
    {
        return;
    }
    swap(root->left, root->right);
    MirrorTree(root->left);
    MirrorTree(root->right);
}
int Height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(Height(root->left),Height(root->right))+1;
}
int DiameterBT(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int op1=DiameterBT(root->left);
    int op2=DiameterBT(root->right);
    int op3=Height(root->left)+Height(root->right)+1;

    return max(op1, max(op2, op3));
}
pair<int, int> Diameter_Optimised(node *root)
{
    pair<int, int>p={0,0};
    if(root==NULL)
    {
        return p;
    }
    pair<int, int> l=Diameter_Optimised(root->left);
    pair<int, int> r=Diameter_Optimised(root->right);
    p.first=max(l.first, r.first)+1;
    int op1=l.first+r.first;
    int op2=l.second;
    int op3=r.second;
    p.second=max(op1, max(op2, op3));

    return p;

}
int main()
{

    node *root=BuildTree();
    cout<<"Pre Order Tree"<<endl;
    Print(root);
    
    cout<<"\nLevel wise Print\n";
    Print_LevelWise(root);

    cout<<"\nMirror of BT \n";
    MirrorTree(root);
    Print_LevelWise(root);

    cout<<"\nHeight of BT = "<<Height(root);
    
    cout<<"\nDiameter of BT = "<<DiameterBT(root);
    cout<<"\n Optimesed Diameter = "<<Diameter_Optimised(root).second;

    return 0;
}