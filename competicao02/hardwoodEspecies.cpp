#include <bits/stdc++.h>
#include <cstdio>
#include <iomanip>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n)!=0) return 0;

    string name;
    getline(cin, name); //limpa o enter
    getline(cin, name); //consome a linha em branco

    while(n--){
        map<string, double> wood;
        double total=0;
        while(getline(cin, name) && name!=""){
            if(wood.find(name)==wood.end()){
                wood.insert({name, 1});
                total++;
            }else{
                wood[name]++;
                total++;
            }
        }

        for(auto const& [arvore, quant]: wood){
            cout<< arvore << " " << fixed << setprecision(4) << 100*quant/total << "\n";
        }
        if(n>0) cout<<'\n';
    }

    return 0;
}