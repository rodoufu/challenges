//https://www.hackerrank.com/challenges/torque-and-development
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    unordered_map<int, unordered_set<int> > graph;
    for (auto &x: cities) {
        graph[x[0] - 1].emplace(x[1] - 1);
        graph[x[1] - 1].emplace(x[0] - 1);
    }

    long cost = 0;
    vector<int> citiesToStart(n);
    std::iota(citiesToStart.begin(), citiesToStart.end(), 0);
    unordered_set<int> visited;
    //printf("n:%d,c_lib:%d,c_road:%d\n", n, c_lib, c_road);
    while (!citiesToStart.empty()) {
        int cityToStart = citiesToStart.back();
        citiesToStart.pop_back();
        if (visited.find(cityToStart) != visited.end()) {
            continue;
        }

        stack<int> toVisit({cityToStart});
        int countCities = 0;
        while (!toVisit.empty()) {
            int city = toVisit.top();
            toVisit.pop();
            if (visited.find(city) != visited.end()) {
                continue;
            }
            visited.emplace(city);
            //printf("%d ", city);
            ++countCities;
            
            for (auto &x : graph[city]) {
                if (visited.find(x) == visited.end()) {
                    toVisit.push(x);
                }
            }
        }
        cost += (countCities - 1) * c_road + c_lib;
        //printf("- cost:%d,countCities:%d\n", cost, countCities);
    }

    return min(cost, 1L * n * c_lib);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
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
