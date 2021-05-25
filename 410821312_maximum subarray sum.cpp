#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <sstream>
#include <typeinfo>
#include <cmath>
#include <iomanip>

using namespace std;

//D&C
int maxsum(int arr[],int n,int left,int right)//array,n elements, left and right
{
    if(left == right){//check
        return arr[left];
    }
    int mid = (right + left)/2;
    int leftsum = maxsum(arr, n, left, mid );//find the maximum of the left part
    //cout << "left:  " << leftsum << endl;
    int rightsum = maxsum(arr, n, mid+1, right);//find the maximum of the right part
    //cout << "right: " << rightsum << endl;
    int leftbordersum = 0;
    int rightbordersum = 0;
    int middlesum = 0;
    for(int i=mid; i>=left; i--){//find the middle part also contain the left part
        middlesum += arr[i];
        if(leftbordersum < middlesum){//if its larger, then replace it
            leftbordersum = middlesum;
        }
    }
    for(int i=mid+1; i<=right; i++){//find the middle part also contain the maximum of the right part
        middlesum += arr[i];
        if(rightbordersum < middlesum){//if its larger, then replace it
            rightbordersum = middlesum;
        }
    }
    middlesum = 0;
    int midsum = leftbordersum + rightbordersum;//find the maximum sum all across the left and the right
    if(midsum>leftsum&&rightsum){//return the largest number in left part, right part and the across middle part
        return midsum;
    }
    if(leftsum>rightsum&&midsum){
        return leftsum;
    }
    else{
        return rightsum;
    }
}

//improved Brute Force
int improved(int arr[],int n)
{
    int sum,maxsum=0;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum>maxsum){
                maxsum = sum;
            }
        }
    }
    return maxsum;
 }
int main(){
    int arr[10] = {3,-4,5,-2,-2,6,-3,5,-3,2};//example array from lecture note ch-2, the maximum = 9
    cout << maxsum(arr, 10, 0, 9) << endl;
    cout << improved(arr,10) << endl;
    return 0;
}
