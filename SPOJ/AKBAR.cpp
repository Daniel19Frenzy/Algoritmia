//https://www.spoj.com/problems/AKBAR/
#include <bits/stdc++.h>
using namespace std;

bool undirected = true;
vector<vector<int>> adj;
vector<bool> checked;
vector<int> turnos;
vector<pair<int,int>> nodeStrength;
int protegidos=0;
int turno =0;
//vector<bool> sourceNode;


void initialize(int n){
	adj.resize(n);
	turnos.resize(n);
	//sourceNode.resize(n,false);
	//padres.resize(n);
	checked.resize(n,false);
	//undirected = u;
}

void addEdge(int u, int v){
	adj[u].push_back(v);
	if(undirected)
		adj[v].push_back(u);
}

void addSoldier(int u, int s){
	pair<int,int> aux;
	aux.first = u;
	aux.second = s;
	nodeStrength.push_back(aux);
}

bool bfs(int u,int s){
	unordered_map <int,int> parent;
	unordered_map<int,bool> processedTurn;
	queue<int> q;
	int ultimo=u;
	if(checked[u]){
		cout << "Trone al entrar con: " << u << endl;
		return false;
	}
	q.push(u);
	
	processedTurn[u] = true;
	checked[u]=true;
	//turnos[u] = turno;
	protegidos++;
	int v,cont=0;
	while(cont < s){
		v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); ++i){
			cout << "Checo arista de " << v+1 << " hacia " << adj[v][i]+1 << endl;
			if(processedTurn.count(adj[v][i]) > 0)
				continue;

			if(!checked[adj[v][i]]){
				checked[adj[v][i]] = true;
				//turnos[adj[v][i]] = turno;

				processedTurn[adj[v][i]] = true;
				
				protegidos++;
				q.push(adj[v][i]);
				//parent[adj[v][i]] = v;

				cout << "Agrego a: " << adj[v][i] +1<< endl;
				//cout << "Agrego padre de: " << adj[v][i] << " es " << v << endl;
				//cout << "El i es de: " << i << " el tamanio es de: "<< adj[v].size() << "y el v es: " << v << " y el ultimo es: " << ultimo << endl;
				if(i == adj[v].size() -1 && v == ultimo){
					ultimo = adj[v][i];
					cout << "El ultimo es: " << ultimo +1<< endl;
					cont++;
				}
			}
			else{
				
				//cout << "El padre de: " << v << " es " << parent[v];
				cout << "Trono por que topo con: " << adj[v][i] +1 << endl;
				//cout << "El turno en el que estas es: " << turno << "y el turno del nodo es: " << turnos[adj[v][i]] << endl;
				if(!processedTurn.count(adj[v][i])){
					return false;
				}
			}
		}
		//checked[v] = true;
	}
	return true;
}

int main(){
	int T,N,R,M;
	int u,v,s;
	cin >> T;
	for (int k = 0; k < T; ++k){
		cin >> N >> R >> M;
		initialize(N);
		for (int i = 0; i < R; ++i)
		{
			cin >> u >> v;
			addEdge(u-1,v-1);
		}
		for (int i = 0; i < M; ++i)
		{
			cin >> u >> s;
			addSoldier(u-1,s);
			//sourceNode[u-1]=true;
		}
		bool flag = true;
		for (int i = 0; i < nodeStrength.size(); ++i){
			turno++;
			if(!bfs(nodeStrength[i].first,nodeStrength[i].second)){
				cout << "No\n";
				flag = false;
				break;
			}
		}
		if(flag){
			//cout << "Ahora checamos el numero de protegidos\n";
			if(protegidos != N)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		adj.clear();
		checked.clear();
		nodeStrength.clear();
		turnos.clear();
		protegidos=0;
		//sourceNode.clear();
	}
	return 0;
}
