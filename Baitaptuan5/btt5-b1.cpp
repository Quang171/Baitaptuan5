#include<bits/stdc++.h>
using namespace std;

int cnt[1000];

int color_to_int(string color) {
    if (color == "do") return 0;
    if (color == "trang") return 1;
    return 2; 
}

string int_to_color(int num) {
    if (num == 0) return "do";
    if (num == 1) return "trang";
    return "xanh";
}

int main(){
    int a[1000];
    int n;
    cout<<"Nhập số lượng màu: ";
    cin>>n;
    int m=INT_MIN;
    vector<string> colors(n);
    cout<<"Nhập các màu: ";
    for(int i=0; i<n;i++){
        cin>>colors[i];
    }
    vector<int>mahoa(n);
    for(int i=0;i<n;i++){
        mahoa[i]=color_to_int(colors[i]);
        cnt[mahoa[i]]++;
        m=max(m,mahoa[i]);
    }
  
    for(int i=0;i<=m;i++){
        if(cnt[i]!=0){
            for(int j=0;j<cnt[i];j++){
                cout<<int_to_color(i)<<" ";
            }
        }
    }
    return 0;
}