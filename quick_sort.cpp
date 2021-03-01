#include <iostream>
//#include <cstdlin>
#include <vector>
using namespace std;

void sort(vector<int>& v, int l, int r){
    //cout << "in" << l << r;
    if (l >= r){
        cout << "sho za hiynya!";
        return;
    }
    else{
    int x = (l+r) / 2;
    //int x = v[l+rand() % (r-l+1)];
    int i = l, j = r;
    while (i<=j){
        while (v[i] < x) i++;
        while (v[j] > x) j--;
        if (i<j){
            swap(v[i], v[j]);
            i++;
            j--;
        }

    }
    sort(v, l, i);
    sort(v, j, r);
    }
}

int main(){
    cout << "HI!!!";
    vector<int> v{3, 1, 9, 12, 5, 23, 21, 4, 2, 10};
    sort(v, 0, 10);
    for (int i=0; i<10; i++){
        cout << v[i];
    }
}
