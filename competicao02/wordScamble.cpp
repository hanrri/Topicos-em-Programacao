#include <algorithm>
#include <bits/stdc++.h>
#include <string>

//#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef long long ll;


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    string text;

    while(getline(cin, text)){
        string word="";
        for(auto it:text){
            if(it!=' '){
                word+=it;
            }else{
                reverse(word.begin(), word.end());
                cout<<word<<" ";
                word="";
            }
        }
        reverse(word.begin(), word.end());
        cout<<word<<endl;
    }

    return 0;
}