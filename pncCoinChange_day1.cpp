//permutation
//combination
// coinChange
// subSequence Method

//Approach to Nqueen


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

//=============================================SUBSEQUENCE METHOD=============================================

int combinationSingle_subSeq(vector<int> & arr, int idx, int tar, string ans){
    if(tar == 0 || idx == arr.size()){
       if( tar == 0){
           cout<<ans<<endl;
           return 1;
       }
       return 0;
    }
    int count = 0;
    if( tar - arr[idx] >= 0){
        count += combinationSingle_subSeq(arr, idx + 1, tar - arr[idx] , ans + to_string(arr[idx])+ " ");
    }    
    count += combinationSingle_subSeq(arr, idx + 1, tar, ans);
    return count;
}


int combinationINFI_subSeq(vector<int> & arr, int idx, int tar, string ans){
    if(tar == 0 || idx == arr.size()){
       if( tar == 0){
           cout<<ans<<endl;
           return 1;
       }
       return 0;
    }
    int count = 0;
    if( tar - arr[idx] >= 0){
        count += combinationINFI_subSeq(arr, idx , tar - arr[idx] , ans + to_string(arr[idx])+ " ");
    }    
    count += combinationINFI_subSeq(arr, idx + 1, tar, ans);
    return count;
}

int permutationINFI_subSeq(vector<int> & arr, int idx, int tar, string ans){
    if(tar == 0 || idx == arr.size()){
       if( tar == 0){
           cout<<ans<<endl;
           return 1;
       }
       return 0;
    }
    int count = 0;
    if( tar - arr[idx] >= 0){
        count += permutationINFI_subSeq(arr, 0 , tar - arr[idx] , ans + to_string(arr[idx])+ " ");
    }    
    count += permutationINFI_subSeq(arr, idx + 1, tar, ans);
    return count;
}

int permutationSingle_subSeq(vector<int> & arr, int idx, int tar, string ans){
    if(tar == 0 || idx == arr.size()){
       if( tar == 0){
           cout<<ans<<endl;
           return 1;
       }
       return 0;
    }
    int count = 0;
    if( arr[idx]>=0 && tar - arr[idx] >= 0){
        int tmp = arr[idx];
        arr[idx] = -arr[idx];
        count += permutationSingle_subSeq(arr, 0 , tar - tmp , ans + to_string(tmp)+ " ");
        arr[idx] = -arr[idx];
    }    
    count += permutationSingle_subSeq(arr, idx + 1, tar, ans);
    return count;
}

void subSeqMethod(){
    vector<int> arr {2, 3, 5, 7};
    int tar = 10;
    cout<<combinationSingle_subSeq(arr,0,tar,"");
    cout<<"============================================="<<endl;
    cout<<combinationINFI_subSeq(arr,0,tar,"");
    cout<<"============================================="<<endl;
    cout<<permutationINFI_subSeq(arr,0,tar,"");
    cout<<"============================================="<<endl;
    cout<<permutationSingle_subSeq(arr,0,tar,"");
    cout<<"============================================="<<endl;



    
}

//=============================================QUEEN P & C=========================================================
int queenCombination_1D(vector<bool> arr, int idx, int tnq, int qpsf, string ans){
    if(tnq == qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
            count += queenCombination_1D(arr,i+1,tnq,qpsf+1,ans +"b"+ to_string(i) + "q"+ to_string(qpsf)+ " ");
        }   
    return count;
}

int queenCombination_1D_subSeq(vector<bool> arr, int idx, int tnq, int qpsf, string ans){
    if(tnq == qpsf || idx == arr.size()){
       if( tnq == qpsf ){
           cout<<ans<<endl;
           return 1;
       }
       return 0;
    }
    int count = 0;
    
    count += queenCombination_1D_subSeq(arr, idx + 1, tnq, qpsf+1 , ans +"b"+ to_string(idx) + "q"+ to_string(qpsf)+ " ");
    count += queenCombination_1D_subSeq(arr, idx + 1, tnq,qpsf, ans);
    return count;
}

int queenPermutation_1D(vector<bool> &arr, int idx, int tnq, int qpsf, string ans){
    if(tnq == qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size(); i++){
        if( !arr[i] ){
            
            arr[i] = true;
            count += queenPermutation_1D(arr,0,tnq,qpsf+1, ans +"b"+ to_string(i) + "q"+ to_string(qpsf)+ " ");
            arr[i] = false;
        }   
    }
    return count;
}

