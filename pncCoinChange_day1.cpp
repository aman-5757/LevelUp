//permutation
//combination
// coinChange


#include<vector>
#include<iostream>
using namespace std;

int permutationINFI(vector<int> &arr, int idx, int tar, string ans){
    if(tar == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
        if( tar-arr[i] >= 0 ){
            count += permutationINFI(arr,0,tar-arr[i],ans + to_string(arr[i])+" ");
        }   
    }
    return count;

}

int combinationINFI(vector<int> &arr, int idx, int tar, string ans){
    if(tar == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
        if( tar-arr[i] >= 0 ){
            count += combinationINFI(arr,i,tar-arr[i],ans + to_string(arr[i])+" ");
        }   
    }
    return count;

}

int combinationSingle(vector<int> &arr, int idx, int tar, string ans){
    if(tar == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
        if( tar-arr[i] >= 0 ){
            count += combinationSingle(arr,i+1,tar-arr[i],ans + to_string(arr[i])+" ");
        }   
    }
    return count;

}


int permutationSingle(vector<int> &arr, int idx, int tar, string ans){
    if(tar == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
        if( arr[i] > 0 && tar-arr[i] >= 0 ){
            int tmp = arr[i];
            arr[i] = -arr[i];
            count += permutationSingle(arr,0,tar-tmp,ans + to_string(tmp)+" ");
            arr[i] = -arr[i];
        }   
    }
    return count;

}


void coinChangeCombinationPermuation(){
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;

    cout<<permutationINFI(arr,0,tar,"")<<endl;
    cout<<"============================================="<<endl;
    cout<<combinationINFI(arr,0,tar,"")<<endl;
        cout<<"============================================="<<endl;

    cout<<combinationSingle(arr,0,tar,"")<<endl;
        cout<<"============================================="<<endl;

    cout<<permutationSingle(arr,0,tar,"")<<endl;
        cout<<"============================================="<<endl;

}


int main(){
    coinChangeCombinationPermuation();
    return 0;
}