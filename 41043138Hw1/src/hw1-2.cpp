#include <stdio.h>
#include <iostream>
using namespace std;

int ackermann(int m, int n) {
    int array[100]; 
    int a = -1; //初始化堆疊
    array[++a] = m;
    while (a >= 0) {
        //若堆疊不為0,則繼續執行
        m = array[a--];
        if (m == 0) {
            n = n + 1;
        }//當m為0,回傳n+1
        else if (n == 0) {
            array[++a] = m - 1;
            n = 1;
        }//當n為0,m=m-1,n=1
        else {
            array[++a] = m - 1;
            array[++a] = m;
            n = n - 1;
        }//當m,n不等於0,m=m-1，n=ackermann(m, n - 1)
    }
    return n;
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    cout << "ackermann(" << m << ',' << n << ") = " << ackermann(m, n);
    return 0;
}
