#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* construct(int *arr){
    Node* root=new Node(arr[0]);
    pair<Node*,int> p={root,1};

    stack<pair<Node*,int>> st;
    st.push(p);

    int idx=1;
    while(!st.empty()){
        // pair<Node*,int> pe=st.top();
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*,int> rp={st.top().first->right,1};
                st.push(rp);
            } else {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else {
            st.pop();
        }

    }
    return root;
}

//recursive solution
// void PostOrder(Node* root){
//     if(root==nullptr){
//         return;
//     }
//     PostOrder(root->left);
//     PostOrder(root->right);
//     cout << root->data << " ";
// } 

// non recursive solution
// 1st method
// void PostOrderIter(Node* root){
//     if(root==nullptr){
//         return;
//     }
//     stack<Node*> st;
//     while(true){
//         while(root){
//             st.push(root);
//             st.push(root);
//             root=root->left;
//         }
//         if(st.empty()){
//             return;
//         }
//         root=st.top();
//         st.pop();
//         if(!st.empty() && st.top()==root){
//             // st.pop();
//             // st.push(root);
//             root=root->right;
//         }
//         else{
//             cout << root->data << " ";
//             root=nullptr;
//         }
//     }
    
// }


// 2nd method
void PostOrderIter(Node* root){
    if(root==nullptr){
        return;
    }
    stack<Node*> st;
    if(root->right){
        st.push(root->right);
    }
    st.push(root);
    root=root->left;
    while(!st.empty()){
        while(root){
            if(root->right){
                st.push(root->right);
            }
            st.push(root);
            root=root->left;
        }
        if(st.empty()){
            return;
        }
        root=st.top();
        st.pop();
        if(!st.empty()&& st.top()==root->right){
            st.pop();
            st.push(root);
            root=root->right;
        }
        else{
            cout << root->data << " ";
            root=nullptr;
        }
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s=="n"){
            arr[i]=-1;
        }
        else{
            arr[i]=stoi(s);
        }
    }

    Node* root=construct(arr);
    PostOrder(root);
    cout << endl;
    PostOrderIter(root);
}
