#include"binarysearchtree.h"
//#include"quetype.h"
#include <iostream>
using namespace std;

template <class ItemType>
TreeType<ItemType>::TreeType()
{
    root=NULL;
}
template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
{
    if(tree!=NULL)
     {
         Destroy(tree->left);
         Destroy(tree->right);
         delete tree;
         tree=NULL;
     }
}
template <class ItemType>
TreeType<ItemType>::~TreeType()
{
    Destroy(root);
}
template <class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
    Destroy(root);
}
template <class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
    return root==NULL;
}
template <class ItemType>
bool TreeType<ItemType>::IsFull()
{
    TreeNode<ItemType>*location;
    try{
    location=new TreeNode<ItemType>;
    delete location;
    return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
int CountNodes(TreeNode<ItemType>*tree)
{
    if(tree==NULL)
        return 0;
    else
        return CountNodes(tree->left)+CountNodes(tree->right)+1;
}
template <class ItemType>
int TreeType<ItemType>::LengthIs()
{
    return CountNodes(root);
}
template <class ItemType>
void Retrieve(TreeNode<ItemType>*tree,ItemType& item,bool& found)
{
    if(tree==NULL)
        found=false;
    else if(item<tree->info)
        Retrieve(tree->left,item,found);
    else{
        item=tree->info;
        found=true;
    }
}
template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item,bool& found)
{
    Retrieve(root,item,found);
}
template <class ItemType>
void insert(TreeNode<ItemType>*& tree,ItemType item)
{
    if (tree==NULL)
    {
        tree=new TreeNode<ItemType>;
        tree->right=NULL;
        tree->left=NULL;
        tree->info=item;

    }
    else if(item<tree->info)
        insert(tree->right,item);
    else
        insert(tree->right,item);
}
template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
    insert(root,item);
}
/*template <class ItemType>
void delete(TreeNode<ItemType>*& tree,ItemType item)
{
    if(item<tree->info)
        delete(tree->left,item);
    else if(item>tree->info)
        delete(tree->right,item);
    else
        deleteNode(tree);
}*/
template <class ItemType>
void deleteNode(TreeNode<ItemType>*&tree)
{
    ItemType data;
    TreeNode<ItemType>* tempPtr;

    tempPtr=tree;
    if(tree->left == NULL)
    {
        tree=tree->right;
        delete tempPtr;
    }
    else if(tree->right==NULL)
    {
         tree=tree->left;
        delete tempPtr;
    }
    else{
        //GetPredecessor(tree->left,data);
        tree->info=data;
    }
}











