// https://training.olinfo.it/#/task/gator_somme/statement
// Use "ricerca binaria" quindi un set ci sta
#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    

    return 0;
}


/* see
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset<int32_t> arr;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int32_t N, temp, costo = 0;
    cin >> N;
    for(int32_t i = 0; i < N; i++){
        cin >> temp;
        arr.insert(temp);
    }
    while(arr.size() != 1){
        auto i = arr.begin();
        temp = *i;
        arr.erase(arr.begin());
        i = arr.begin();
        temp += *i;
        arr.erase(arr.begin());
        costo += temp;
        arr.insert(temp);
    }
    cout << costo;
    return 0;
}
*/