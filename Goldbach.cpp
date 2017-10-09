#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector<bool> es_primo;
vector<lli> primos;

void criba(lli n){
	es_primo.resize(n + 1, true);
	es_primo[0] = es_primo[1] = false;
	es_primo[2] = true;
	primos.push_back(2);
	for(lli i = 4; i <= n; i += 2){
		es_primo[i] = false;
	}
	lli limit = sqrt(n);
	for(lli i = 3; i <= n; i += 2){
		if(es_primo[i]){
			primos.push_back(i);
			if(i <= limit){
				for(lli j = i * i; j <= n; j += 2 * i){
					es_primo[j] = false;
				}
			}
		}
	}
}

bool isPrime(lli n){
	if(n <= 31622){
		return es_primo[n];
	}else{
		for(lli & p : primos){
			if(p * p > n) break;
			if(n % p == 0) return false;
		}
		return true;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	criba(31622);
	lli n;
	while(true){
		cin >> n;
		if(n == 0ll)
			break;
		lli j = n - 2;
		for (lli i= 2; i <= j ; i+=1,j-=1)
		{
			if(isPrime(i) && isPrime(j)){
				cout << n <<" = " << i << " + " << j << endl;
				break;
			}
		}
	}
	
	return 0;
}