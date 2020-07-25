//
// Created by GiTaek Lee on 2020/07/26.
//

// @백준 1339 => 단어수학

// 입력

//첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다.
// 단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고,
// 수의 최대 길이는 8이다. 서로 다른 문자는 서로 다른 숫자를 나타낸다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
char alpha[256];

int calc(vector<string> &a,vector<char> &letters, vector<int> &d){
    int m = letters.size();
    int sum = 0;
    for (int i = 0; i<m; i++){
        alpha[letters[i]] = d[i];
    }

    for (string s: a){
        int now = 0;
        for (char x: s){
            now = now * 10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> letters;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        for(char x : a[i]){
            letters.push_back(x);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(),letters.end()),letters.end());
    int m = letters.size();
    vector<int> d;
    for(int i = 9; i>9-m; i--){
        d.push_back(i);
    }
    sort(d.begin(),d.end()); // next_permutation 위함.
    int ans = 0;
    do {
        int now = calc(a, letters, d);
        if(ans < now)
        {
            ans = now;
        }
    } while (next_permutation(d.begin(),d.end()));

    cout << ans << "\n";
    return 0;
}