#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    TreeNode(int data){
        this->data = data;
    }
};

void inOrder(TreeNode * node){
    if(node == nullptr) return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}
// size code
int size(TreeNode * node){
    return node != nullptr ? size(node->left)+size(node->right)+1 : 0;
}

int height(TreeNode * node){
    return node != nullptr ? max(height(node->left),height(node->right))+1 : -1;
}

int maximum(TreeNode * node){
    return node != nullptr? max(node->data,max(maximum(node->left),maximum(node->right))) : -1e8;
}

int minimum(TreeNode * node){
    return node == nullptr ? 1e8 : min(node->data,min(minimum(node->left),minimum(node->right)));
}


bool find(TreeNode * node, int data){
    if(node == nullptr) return false;
    if(data == node->data)  return true;
    return find(node->left,data) || find(node->right,data);
}


bool find_(TreeNode * node, int data){       //expanded
    if(node == nullptr) return false;
    if(node->data == data)  return true;
    bool lc = find(node->left,data);
    if(lc)  return true;
    bool rc = find(node->right,data);
    if(rc)  return true;
    return false;
}

bool nodeToRootPath(TreeNode*node, int data, vector<TreeNode *> & path){
    if(node == nullptr) return false;
    if(node->data == data){
        path.push_back(node);
        return true;
    }
    bool res = nodeToRootPath(node->left,data,path) || nodeToRootPath(node->right,data,path);
    if(res){
        path.push_back(node);
    }
    return res;
}


vector<TreeNode * > nodeToRootPath02(TreeNode * node, int data){
    if(node == nullptr) return {};
    if(node->data == data){
        vector<TreeNode *> base;
        base.push_back(node);
        return base;
    }
    vector<TreeNode *> la = nodeToRootPath02(node->left,data);
    if(la.size()!=0){
        la.push_back(node);
        return la;
    }
    vector<TreeNode *> ra = nodeToRootPath02(node->right,data);
    if(ra.size()!=0){
        ra.push_back(node);
        return ra;
    } 
    return {}; 

}


TreeNode * lowestCommonAncestor(TreeNode * root,TreeNode *p, TreeNode *q){
    vector<TreeNode *> arr1, arr2;
    bool res = nodeToRootPath(root, p->data, arr1) && nodeToRootPath(root,q->data,arr2);
    if(!res)    return nullptr;
    int i = arr1.size()-1;
    int j = arr2.size()-1;
    TreeNode * LCA = nullptr;
    while(i>=0 && j >=0){
        if(arr1[i]->data != arr2[j]->data)  break;
        LCA = arr1[i];
        i--;    j--;
    }

    return LCA;

}

int distanceBetweenNodes(TreeNode * root, int p, int q){            //asked in amazon
    vector<TreeNode *> arr1, arr2;
    bool res = nodeToRootPath(root, p, arr1) && nodeToRootPath(root,q,arr2);
    if(!res)    return 0;
    int i = arr1.size()-1;
    int j = arr2.size()-1;
    int LCA = 0;
    while(i>=0 && j >=0){
        if(arr1[i]->data != arr2[j]->data)  break;
        LCA++;
        i--;    j--;
    }

    return (arr1.size()+arr2.size()-(2*LCA));

}

int diameter(TreeNode * node){
    if(node == nullptr){
        return 0;
    }
    int ld = diameter(node->left);
    int rc = diameter(node->right);
    int lh = height(node->left);
    int right = height(node->right);
    return max(max(ld,rd),lh+rh+2);
}


// public static int [] diameter(TreeNode root){            --> DIAMETER FOR JAVA LEETCODE 543
//         if(root == null)    return new int[]{0,-1}; //dia,height
//         int [] la = diameter(root.left);
//         int [] ra = diameter(root.right);
//         int d = Math.max(Math.max(la[0],ra[0]), la[1]+ra[1]+2);
//         int h = (Math.max(la[1],ra[1]))+1;
//         return new int[]{d,h};
//     }


//Diameter using pair C++

pair<int, int> diameter_btr(TreeNode * root){
    if(root == nullptr){
        return {0,-1};}
        pair<int, int> la = diameter_btr(root->left);
        pair<int, int> ra = diameter_btr(root->right);
        int d = max(max(la.first,ra.first), la.second+la.second+2);
        int h = max(la.second,ra.second)+1;
        return {d,h};
    }

int idx = 0;
TreeNode * constructTree(vector<int> & arr){
    if(idx == arr.size() || arr[idx] == -1){
        idx++;
        return nullptr;
    }
    TreeNode * node = new TreeNode(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}


void display(TreeNode * node){
    if(node == nullptr) return;
    string str = "";
    str += node->left != nullptr? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr? to_string(node->right->data) : ".";
    cout<<str<<endl;

    display(node->left);
    display(node->right);
}



void solve(){
    vector<int> arr = {10,20,30,40,-1,-1,60,70,-1,80,-1,-1,-1,90,100,-1,120,-1,-1,110,130,-1,-1,-1};
    TreeNode * root = constructTree(arr);
    // display(root);
    // inOrder(root);
    // cout<<size(root);
    // cout<<maximum(root);
    // cout<<minimum(root);
    // cout<<find(root, 60);
    // vector<TreeNode *> ans = nodeToRootPath02(root,130);
    // for(int i = 0; i<ans.size(); i++){
    //     cout<<ans[i]->data<<" ";
    // }
}

int main(){
    solve();
    return 0;
}
