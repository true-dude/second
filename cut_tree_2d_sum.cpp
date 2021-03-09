#include <iostream>
#include <vector>
using namespace std;

int log(int n){
    int x = 1, c =0;
    while (x < n){
        x *= 2;
        c ++;
    }
    return x;
}

void update(vector<vector <int>> &a, int x, int y, int inc){ //увелечение элемента таблицы
    int tx=x, ty = y;
    while (tx > 0){
        ty = y;
        while (ty > 0){
            a[tx][ty] += inc;
            ty /= 2;
        }
        tx /= 2;
    }
}

int get_sum_y(vector<vector <int>> &a, int l, int t, int b){
    int ans = 0;
    while (t < b){
        if (t % 2 == 1){
            ans += a[t][l];
            t ++;
        }
        if (b % 2 == 0){
            ans += a[b][l];
            b --;
        }
        t /= 2;
        b /= 2;
    }
    if (t==b){
        ans += a[t][l];
        cout << "t: " << t << " l: " << l << "\n\n";
    }
    return ans;
}

int get_sum_x(vector<vector <int>> &a, int l, int r, int t, int b){
    int ans = 0;
    while (l<r){
        cout << "l: " << l << " r: " << r << "\n\n";
        if (l % 2 == 1){
            ans += get_sum_y(a, l, t, b);
            l ++;
        }
        if (r % 2 == 0){
            ans += get_sum_y(a, l, t, b);
            r --;
        }
        l /= 2;
        r /= 2;
    }
    if (l == r){
        ans += get_sum_y(a, l, t, b);
    }
    return ans;
}

int main(){
    int n, m, l, r, y, z, i, j, ky, kx, q, xn, xm, t, b;
    cin >> n >> m;
    xn = log(n);
    xm = log(m);
    vector <vector <int>> a(xn*2+3);//[xn*2+3][xm*2+3];
    for (int i=0; i<xn*2+3; i++){ //заполняем нулями
        for (int j=0; j<xm*2+3; j++) a[i].push_back(0);
    }
    for (int i=0; i<n; i++){ // считываем таблицу
        for (int j=0; j<n; j++) cin >> a[i+xn][j+xm];
    }
    for (int i=2*xn-1; i>0; i--){ // строим дерево двумерное отрезков
        for (int j=2*xm-1; j>0; j--){
            //a[i][j] = a[i*2][j*2] + a[i*2+1][j*2] + a[i*2][j*2+1] + a[i*2+1][j*2+1]; //забыл простчитывать некоторые значения (увы не все так просто!!!!)
            //but i wiil do it, i belive in this
            if (i < xn && j < xm) a[i][j] = a[i*2][j*2] + a[i*2+1][j*2] + a[i*2][j*2+1] + a[i*2+1][j*2+1];
            if (i >= xn && j < xm) a[i][j] = a[i][j*2] + a[i][j*2+1];
            if (j >= xm && i < xn) a[i][j] = a[i*2][j] + a[i*2+1][j];
            if (j >= xm && i >= xn) a[i][j] = a[i][j];
        }
    }

    for (auto i: a){
        for (auto j:i) cout << j << " ";
        cout << "\n";
    }
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> ky >> kx >> q;
        update(a, ky, kx, q);
    }
    cin >> z;
    for (int i=0; i<z; i++){
        cin >> l >> r >> t >> b;
        cout << get_sum_x(a, l+xm-1, r+xm-1, t+xn-1, b+xn-1) << "\n";
    }
}

//урааа!!!! вроде все работает
