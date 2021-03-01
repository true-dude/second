#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main(){
    int n, s, f, el;
    cin >> n >> s >>f;
    vector<vector <int>> ms(n);
    vector<bool> u(n, false);
    vector<vector <pair<int, int>>> g(n);
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin >> el;
            if (el != -1 && el != 0)
                g[i].push_back(make_pair(j, el));
                //g[j].push_back(make_pair(i, el)); //ДЛЯ НЕОРИЕНТИРОВОННОГО
         }
    }
    vector<int> d(n, INF), p(n);
    d[s-1] = 0;
    p[s-1] = -1;
    for (int i=0; i<n; ++i){
        int v = -1;
        for (int j=0; j<n; ++j){
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        //cout << "v:" << v;
        if (d[v] == INF)
            break;

        u[v] = true;

        for (size_t j=0; j<g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if ((d[v] + len) < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                //cout << "\n"<< v << ">>" << to << ">>" << d[to];
            }
        }
    }
    int a=p[f-1];
    vector<int> put;
    while (a!=-1){
        put.push_back(a);
        a = p[a];
    }
    //if (d[f-1] != INF)
    //    cout << d[f-1];
    //else
    //    cout << -1;
    if (put.empty() && f!=s)
        cout << -1;
    else{
        for (size_t i=put.size(); i>0; i--)
            cout << put[i-1]+1 << " ";
        cout << f;
    }
    //for (size_t i=0; i<d.size(); i++)
    //    cout << d[i] << " ";
    //cout << p[s-1];
    //cout << "\n" << d[f-1];
}
