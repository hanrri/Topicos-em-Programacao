#include <algorithm>
#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    while(n--){
        int s, d;
        cin>>s>>d;

        /*
        a+b=s
        a-b=d

        a=s+b
        d+2b=s
        b=(s-d)/2

        b=(40-20)/2=10
        a=20+10=30

        b=(20-40)/2=-10
        a=20-10=10

        */

        //tomar cuidado com os números!!!!
        //nao pode ter placar com numeros quebrados
        //pode ter placar zero
        //nao pode ter placar negativo

        int b=(s-d)/2, a=d+b;

        int a2=max(a,b), b2=min(a,b);

        if(a>=0 && b>=0 && ((s-d)%2)==0) cout<<a2<<" "<<b2<<endl;
        else cout<<"impossible"<<endl;
    }

    return 0;
}