int queenCombination_2D(vector<vector<bool>> & arr, int idx, int tnq, int qpsf, string ans){
    if(tnq  == qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size()*arr[0].size(); i++){
        int r = i/arr[0].size();
        int c = i%arr[0].size();
        count += queenCombination_2D(arr,i+1,tnq,qpsf+1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
        
    }
    return count;
}

int queenPermutation_2D(vector<vector<bool>> & arr, int idx, int tnq, int qpsf, string ans){
    if(tnq == qpsf){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size()*arr[0].size(); i++){
        int r = i/arr[0].size();
        int c = i%arr[0].size();
        if( !arr[r][c] ){
            
            arr[r][c] = true;
            count += queenPermutation_2D(arr,0,tnq,qpsf+1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
            arr[r][c] = false;
        }   
    }
    return count;
}





void queenPnC(){
    vector<bool> arr(5,false);
    int tnq = 3;
    vector<vector<bool>> barr(4,vector<bool>(4,false));
    cout<<queenCombination_1D(arr,0,tnq,0,"")<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
    cout<<queenCombination_1D_subSeq(arr,0,tnq,0,"")<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
    cout<<queenPermutation_1D(arr,0,tnq,0,"")<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
    cout<<queenCombination_2D(barr, 0,4,0,"")<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
    cout<<queenPermutation_2D(barr, 0,4,0,"")<<endl;
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";


}


//======================================================N Queen======================================================

bool isSafeToPlace(vector<vector<bool>> & arr, int r, int c){
    vector<vector<int>> dir = {{0,-1},{-1,-1},{-1,0},{-1,1}};           //for Nqueen_01 (Combination)   Answer = 2
    vector<vector<int>> dirP = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};     //for Nqueen_02 (Permutation)   Answer = 48


    for(int s = 0; s<dir.size(); s++){
        for(int rad = 1; rad<=arr.size(); rad++){
            int x = r + rad*dir[s][0];
            int y = c + rad*dir[s][1];
            if(x>=0 && y>=0 && x<arr.size() && y<arr[0].size()){
                if(arr[x][y])
                    return false;
            }
        }
    }
    return true;

}

int calls = 0;

int Nqueen_01(vector<vector<bool>> & arr, int idx, int tnq, string ans){
    if(tnq  == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    calls++;
        for(int i = idx; i<arr.size()*arr[0].size(); i++){
        int r = i / arr[0].size();
        int c = i % arr[0].size();
        if(isSafeToPlace(arr,r,c)){
            arr[r][c] = true;
        count += Nqueen_01(arr,i+1,tnq-1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
        
            arr[r][c] = false;

        }
    }
    return count;
}

int Nqueen_02(vector<vector<bool>> & arr, int idx, int tnq, string ans){
    if(tnq == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i = idx; i<arr.size()*arr[0].size(); i++){
        int r = i/arr[0].size();
        int c = i%arr[0].size();
        if( !arr[r][c] && isSafeToPlace(arr,r,c) ){
            
            arr[r][c] = true;
            count += Nqueen_02(arr,0,tnq-1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
            arr[r][c] = false;
        }   
    }
    return count;
}

vector<bool> rowA;  //n;
vector<bool> colA;     //m
vector<bool> diaA;      //n+m-1
vector<bool> adigA;     //n+m-1



int Nqueen_03(vector<vector<bool>> & arr, int idx, int tnq, string ans){            //4 extra 1D arrays
    if(tnq  == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    calls++;
    int n = arr.size();
    int m = arr[0].size();
        for(int i = idx; i<arr.size()*arr[0].size(); i++){
        int r = i / arr[0].size();
        int c = i % arr[0].size();
        if(!rowA[r] && !colA[c] && !diaA[r+c] && !adigA[r-c+m-1]){
           
            rowA[r] = true;
            colA[c] = true;
            diaA[r+c] = true;
            adigA[r-c+m-1] = true;
        count += Nqueen_03(arr,i+1,tnq-1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
            rowA[r] = false;
            colA[c] = false;
            diaA[r+c] = false;
            adigA[r-c+m-1] = false;
         

        }
    }
    return count;
}


int Nqueen_04(int n,int m, int r, int tnq, string ans){
    if(tnq  == 0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    calls++;
   
        for(int c = 0; c<m; c++){
        
        if(!rowA[r] && !colA[c] && !diaA[r+c] && !adigA[r-c+m-1]){
           
            rowA[r] = true;
            colA[c] = true;
            diaA[r+c] = true;
            adigA[r-c+m-1] = true;
        count += Nqueen_04(n,m,r+1,tnq-1,ans + "("+to_string(r) +"," + to_string(c)+")"+" ");
            rowA[r] = false;
            colA[c] = false;
            diaA[r+c] = false;
            adigA[r-c+m-1] = false;
         

        }
    }
    return count;
}








void queen(){
    int n,m;
    n =4;
    m = 4;
    int tnq = n;
    vector<vector<bool>> arr(n,vector<bool>(m,false));
    // cout<<Nqueen_01(arr,0,tnq,"")<<endl;
    // cout<<Nqueen_02(arr,0,tnq,"")<<endl;
    rowA.resize(n,false);
    colA.resize(m,false);
    diaA.resize(n+m-1,false);
    adigA.resize(n+m-1,false);
    // cout<<Nqueen_03(arr,0,tnq,"")<<endl;
    cout<<Nqueen_04(n,m,0,tnq,"")<<endl;

    cout<<calls<<endl;


    
}

//              N QUEEN 05 To Be Done After BitMasking



int main(){
    // coinChangeCombinationPermuation();
    //subSeqMethod();
    // queenPnC(); 
    queen();   
    return 0;
}