#include <iostream>
using namespace std;

void merge_sort(int *a, int len){
    int b[len];
    if (len == 2){
        if (a[0] > a[1]){
            swap(a[0], a[1]);
            return;
        }
    }
    if (len == 1) return;
    merge_sort(a, len/2);
    merge_sort(a + len/2, len-(len/2));
    int uk1 = 0;
    int uk2 = len/2;
    int ukend = len;
    for (int i=0; i< len; i++){//&&&&!!!!!
        if ((a[uk1] > a[uk2] || uk1 > len/2-1) && uk2 != len){
            b[i] = a[uk2];
            ++uk2;
        }
        else{
            if (uk1<=len/2){
                b[i] = a[uk1];
                ++uk1;
            }
        }
    }
    for (int i=0; i< len; i++) a[i] = b[i];
}

int main(){
    int a[10] = {17, 5, 23, 54, 43, 32, 12, 17, 1};
    merge_sort(a, 9);
    for (int i=0; i<9; ++i) cout << a[i] << " ";
}
