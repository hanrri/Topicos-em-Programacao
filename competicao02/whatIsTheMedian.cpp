#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    priority_queue<int> esq; //maior no topo(mesmo tamanho que o dir ou 1 elemento a mais)
    priority_queue<int> dir; //menor no topo

    while(cin>>n){
        if(esq.empty()){
            esq.push(n);
        }else if(n<=esq.top()){
            esq.push(n);
            if(esq.size()>dir.size()+1){
                dir.push(-esq.top());
                esq.pop();
            }
        }else{
            dir.push(-n);
            if(dir.size()>esq.size()){
                esq.push(-dir.top());
                dir.pop();
            }
        }

        if((esq.size()+dir.size())%2 !=0) cout<<esq.top()<<endl;
        else cout<< ((esq.top()-dir.top())/2) << endl;
    }

    return 0;
}