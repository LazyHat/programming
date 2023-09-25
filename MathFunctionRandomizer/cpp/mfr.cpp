#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <ctime>
#include <vector>
using namespace std;

class node
{
    bool term = true;
    string func;
    string op;
    node *l = nullptr;
    node *r = nullptr;

public:
    node() {}
    node(string function, string operation)
    {
        this->term = false;
        this->func = function;
        this->op = operation;
    }
    node(string function, string variable, bool termnode)
    {
        this->func = function;
        this->op = variable;
    }
    void lset(node *newnode)
    {
        this->l = newnode;
    }
    void rset(node *newnode)
    {
        this->r = newnode;
    }
    node *getl() { return this->l; }
    node *getr() { return this->r; }
    string getfunc() { return func; }
    string getop() { return op; }
};

void readvalues(vector<string> &vals)
{
    string k = "", val;
    while (k == "")
        getline(cin, k);
    istringstream lin(k);
    while (lin >> val)
    {
        vals.push_back(val);
    }
}

node randnode(vector<string> operations, vector<string> functions, vector<string> variables, bool func)
{
    node result;
    if (func)
        result = node(functions[rand() % functions.size()], operations[rand() % operations.size()]);
    else
        result = node({""}, operations[rand() % operations.size()]);
    result.lset(new node(functions[rand() % functions.size()], variables[rand() % variables.size()], true));
    result.rset(new node(functions[rand() % functions.size()], variables[rand() % variables.size()], true));
    return result;
}

void tree(node *first, vector<string> operations, vector<string> functions, vector<string> variables, int countops)
{
    if (countops <= 1)
        return;
    else
    {
        if (rand() % 2 == 0)
        {
            first->lset(new node(randnode(operations, functions, variables, true)));
            tree(first->getl(), operations, functions, variables, --countops);
        }
        else
        {
            first->rset(new node(randnode(operations, functions, variables, true)));
            tree(first->getr(), operations, functions, variables, --countops);
        }
        return;
    }
}

void buildfunc(node *first, string &result)
{
    if (first->getfunc() != "" && first->getfunc() != "-")
    {
        result += first->getfunc() + "(";
    }
    if (first->getl() == nullptr)
    {
        result += first->getop();
    }
    else
    {
        if ((first->getop() == "*" || first->getop() == "/" || first->getop() == "^") && (first->getl()->getop() == "-" || first->getl()->getop() == "+"))
        {
            result += "(";
            buildfunc(first->getl(), result);
            result += ")";
        }
        else
        {
            buildfunc(first->getl(), result);
        }
        result += " " + first->getop() + " ";
        if ((first->getop() == "*" || first->getop() == "/" || first->getop() == "^") && (first->getr()->getop() == "-" || first->getr()->getop() == "+"))
        {
            result += "(";
            buildfunc(first->getr(), result);
            result += ")";
        }
        else
        {
            buildfunc(first->getr(), result);
        }
    }
    if (first->getfunc() != "" && first->getfunc() != "-")
    {
        result += ")";
    }
}

int main()
{
    srand(time(NULL));
    unsigned int countops;
    vector<string> ops, funcs, vars;
    funcs.push_back("");
    cout << "variables: ";
    readvalues(vars);
    cout << "operations: ";
    readvalues(ops);
    for (auto &&i : ops)
    {
        if (i == "-")
        {
            funcs.push_back(i);
            break;
        }
    }
    cout << "functions: ";
    readvalues(funcs);
    cout << "count operations: ";
    cin >> countops;
    for (int i = 0; i < 10; i++)
    {
        node first = randnode(ops, funcs, vars, false);
        tree(&first, ops, funcs, vars, countops);
        string res;
        buildfunc(&first, res);
        cout << "f = " << res << endl;
    }
}