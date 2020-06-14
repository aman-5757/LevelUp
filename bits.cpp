#include<iostream>

int offOnBit(int x, int k ){
    int mask = (1<<k);
    return (mask|x);
}

// Single Number -- LC 191 (numberOfSingleBit_)

int numberOfSingleBit_01(uint32_t n) {
        int c = 0;
        for(int i = 0; i<32; i++){
            int mask = (1<<i);
            if((n&mask) != 0 ) {
                c++;
            } 
        }
        return c; 
    }

int numberOfSingleBit_02(uint32_t n) {
        int c = 0;
        int t = 0;
        while(n!=0 && t<32){
            t++;
            if((n&1)!=0)    c++;
            n >>= 1;
        }
        return c; 
    }

int numberOfSingleBit_03(uint32_t n) {
        int c = 0;
        while(n!=0){
            c++;
            n = (n&(n-1));        //---> This formula removes last set bit.
        }
        return c; 
    }

int main(){
    return 0;
}