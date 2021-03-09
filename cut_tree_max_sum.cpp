#include <iostream>
using namespace std;

struct leaf{ // структура данных для каждого листа
    int sum, pref, suff, ans; //сумма отрезка, макс  префикс, суффикс на отрезке, максимальная сумма на отрезке, т.е. ответ
};

leaf combine(leaf l, leaf r){ //строит лист дерева по двум детям
    leaf t;
    t.sum = l.sum + r.sum;
    t.pref = max(l.pref, l.sum+r.suff);
    t.suff = max(r.suff, r.sum+l.pref);
    t.ans = max(max(l.ans, r.ans), l.suff+r.pref);
    retur t;
}

leaf make_one(int a){ //строит лист без детей
    leaf t;
    t.sum = t.ans = t.pref = t.suff = max(a, 0);
    return t;
}

get_max_sum(int *a, int l, int r){
    leaf ls = a[l], rs = a[r];
    while (l<r){
        if (l % 2 == 0){
            ls = a[l];
            l ++;
        }
        if (r % 2 == 1){
            rs = a[r];
            r --;
        }
        l /= 2;
        r /= 2;
    }
}

int main(){
    int n, m, l, r, i, so, t, x=1, y, z, log=0;
    cin >> n;
    while (x < n){ //считаем логарифм длины массива
        log += 1;
        x *= 2;
    }
    leaf a[x*2+3];
    for (i=0; i<n; i++){
        cin >> y;
        a[x+i] = make_one(y);
    }
    for (i=x-1; i>0; i--) a[i] = combine(a[i*2], a[i*2+1]); //построение дерева отрезков
    cin >> z;
}
