//https://www.hackerrank.com/challenges/bfsshortreach
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define PATH(X,F,T) ((X)[F].find(T) != (X)[F].end() || (X)[T].find(F) != (X)[T].end())

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    unordered_map<int, unordered_set<int> > graph;
    for (auto &x : edges) {
        graph[x[0] - 1].emplace(x[1] - 1);
    }

    unordered_map<int, int> dist;
    unordered_set<int> left;
    queue<tuple<int, int> > use;
    auto max_dist = 2 * m;
    for (int i = 0; i < n; ++i) {
        if (i + 1 != s) {
            dist[i] = max_dist;
            left.emplace(i);
        }
    }
    use.push(make_tuple(s - 1, 0));
    //printf("n:%d,m:%d,s:%d\n", n, m, s);
    while (!use.empty()) {
        auto it_i = use.front();
        use.pop();
        auto it = get<0>(it_i);
        auto height = get<1>(it_i);
        //printf("w:%d\n", it);

        for (int i = 0; i < n; ++i) {
            if (i + 1 != s) {
                //printf("i:%d", i);
                if (PATH(graph, it, i)) {
                    //printf("-");
                    if (left.find(i) != left.end()) {
                        use.push(make_tuple(i, height + 1));
                        left.erase(i);
                    }

                    if (dist[i] > height + 1) {
                        dist[i] = height + 1;
                    }
                }
                //putchar('\n');
            }
        }
    }

    vector<int> resp;
    for (int i = 0; i < n; ++i) {
        if (i + 1 != s) {
            resp.push_back(dist[i] == max_dist ? -1 : 6 * dist[i]);
        }
    }
    return resp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
