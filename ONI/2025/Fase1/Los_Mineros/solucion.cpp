#include <bits/stdc++.h>
using namespace std;

// Representa los últimos dos envíos en una mina
struct State {
    int a, b; // -1 = ninguno, 0=M,1=F,2=B
    State(int x=-1,int y=-1):a(x),b(y){}
};

// Calcula la cantidad de carbón producido al añadir el envío x
int gain(State st, int x){
    vector<int> types;
    types.push_back(x);
    if(st.a != -1) types.push_back(st.a);
    if(st.b != -1) types.push_back(st.b);
    sort(types.begin(), types.end());
    types.erase(unique(types.begin(), types.end()), types.end());
    return types.size();
}

// Actualiza el estado con el nuevo envío x
State update(State st, int x){
    if(st.a == -1) return State(x, -1);
    if(st.b == -1) return State(st.a, x);
    return State(st.b, x); // solo conservar los dos últimos
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    string s;
    cin >> n >> s;

    // Convertir letras a números: M=0, F=1, B=2
    auto encode = [&](char c){
        return (c=='M'?0:c=='F'?1:2);
    };

    // Generar todos los posibles estados
    vector<State> states;
    map<pair<int,int>,int> id;
    auto getId = [&](State st){
        pair<int,int> key = {st.a, st.b};
        if(!id.count(key)){
            int idx = states.size();
            id[key] = idx;
            states.push_back(st);
        }
        return id[key];
    };

    vector<int> vals = {-1,0,1,2};
    for(int a:vals) for(int b:vals){
        if(a==-1 && b!=-1) continue; // inválido
        getId(State(a,b));
    }

    int S = states.size();
    const int NEG = -1e9;
    vector<vector<int>> dp_prev(S, vector<int>(S, NEG));
    vector<vector<int>> dp_cur(S, vector<int>(S, NEG));

    int emptyId = getId(State(-1,-1));
    dp_prev[emptyId][emptyId] = 0;

    for(int i=0;i<n;i++){
        int x = encode(s[i]);
        for(int u=0;u<S;u++) for(int v=0;v<S;v++){
            if(dp_prev[u][v]==NEG) continue;
            // Asignar envío a mina 1
            State st1 = states[u];
            int g1 = gain(st1, x);
            State ns1 = update(st1, x);
            int id1 = getId(ns1);
            dp_cur[id1][v] = max(dp_cur[id1][v], dp_prev[u][v] + g1);

            // Asignar envío a mina 2
            State st2 = states[v];
            int g2 = gain(st2, x);
            State ns2 = update(st2, x);
            int id2 = getId(ns2);
            dp_cur[u][id2] = max(dp_cur[u][id2], dp_prev[u][v] + g2);
        }
        dp_prev.swap(dp_cur);
        for(auto &row: dp_cur) fill(row.begin(), row.end(), NEG);
    }

    int ans = 0;
    for(int u=0; u<S; u++)
        for(int v=0; v<S; v++)
            ans = max(ans, dp_prev[u][v]);

    cout << ans << "\n";
}