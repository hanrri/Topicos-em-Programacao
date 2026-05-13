#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


struct contestant{ // struct com os dados de cada competidor e suas questoes
    int id; // sua identificacao
    bool participation=false; // se ele participou ou nao
    int solved=0; // numero de problemas respodidos corretamente
    int penality=0; // tempo total com penalidades
    int incorrect[11]={0}; // quantas vezes errou cada questao 
    bool correct[11]={false}; // quais questoes acertaram
};

bool comp(const contestant& a, const contestant b){ // comparacao entre structs de participantes
    if(a.participation != b.participation){
        return a.participation > b.participation; // quem participou eh maior que quem nao participou,
    }

    if(a.solved != b.solved){
        return a.solved > b.solved; // quem solucionou mais questoes eh maior, senao
    }

    if(a.penality != b.penality){
        return a.penality < b.penality; // quem tem menos tempo de penalidades eh maior
    }

    return a.id <b.id; // se for tudo igual, imprime na ordem de menor para menos indice
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases; // quantidade de casos a serem analisados
    if(cin>>cases){
        string line; 
        getline(cin, line); // limpa o buffer 
        getline(cin, line); // lemos a linha em branco

        while (cases--) {
            vector<contestant> list(101); // cria o vetor para os 100 competidores

            for(int i=1; i<=100; i++) list[i].id=i; // garantimos que todos existem

            while(getline(cin,line) && line != ""){
                stringstream ss(line); // lemos o valor de uma linha inteira
                int person, problem, time;
                char L;

                ss>>person>>problem>>time>>L; // alocaremos cada valor presente na linha no ser respectivo lugar

                list[person].participation = true; //se um competidor realizou alguma acao, ele esta participando da competicao 

                if(list[person].correct[problem] == false){
                    if(L == 'I'){
                        list[person].incorrect[problem]++; // se o competidor errou uma questao, incrementaremos um erro na questao dentro do array
                    }else if (L == 'C') { // se acertou
                        list[person].correct[problem] = true; // marcaremos a resposta como correta
                        list[person].solved++; // incrementaremos em 1 o valor de questoes respondidas corretamente
                        list[person].penality+=time+(list[person].incorrect[problem]*20); // calcularemos o tempo de penalidade da questao, tempo ate
                                                                                          // ser resolvida  mais 20 minutos por erro ate acertar
                    }
                }
            } // se nao tivermos mais inputs de questoes, passamos para a proxima parte do codigo e depois continuaremos a receber acoes

            sort(list.begin(), list.end(), comp); //ordenaremos os participantes na ordem desejada na questao

            for(int i=0; i<101; i++){
                if(!list[i].participation) break; 
                cout << list[i].id << " " << list[i].solved << " " << list[i].penality << "\n";
                // se o competidor participou, suas informacoes serao impressas na ordem do primeiro ao ultimo
            } // quando acabaremos o caso, iremos para o proximo se existir

            if(cases>0) cout << "\n"; // linha de separacao entre casos
        }
    }

    return 0;
}