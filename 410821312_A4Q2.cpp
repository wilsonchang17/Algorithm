#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
using namespace std;

string arr[100];
int n=0;
string temp1,temp2;
int cur=0,max=0,countbreak;

void input(){
    string s;
    cout << "input string(end with 1)" << endl;
    for(int  i=0; ;i++){
        cin >> s;
        if(s=="1"){
            break;
        }
        arr[i] = s;
        n++;
    }
}

void debugoutput(){
    for(int  i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}

void find(){
    cur = 0;
    int tempi,tempj,replace;
    for(int i=0; i<n-1; i++){//take arr[i]
        temp1 = arr[i];
        int len1 = arr[i].length();
        if(temp1=="0"){
            continue;
        }
        for(int j=1; j<n; j++){// take arr[i=1] ~ arr[last one]
            temp2 = arr[j];
            if(temp2=="0"){
                continue;
            }
            else{
                if(i!=j){
                    int len2 = arr[j].length();
                    int gap1 = len1 - len2;
                    if(gap1<0){
                        gap1 = 0;
                    }
                    int tmp1[100] = {0},tp1=0;
                    int count1=0, count2=0;
                    for(int s=gap1; s<len1; s++){//check temp1 back and temp2 head
                        for(int k=s , q=0; k<len1; k++ , q++){
                            if(temp1[k]==temp2[q]){
                                if(temp1[k+1]==temp2[q+1] && k!=len1-1){
                                    tmp1[tp1]++;//how many overlap
                                }
                                else{
                                    if(k==len1-1){//last one, don't have to check further
                                        tmp1[tp1]++;
                                    }
                                    else{
                                        tmp1[tp1] = 0;
                                        break;
                                    }
                                }
                            }
                            else{
                                break;
                            }
                        }
                        tp1++;
                    }
                    count1 = *max_element(tmp1, tmp1+99);
                    int gap2 = len2 - len1;
                    if(gap2<0){
                        gap2 = 0;
                    }
                    int tmp2[100]={0},tp2=0;
                    for(int s = gap2; s<len2; s++){//check temp2 back and temp1 head
                        for(int k=s , q=0; k<len2; k++, q++){
                            if(temp2[k]==temp1[q]){
                                if(temp2[k+1]==temp1[q+1] && k!=len2-1){
                                    tmp2[tp2]++;//how many overlap
                                }
                                else{
                                    if(k==len2-1){//last one, don't have to check further
                                        tmp2[tp2]++;
                                    }
                                    else{
                                        tmp2[tp2] = 0;
                                        break;
                                    }
                                }
                            }
                            else{
                                break;
                            }
                        }
                        tp2++;
                    }
                    count2 = *max_element(tmp2, tmp2+99);
                    if(std::max(count1,count2) > cur){//the most that we can replace
                        cur = std::max(count1, count2);
                        if(count1>=count2){
                            replace = 1;
                        }
                        else{
                            replace = 0;
                        }
                        tempi = i;
                        tempj = j;
                    }
                }
                }
        }
    }
    //combine two string with their overlap
    if(replace==1){
        string a;
        if(arr[tempi]=="0" || arr[tempj]=="0"){}
        else{
            a = arr[tempi] + arr[tempj].erase(0,cur);
            arr[tempj] = a;
            arr[tempi] = "0";
        }
    }
    else{
        string a;
        if(arr[tempi]=="0" || arr[tempj]=="0"){}
        else{
            a = arr[tempj].erase(arr[tempj].length()-cur) + arr[tempi];
            arr[tempj] = a;
            arr[tempi] = "0";
        }
    }
}

int main()
{
    input();
    for(int  i=0; i<n-1; i++){
        find();
    }
    string final;
    for(int i=0; i<n; i++){//if there are string still did not combine means that there is no overlap
        if(arr[i]!="0"){
            final+=arr[i];//combine

        }
    }
    cout << "Minimized string:  " << final;
    return 0;
}
