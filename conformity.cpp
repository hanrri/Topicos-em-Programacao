#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef set<int> se;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin>>n && n!=0){

        map<se, int> seq;
        
        for(int i=0; i<n; i++)
        {
            se aluno;
            int cinco=5;
            int num;
            while(cinco--)
            {
                cin>>num;
                aluno.insert(num);
            }

            if(seq.find(aluno)!=seq.end())
                seq[aluno]++;
            else
                seq.insert({aluno, 1});
        }

        int maior=0, cont=1;
        for(auto const& [key, value]: seq)
        {
            if(value>maior)
            {
                maior=value;
                cont=1;
            }else if(value==maior)
                cont++;
            else
                continue;
        }

        cout<<maior*cont<<'\n';
    }

    return 0;
}