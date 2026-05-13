#include <bits/stdc++.h>
#include <queue>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;

struct registro{
    int p;
    int pv;
    int q;

    bool operator<(const registro &outro) const{
        if(pv != outro.pv)
        return pv>outro.pv;    

    return q > outro.q;
    }
};

int n;
string line, trash;
priority_queue<registro> query;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(getline(cin, line)){
        if(line == "#") break;
        
        registro regis;
        stringstream ss(line);
        ss>>trash>>regis.q>>regis.p; regis.pv=regis.p;

        query.push(regis);
    }

    cin>>n;

    for(int i=0; i<n; i++){
        registro regis = query.top();
        cout<<regis.q<<endl;
        regis.pv+=regis.p;
        query.pop();
        query.push(regis);
    }

    return 0;
}

