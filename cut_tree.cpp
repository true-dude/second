//ДЕРЕВО ОТРЕЗКОВ С ФУНК УВЕЛЕЧЕНИЯ ЭЛЕМЕНТА И ЗАПРОСА СУММЫ НА ОТРЕЗКЕ
#include <iostream>
using namespace std;

void add(int *a, int i, int x){
    while (i!=0){
        a[i] += x;
        i /= 2;
    }
}

int sum(int *a, int l, int r){
    int s=0;
    while (l<r){
        if (l%2==1){
            s += a[l];
            l++;
        }
        if (r%2==0){
            s += a[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    if (l == r)s += a[l];
    return s;
}

int main(){
    int n=5, x=1, q=0, p, s, ip, l, r, ap;
    cin >> n;
    while (x < n){
        x *= 2;
        q++;
    }
    int a[x*2+3];
    for (int i=0; i<x*2+3; i++) a[i] = 0;
    for (int i=0; i<n; i++) cin >> a[x+i]; //НЕ ХОЧЕТ СЧИТЫВАТЬ ПЕРВЫЙ ЭЛЕМЕНТ МАССИВА - ПРОСТО ИГНОРИРУЕТ ЕГО!!!
    for (int i=x; i>0; i--) a[i] = a[i*2] + a[i*2+1];
    for (auto i:a) cout << i << " ";
    cin >> p;
    for (int i=0; i<p; i++){
        cin >> ip >> ap;
        ip += x-1;
        add(a, ip, ap);
    }
    for (auto i: a) cout << i << " ";
    cin >> p;
    for (int i=0; i<p; i++){
        cin >> l >> r;
        cout << sum(a, l+x-1, r+x-1) << "\n";
    }
}
