#include<iostream>
#include<string>
#include<set>

#include<cstdio>
#include<cstring>

using namespace std;

bool vaiUm(bool *permuta, int len) {
    bool incUm = true;
    for (int i = 0; i < len && incUm; ++i) {
        if (permuta[i]) {
            permuta[i] = false;
        } else {
            permuta[i] = true;
            incUm = false;
        }
    }
    return !incUm;
}

int main() {
    char palavra[1001];
    bool permuta[1001];
    while (scanf("%s", palavra) != EOF) {
        int len = strlen(palavra);
        for (int i = 0; i < len; ++i) {
            permuta[i] = false;
        }
        set<string> palavras;

        while (vaiUm(permuta, len)) {
            string nova;
            for (int i = 0; i < len; ++i) {
                if (permuta[i]) {
                    nova.push_back(palavra[i]);
                }
            }
            palavras.emplace(nova);
        }
        
        for (auto it: palavras) {
            cout << it << endl;
        }
        puts("");
    }
}

