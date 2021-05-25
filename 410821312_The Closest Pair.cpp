#include <iostream>
#include <string.h>
# include <stdlib.h>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <cmath>
using namespace std;

class point
{
public:
    double x,y;
};
class point arr[10000];

bool large(point a, point b){
    return a.x < b.x;
}

double dis(point a, point b){
    double s;
    s = (sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)));
    return s;
}

double com(point a[], int left, int middle, int right, double minleft, double minright){
    double d;
    if(minleft > minright){
        d = minright;
    }
    else{
        d = minleft;
    }
    double midline=(a[middle].x + a[middle+1].x)/2;
    double mindd=d;
    for(int i=middle+1; a[i].x < midline+d && i <= right; i++){
        for(int j=middle; a[j].x > midline-d && j >= left; j--){
            double temp=dis(a[i],a[j]);
            if(temp < mindd){
               mindd = temp;
            }
        }
    }
    return mindd;
}
double div(point arr[], int left, int right){
    //cout << "left:  " << left << endl;
    //cout << "right:  " << right << endl;
    if(left>=right){
        return 99999;
    }
    int middle  = (left + right)/2;
    double minleft = div(arr, left, middle);
    double minright = div(arr, middle+1, right);
    return com(arr, left, middle, right, minleft, minright);
}

int main(){
    int test;
    while(cin >> test){
        if(test==0){
            break;
        }
        for(int i=0; i<test; i++){
            cin >> arr[i].x >> arr[i].y;
        }
        sort(arr,arr+test,large);
        double ans = div(arr, 0, test-1);
        cout << ans << endl;
    }
    return 0;
}




