#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin>>cases; //leitura da quantidade de casos a serem analisados

    while(cases--){ // enquanto tivermos casos, permaneceremos no loop while
        int n,t,m;
        cin>>n>>t>>m; // leitua da quantidade maxima de carros possiveis na balsa, tempo de travessia da balsa e quantidade de carros no caso

        queue<pair<int,int>> seq[2];
        // vamos criar um vector de pares de inteiros, o primeiro será o horario de chegada do carro
        // e o segundo sera o tempo que ele foi desembarcado para podermos imprimir na ordem no output
        // seq[0] -> lado esquerdo; seq[1] -> lado direito; onde iremos "colocar" os carros quando chegam
        
        for(int i=0; i<m; i++){ // vamos receber os carros e coloca-los na ordem nos seus respectivos lados
            int time; // o horario que o carro vai chegar
            string side; // o lado que o carro vai estar
            cin>>time>>side;

            if(side=="left") seq[0].push({time, i}); // se no input dizer que left, poe na fila da esquerda
            else seq[1].push({time, i}); // analogo para a direita
        }

        vi answer(m); // vetor onde vamos guardar a resposta
        int current_time=0; // o "tempo atual"
        int side=0; // o "lado atual" da balsa. 0 -> esquerda; 1 -> direita

        while (!seq[0].empty() || !seq[1].empty()) { // enquanto existirem carros para atravessar, o programa irá rodar
            int next_car = INT_MAX; // uma variavel muito grande para podermos descobrir qual vai ser o próximo carro a atravessar
            if(!seq[0].empty()) next_car = min(next_car, seq[0].front().first); 
            if(!seq[1].empty()) next_car = min(next_car, seq[1].front().first);
            // encontra o proximo carro a atravessar

            current_time = max(current_time, next_car);
            // "avancamos no tempo" para quando for possivel buscar um carro para travessia caso a balsa estiver "ociosa"

            int quant_cars = 0; // contagem de carros que vao entrar, controlar para nao passar do maximo

            // se o lado da balsa nao estiver vazio, o primeiro carro já estiver no lado da balsa
            // e a balsa nao estiver na capacidade maxima, esse carro ira entrar na balsa
            while(!seq[side].empty() && seq[side].front().first <= current_time && quant_cars < n){
                int indice_car = seq[side].front().second; // guardamos o indice desse carro
                answer[indice_car] = current_time+t; // adicionamos o horario de desmbarque do carro no vector de resposta que
                                                    // é igual ao tempo atual mais o tempo de travessia
                seq[side].pop(); // retiramos o carro da fila
                quant_cars++; // incrementa em 1 a quantidade de carro na balsa
            }

            current_time+=t; // adicionamos o tempo de travessia no valor atual
            side^=1; // mudamos o lado da balsa com um xor 
        }
        //quando não tivermos mais carros, teremos terminado o caso

        for(int i=0; i<m; i++){
            cout << answer[i] <<"\n"; //imprimimos o vector de resposta
        }

        if(cases>0) cout << "\n"; // no caso de mais casos, colocamos a separacao de um linha
    }

    return 0;
}