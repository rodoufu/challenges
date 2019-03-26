// https://leetcode.com/problems/employee-importance/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> used;
        unordered_map<int, Employee*> empregados;
        for (auto &x : employees) {
            empregados[x->id] = x;
        }
        
        int soma = 0;
        stack<int> buscar;
        buscar.push(id);
        while(!buscar.empty()) {
            int x = buscar.top();
            buscar.pop();
            
            if (used.find(x) == used.end()) {
                used.emplace(x);
                auto empregado = empregados[x];
                for (auto &y : empregado->subordinates) {
                    buscar.push(y);
                }
                soma += empregado->importance;
            }
        }
        return soma;
    }
};
