#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    cout << "Welcome to smart phone shop" << endl <<endl;
    cout << "Price of each smart phone " << endl;
    cout << "===============================================" << endl << endl;
    cout << "Apple:   20$      " << endl << endl;
    cout << "LG:      15$     " << endl << endl;
    cout << "HTC:     9$      " << endl << endl;
    cout << "Samsung  19$      " << endl << endl;
    cout << "Sony     11$     " << endl << endl << endl;
    cout << "You can only buy each phone once!!!  " << endl;
    cout << "===============================================" << endl;
    cout << "Please input your budget(<75):  " << endl;
    int money;
    int phone[5] = {20,15,9,19,11};
    cin  >> money;
    int arr[5];
    cout << "Please input your preferences:  " << endl;
    for(int i=0; i<5; i++){
        cin  >> arr[i];
    }
    for(int i=1; i<5; i++){//sort from less price to the highest with the preferences
        for(int j=i; j>0; j--){
            if(phone[j]<phone[j-1]){
                swap(phone[j],phone[j-1]);
                swap(arr[j],arr[j-1]);
            }
        }
    }
    int dp[6][money+1];
    for(int i=0; i<6; i++){
        for(int j=0; j<money+1; j++){
            dp[i][j] = 0;
        }
    }
    cout << endl;
    int maxmoney=0;
    for(int i=1; i<6; i++){//do dynamic programing
        maxmoney += phone[i-1];
        for(int j=0; j<money+1; j++){//check money from 0 - budget
            if(j>=phone[i-1]){
                dp[i][j] = arr[i-1];
            }
            if(j>=maxmoney){//see if the money is able to buy now item and previous all item
                dp[i][j] = dp[i-1][j] + arr[i-1];// if it is able, add preference together
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);// save the largest preferences
        }
    }
    cout << endl << "this is the most preferences you can get" << endl;
    cout << dp[5][money] << endl;

    return 0;
}
