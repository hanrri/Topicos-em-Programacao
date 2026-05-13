#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;

//codigo se baseia em uma pilha, percorremos a string com a sequencia e guardamos a abertura dos parenteses
//e colchetes somente,se encontramos um fechamento, verificamos se existe uma abertura no topo da pilha
//do respectivo caractere, se houver, retiramos ele do topo da pilha e continuamos a percorrer, se não tiver,
//já temos como output "No". Se chegarmos ao fim da string e pilha estiver vazia, o output sera "Yes"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int quant; //quantidade de sequecias a serem analisadas
    if(cin>>quant){
        cin.ignore(); //limpamos o buffer para nao atrapalhar na leitura das sequencias

        for(int i=0; i<quant; i++){
            string seq; 
            getline(cin, seq); //lemos a sequencia

            stack<char> here;
            bool confirm = true;
            for(auto x: seq){
                if(x == '(' || x == '[') here.push(x); //se for uma abertura, vai para a pilha
                else if (x == ')'){
                    if(!here.empty() && here.top() == '(') here.pop(); //se for um fechamento, procura a abertura
                    else{
                        confirm = false; //se nao tiver, simplesmente "No"
                        break;
                    }
                }else if (x == ']'){
                    if(!here.empty() && here.top() == '[') here.pop(); //mesma coisa dos parenteses
                    else{
                        confirm = false;
                        break;
                    }
                }
            }
            if(!here.empty()){ 
                confirm = false; //se a pilha no final estiver vazia, deu tudo certo
            }
            if(confirm) cout << "Yes" << "\n";
            else cout << "No" << "\n"; //simplesmente a impressao do output controlado pelo bool confirme
        }
    }

    return 0;
}