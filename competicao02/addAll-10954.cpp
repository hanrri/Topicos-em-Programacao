#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;

//codigo vai se basear em um algoritmo guloso, pegamos a soma de dois elementos que nos dara o menor custo,colocamos
//o resultado na fila e retiramos esses valores da fila e repetimos esse processo até ter apenas um elemento na fila

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cho;
    while(1){
        cin>>cho;
        if(cho==0) break;

        priority_queue<int, vi, greater<int>> seq; //uma fila com prioridade para o menor valor sempre ser o primeiro a sair
        
        for(int i=0; i<cho; i++){
            int num;
            cin>>num;
            seq.push(num);
        } // recebe todos os valores a serem somados

        ll cost = 0;

        while(seq.size()>1){ //enquanto tiver mais de 1 número na fila sera possivel fazer somas
            int a=seq.top(); seq.pop(); //pega o menor valor, guarda em a e tira ele da fila
            int b=seq.top(); seq.pop(); //pega o novo menor valor, guarda em b e tira ele da fila também

            int sum=a+b; //soma a e b -> custo
            cost+=sum; //adiciona no custo total
            
            seq.push(sum); //poe o custo dessa soma e adiciona na fila
        }

        cout<<cost<<endl; //imprime o custo total no final de todo processo
    }

    return 0;
}