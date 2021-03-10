#include <iostream>
using namespace std;

struct leaf{ // структура данных для каждого листа
    int sum=0, pref=0, suff=0, ans=0; //сумма отрезка, макс  префикс, суффикс на отрезке, максимальная сумма на отрезке, т.е. ответ
};

leaf combine(leaf l, leaf r){ //строит лист дерева по двум детям
    leaf t;
    t.sum = l.sum + r.sum;
    t.pref = max(l.pref, l.sum+r.pref);
    t.suff = max(r.suff, r.sum+l.suff);
    t.ans = max(max(l.ans, r.ans), l.suff+r.pref);
    return t;
}

leaf make_one(int a){ //строит лист без детей
    leaf t;
    t.sum = a;
    t.ans = t.pref = t.suff = max(a, 0);
    return t;
}

leaf get_max_sum(leaf *a, int l, int r){
    leaf ls = a[l], rs = a[r];
    leaf list_l[100000], list_r[100000];
    leaf ans;
    int cl=0, cr=0;
    bool il=false, ir=false, tr=false;
    while (l<r){
        if (l % 2 == 1){
            il = true;
            if (tr)ls = combine(ls, a[l]);
            l ++;
        } else il = false;
        if (r % 2 == 0){
            ir = true;
            if (tr) rs = combine(a[r], rs);
            r --;
        } else ir = false;
        if (l>r){
            //cout << "break!!!";
            break;
        }
        l /= 2;
        r /= 2;
        tr = true;
    }
    if (l == r){
        ans = a[l];
        if (il) ans = combine(ls, a[l]);
        if (ir) ans = combine(ans, rs);
    }
    else{
        if (l>r){
            //if (il && tr) ls = combine(ls, a[r]);
            //if (ir && tr) rs = combine(a[l], rs);
            ans = combine(ls, rs);
        }
    }
    return ans;
}

int main(){
    int n, m, l, r, i, so, ko, t, x=1, y, z, log=0;
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
    for (leaf i: a) cout << i.sum << " " << i.pref << " " << i.suff << " " << i.ans << "\n\n";
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> l >> r;
        leaf ans = get_max_sum(a, l+x-1, r+x-1);
        cout << ans.ans << "\n\n";
    }
}
//1 2 4 5 6 3
