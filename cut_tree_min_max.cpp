#include <iostream>
using namespace std;

void add(int *a, int i, int x){
    a[i] = x;
    i /= 2;
    while (i>0){
        a[i] = min(a[i*2], a[i*2+1]);
        i /= 2;
    }
}

int min_tree(int *a, int l, int r){
    int m = 1000000;
    while (l<r){
        if (l%2==1){
            m = min(m, a[l]);
            l++;
        }
        if (r%2==0){
            m = min(m, a[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    if (l == r) m = min(m, a[l]);
    return m;
}

int main(){
    int i, n, l, r, x=1, y, z, q=0, pasha, ipa;
    cin >> n;
    while (x<n){
        x *= 2;
        q += 1;
    }
    int a_min[x*2+3];
    for (int i=0; i<x*2+3; i++) a_min[i] = 1000000;
    for (int i=0; i<n; i++) cin >> a_min[x+i];
    for (int i=x-1; i>0; i--) a_min[i] = min(a_min[i*2], a_min[i*2+1]);
    for (auto i:a_min) cout << i << " ";
    cin >> y;
    for (int i=0; i<y; i++){
        cin >> ipa >> pasha;
        add(a_min, ipa+x-1, pasha);
    }
    cout << "add!!!\n";
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> l >> r;
        cout << min_tree(a_min, l+x-1, r+x-1) << "\n";
    }
}
