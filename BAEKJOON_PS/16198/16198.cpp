//
// Created by GiTaek Lee on 2020/07/26.
//

// 백준 16198 => 에너지 모으기

#include <iostream>
#include <vector>


using namespace std;

int go(vector<int> &a){
    int n = a.size();
    if(n==2) return 0;
    int ans = 0;
    for(int i = 1; i<n-1; i++){
        int energy = a[i-1] * a[i+1];
        vector<int> b(a);
        b.erase(b.begin()+i);
        energy += go(b);
        if(ans < energy)
        {
            ans = energy;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    cout << go(a) << "\n";


    return 0;
}