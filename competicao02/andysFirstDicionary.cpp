#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text;
    set<string> dicionary;
    
    while (getline(cin, text)) {
        for(auto &it:text){
            if(isalpha(it)){
                it=tolower(it);
            }else{
                it=' ';
            }
        }

        string word;
        stringstream ss(text);

        while(ss >> word){
            dicionary.insert(word);
        }
    }

    for(auto it:dicionary){
        cout<<it<<endl;
    }

    return 0;
}

