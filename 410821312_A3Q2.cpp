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
    cout << endl;
    cout << "this is the price of the different length for renting" << endl;
    cout << "=====================================================" << endl;
    cout << "1 mile:     500$" << endl;
    cout << "2 miles:    1050$" << endl;
    cout << "3 miles:    1600$" << endl;
    cout << "4 miles:    2150$" << endl;
    cout << "5 miles:    2700$" << endl;
    cout << "=====================================================" << endl;
    cout << "please input the length of Isozaki Coast(>20)" << endl;
    int mile;
    cin >> mile;
    int price[5] = {500,1050,1600,2150,2700},len[5] ={1,2,3,4,5},rent[5] = {0};
    int dp[6][mile+1];
    for(int i=0; i<6; i++){
        for(int j=0; j<mile+1; j++){
            dp[i][j] = 0;
        }
    }
    int tempmile = mile;
    int count=0;
    int tempmoney;
    int temp;
    for(int i=1; i<6; i++){//doing dynamic programing
        for(int j=1; j<mile+1; j++){
            if(j % len[i-1]==0){//if the mile can be divide
                count = j / len[i-1];
                dp[i][j] = count*price[i-1];
            }
            else{// if the mile cant be divide
                tempmile = j%len[i-1];
                temp = tempmile;
                tempmile = price[temp-1];
                tempmoney = dp[i][j-(j%len[i-1])];
                if(j>=len[i-1]){//j is larger then the mile which is checking now, sum the previous and the left file with the money
                    dp[i][j] = tempmoney + tempmile;
                }
                else{//j is smaller then mile which is checking now and use the previous max (cause ex i=4 and the check mile now is 3, so cant buy the 4 mile one)
                    dp[i][j] = tempmoney;
                }

            }
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            //cout << dp[i][j] <<"  ";
        }
        //cout << endl;
    }
    //cout << endl << endl;
    /*for(int i=0; i<6; i++){
        for(int j=0; j<mile+1; j++){
            cout << dp[i][j] <<"  ";
        }
        cout << endl;
    }*/
    cout << "this is the maximum money:" << endl;
    cout << dp[5][mile];
    return 0;
}
