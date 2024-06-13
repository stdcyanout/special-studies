#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];

void merge_sort(int L,int R)
{
    if(L==R-1)
        return;
    int M=(L+R)/2;
    merge_sort(L,M);
    merge_sort(M,R);
    int tmp[R-L];
    merge(a+L,a+M,a+M,a+R,tmp);
    copy(tmp,tmp+R-L,a+L);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i];
    merge_sort(0,n);
    for(i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
}