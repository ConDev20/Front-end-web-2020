#include <iostream>
#include <vector>
#include <list>
#include <iomanip> 
#include <stack>
#include <queue>
template <class T>
struct Node
{
    T data;
    Node* left;
    Node* right;
};
template <class T>
Node<T>* newNode(const T& x)
{
    Node<T>* node = new Node<T>;
    node->data = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
template<class T>
void print(Node<T>* current)
{
    if(current == nullptr )
    {
        return;
    }
    print(current->left);
    std::cout << current->data << " ";
    print(current->right);
}
template<class T>
int leafs(Node<T>* current)
{
    if(current == nullptr)
    {
        return 0;
    }else if (current->left == nullptr && current->right == nullptr)
    {
        return 1;
    }
    return leafs(current->left) + leafs(current->right);
}

template<class T>
int countEvens(Node<T>* current)
{
    if(current == nullptr)
    {
        return 0;
    }
    int data = current->data % 2 == 0 ? current->data : 0;
    return  data +
           countEvens(current->right) +
           countEvens(current->left);
}
template<class T>
int maxLeaf(Node<T>* current)
{
    if(current == nullptr)
    {
        return 0;
    }
    if(current->left == nullptr && current->right == nullptr)
    {
        return current->data;
    }
    return std::max(maxLeaf (current->right), maxLeaf(current->left));
}
template<class T>
void clear(Node<T>* root)
{
    if(root == nullptr)
    {
        return;
    }
    clear(root->left);
    clear(root->right); 
    delete root;
}
template<class T>
int height(Node<T>* root)
{  
    if(root == nullptr)
    {
        return 0;
    }
    return std::max(height(root->left), height(root->right)) + 1;
}

void BFS(Node<int> *root)
{
    // Base Case
    if (root == nullptr)  return;
 
    // Create an empty queue for level order traversal
    std::queue<Node<int>*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (!q.empty())
    {
        // Print front of queue and remove it from queue
        Node<int> *node = q.front();
        std::cout << node->data << " ";
        q.pop();
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}
template <class T>
bool equalTrees(Node<T>* root1, Node<T>* root2 )
{
    if(root1 == nullptr || root2 == nullptr)
    {
        return root1 == nullptr && root2 == nullptr;
    }
    if(root1->data != root2->data)
    {
        return false;
    }
    return equalTrees(root1->left, root2->left) && equalTrees(root1->right, root2->right);
}

template<class T>
int depth(const T& x,Node<T> *root)
{
    if(root == nullptr || x == root->data)
    {
        return 0;
    }
    if(x <= root->data)
    {
        return 1 + depth(x, root->left);
    }else
    {
        return 1 + depth(x, root->right);
    }
}
template <class T>
void printLevel(size_t level, Node<T>* root)
{
    if(root == nullptr)
    {
        return;
    }
    if(level == 1)
    {
        std::cout << root->data << " ";
    }else
    {
         printLevel(level-1,root->left);
         printLevel(level-1,root->right);
    }
}
template <class T>
void bfs_slow(Node<T> *root)
{
    for (size_t i = 1; i <= height(root); i++)
    {
        printLevel(i,root);
        std::cout << std::endl;
    }
}
template<class T>
bool isSymetricHelper(Node<T>* left, Node<T>* right)
{
    if(left == nullptr && right == nullptr)
    {
        return true;
    }
    if(left->data == right->data)
    {
        return isSymetricHelper(left->left, right->right) && 
               isSymetricHelper(left->right, right->left);
    }
    return false;
}
template<class T>
bool isSymetric(Node<T>* root)
{
    return isSymetricHelper(root->left,root->right);
}
template<class T>
int lenghtToNode(Node<T>* root, T x, int path = 0)
{   
    if(root == nullptr)
    {
        return 0;
    }
    if(root->data == x)
    {
        return path;
    }
    return  lenghtToNode(root->left,x,path + 1) + lenghtToNode(root->right,x,path + 1);
}
template<class T>
void postorder(Node<T>* root, int indent=0)
{
    if(root != nullptr) 
    {
        if(root->left)
        {
            postorder(root->left, indent+4);
        } 
        if(root->right)
        {
            postorder(root->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout<< root->data << "\n ";
    }
}

template<class T>
T findLevel(Node<T>* root, T a, T level)
{
    if(root == nullptr)
    {
        return 0;
    }
    if(root->data == a)
    {
        return level;
    }
    T left = findLevel(root->left, a, level+1);
    T right = findLevel(root->right,a,level+1);
    if(left != 0)
    {
        return left;
    }
    return right;
}
template<class T>
Node<T>* findParent(Node<T>* root, T a, Node<T>* parent)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root->data == a)
    {
        return parent;
    }
    Node<T> *tmp = findParent(root->left, a, root);
    if(tmp == nullptr)
    {
        return findParent(root->right,a,root);
    }
    return tmp;
}
template<class T>
bool isCousins(Node<T>* root, T x, T y) {
    T level1 = findLevel(root,x,0);
    T level2 = findLevel(root,y,0);
    Node<T>* parent;
    if(level1 == level2 && findParent(root,x,parent) != findParent(root,y,parent))
    {
        return true;
    }
    return false;
}
template<class T>
bool isBalanced(Node<T>* root)
{
    if(root == nullptr)
    {
        return true;
    }
    if(abs(heightTMP(root->left) - heightTMP(root->right)) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}
template<class T>
int heightTMP(Node<T>* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return std::max(heightTMP(root->left), heightTMP(root->right)) + 1; 
}
template<class T>
Node<T>* invert(Node<T>* root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    Node<T>* left = invert(root->left);
    Node<T>* right = invert(root->right);
    root->left = right;
    root->right = left;
    return root;
}
template<class T>
int nora(Node<T>* current,int level)
{
    if(current == nullptr)
    {
        return 0;
    }
    if(level % 2 != 0 && current->right == nullptr && current->left != nullptr)
    {
        return current->data;
    }
    return nora(current->left, level + 1) + nora(current->right, level + 1);
}

template<class T>
Node<T>* createBalancedTree(int height)
{
    std::stack<Node<int>*> s;
    Node<int>* root = new Node<int> {0,nullptr,nullptr};
    s.push(root);
    while(!s.empty())
    {
        Node<int>* top = s.top();
        s.pop();
        if(top->data+1 < height) /// can be !=
        {
            top->left = new Node<int>{top->data + 1, nullptr, nullptr};
            top->right = new Node<int>{top->data + 1, nullptr, nullptr};
            s.push(top->left);
            s.push(top->right);
        } 
    }
    return root;
}
int main()
{
    Node<int>* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(5);
    root->right->left = newNode(6);
    root->right->left->right = newNode(7);
    std::cout << std::endl;
    BFS(root);
    std::cout << nora(root,0);
    std::cout << std::endl;
    std::cout << isBalanced(root);
    std::cout << isCousins(root, 4, 5);
    clear(root);
    return 0;
}