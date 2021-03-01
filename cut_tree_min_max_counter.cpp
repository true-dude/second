//дерево отрезко для запросов минимума на отрезке и сколько раз он встречается на отрезке
//входные данные:
//n(кол-во) элементов в массиве
//сам массив
//кол-во(z) запросов замены элемента
//z запросов (индекс элемента, значение)
//кол-во (z) запросов минимума на отрезке и их кол-во
//z запросов l r(левая граница, правая граница)(1-нумерация!!!)

#include <iostream>
using namespace std;


void add(pair<int, int> *a, int i, int x){
    a[i] = make_pair(x, 1);
    i /= 2;
    while (i>0){
        pair<int, int> c1 = a[i*2];
        pair<int, int> c2 = a[i*2+1];
        pair<int, int> st = a[i];
        if (c1.first == c2.first) a[i] = make_pair(c1.first, c2.second + c1.second);
        else{
            if (c1.first < c2.first) a[i] = c1;
            else a[i] = c2;
        }
        if (st == a[i]){
            break;
        }
        i /= 2;
    }
}

pair <int, int> min_tree(pair<int, int> *a, int l, int r){
    pair<int, int> m = make_pair(1000000, -1);
    while (l<r){
        if (l%2==1){
            if (m.first == a[l].first) m.second += a[l].second;
            else{
                if (a[l].first < m.first) m = a[l];
            }
            l++;
        }
        if (r%2==0){
            if (m.first == a[r].first) m.second +=a[r].second;
            else{
                if (a[r].first < m.first) m = a[r];
            }
            r--;
        }
        l /= 2;
        r /= 2;
    }
    if (l == r){
        if (m.first == a[l].first) m.second += a[l].second;
            else{
                if (a[l].first < m.first) m = a[l];
            }
    };
    return m;
}

int main(){
    int i, n, l, r, x=1, y, z, q=0, pasha, ipa, k, ip;
    cin >> n;
    while (x<n){
        x *= 2;
        q += 1;
    }
    pair<int, int> a[x*2+3];
    for (int i=0; i<x*2+3; i++) a[i] = make_pair(1000000, 1);
    for (int i=0; i<n; i++){ //считываем массив
        cin >> y;
        a[x+i] = make_pair(y, 1);
    }
    for (int i=x-1; i>0; i--){
        if (a[i*2].first == a[i*2+1].first){
            a[i] = make_pair(a[i*2].first, a[i*2].second + a[i*2+1].second);
        }
        else{
            if (a[i*2].first < a[i*2+1].first) a[i] = a[i*2];
            else a[i] = a[i*2+1];
        }
    }
    for (auto i: a) cout << i.first << ":" << i.second << " ";
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> ip >> pasha;
        add(a, ip+x-1, pasha);
    }
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> l >> r;
        pair<int, int> ans = min_tree(a, l+x-1, r+x-1);
        cout << "min:"<< ans.first << " " << "count:" << ans.second << "\n\n";
    }
}

