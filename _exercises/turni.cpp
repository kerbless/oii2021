//https://training.olinfo.it/#/task/turni/statement
#include <iostream>
#include <map>

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int giorni, persone, start, end, lenght;
    std::cin >> giorni >> persone;
    std::map<int,int> disponib;
    for (int i = 0; i < persone; i++) {
        std::cin >> start >> end;
        lenght = end-start; // !
        disponib.insert(std::pair<int,int>(lenght, start));
    }
    


    for(std::map<int,int>::iterator it = disponib.begin(); it != disponib.end(); it++) {
        std::cout << it->first << it->second << std::endl;
    }
    return 0;
}
