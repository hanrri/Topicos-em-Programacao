#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef set<int> se;
typedef stack<int> st;

int n;

bool pega(vi& i, st& ii, vi& iii){
    if(iii.empty())
        return true;
    
    if(!ii.empty() && iii.front()==ii.top()){
        iii.erase(iii.begin());
        ii.pop();
        return pega(i, ii, iii);

    }else if(ii.empty() || iii.front()!=ii.top()){
        if(!i.empty() && iii.front()==i.front()){
            i.erase(i.begin());
            iii.erase(iii.begin());
            return pega(i, ii, iii);

        }else{
            if(!i.empty()){
                ii.push(i.front());
                i.erase(i.begin());
                return pega(i, ii, iii);

            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n && n != 0){
        string line;
        getline(cin, line);

        while(getline(cin, line) && line != "0"){
            vi inicio, fim;
            stringstream ss(line);
            int nt=n, num, cont=0;
            while(nt--){
                ss>>num;
                fim.push_back(num);
                inicio.push_back(++cont);
            }

            st meio;
            if(pega(inicio, meio, fim))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        cout<<'\n';
    }

    return 0;
}