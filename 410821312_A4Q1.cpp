#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
using namespace std;


int lots[100], car[100], finall[100], countt=0;
int countcar = 0, countlot = 0;
void inputlots(){
    cout <<"1 indicates able to park, 0 indicates not able to park" << endl << endl <<"please input the parking lots:(end with -1)"<< endl << endl;
    for(int  i=0; ; i++){
        int l;
        cin >> l;
        if(l == -1){
            break;
        }
        if(l == 1){
            countlot++;//amount of able parking lot
        }
        lots[i] = l;
        countt++;
    }
    cout << endl << "-------------------------------------" << endl;

}
void inputcas(){
    cout <<"1 indicates car location, 0 indicates no car" << endl << endl <<"please input the car location:(end with -1)"<< endl << endl;
    for(int  i=0; ; i++){
        int l;
        cin >> l;
        if(l == -1){
            break;
        }
        if(l == 1){
            countcar++;// amount of cars
        }
        car[i] = l;
    }
    cout << endl << "-------------------------------------" << endl;
}
void finallocation(){
    for(int i=0; i<countt; i++){
        finall[i] = 0; // initialize
    }
}

int main()
{

    inputlots();
    inputcas();
    finallocation();
    if(countcar > countlot){
        cout << "too much car" << endl;
        return 0;
    }
    //greedy
    // indx 0 1 2 3 4 5
    // lots 0 0 1 1 0 1
    // cars 1 0 0 0 1 0
    // fina 0 0 0 1 0 0
    int temp = 0, temp2 = 0 ,result = 0;
    int a,b;
    int changej = 0, changek = 0;
    for(int i=0; i<countt; i++){
        if(car[i] == 1){// current place is a car
            a=0,b=0;//to check if we move or not
            for(int j=i; j<countt; j++){//check after
                if(lots[j] == 1 && finall[j] != 1){
                    temp = j - i;// move time
                    //cout << "this is temp:  " << temp << endl;
                    a=1;
                    changej = j;//parking location
                    break;
                }
            }
            for(int k=i; k>=0; k--){//check before
                if(lots[k] == 1 && finall[k] != 1){
                    temp2 = abs(k - i);// move time
                    //cout << "this is temp2: " << temp2 << endl;
                    b=1;
                    changek = k;//parking location
                    break;
                }
            }
            if(a==1 && b==1){//able to move ahead of backward
                result += min(temp, temp2);// find the minimum path
                if(temp > temp2){// select the smaller one
                    finall[changek] = 1;
                    //cout << "k:  " << changek << endl;
                }
                else{
                    finall[changej] = 1;
                    //cout << "j:  " << changej << endl;
                }
                //cout << "do 1" << endl;
            }
            else if(a==1 && b==0){//only move ahead
                result += temp;
                finall[changej] = 1;
                //cout << "do 2" << endl;
                //cout << "j:  " << changej << endl;
            }
            else{
                result += temp2;//only move backward
                finall[changek] = 1;
                //cout << "do 3" << endl;
                //cout << "k:  " << changek << endl;
            }

        }
    }
    cout << endl << "Minimized time:  " << result << endl;
    cout << endl << "lots input:       ";
    for(int i=0; i<countt; i++){
        cout << lots[i] << "  ";
    }
    cout << endl << "cars input:       ";
    for(int i=0; i<countt; i++){
        cout << car[i] << "  ";
    }
    cout << endl << "final location:   ";
    for(int i=0; i<countt; i++){
        cout << finall[i] << "  ";
    }
    cout << endl;
    return 0;
    // 1  0  0  1  1  0  0  0  0  1  0  0  1
    // 0  1  0  0  0  0  0  1  0  0  1  0  0


}
