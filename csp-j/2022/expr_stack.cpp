#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>

using namespace std;

struct node {
    int v; 
    int y; 
    int h; 
};

int main() {
    ifstream fin("expr.in");
    ofstream fout("expr.out");

    char s[1000002];
    stack<char> q;
    stack<node> n; 

    fin >> s;
    int l = strlen(s);
    s[l] = ')'; 
    q.push('(');

    for (int i = 0; i <= l; i++) {
        if (s[i] == '(') {
            q.push(s[i]);
        }
        else if (s[i] == '0' || s[i] == '1') {
            node temp;
            temp.v = s[i] - '0';
            temp.y = 0;
            temp.h = 0;
            n.push(temp);
        }
        else {
            bool fff = false;
            if (s[i] == ')') {
                fff = true;
                if (q.top() == '(') {
                    q.pop();
                }
                else {
                while (!n.empty() && !q.empty() && 
                (q.top() == '&' || q.top() == '|')) {
                        char z = q.top();
                        q.pop();
                        node a = n.top();
                        n.pop();
                        node b = n.top();
                        n.pop();
                        node temp;
                        temp.y = b.y;
                        temp.h = b.h;
                        if (z == '&') {
                            if (b.v == 0) temp.y++;
                            else {
                                temp.y += a.y;
                                temp.h += a.h;
                            }
                            temp.v = a.v & b.v;
                        }
                        if (z == '|') {
                            if (b.v == 1) temp.h++;
                            else {
                                temp.h += a.h;
                                temp.y += a.y;
                            }
                            temp.v = a.v | b.v;
                        }
                        n.push(temp);
                    }
                    q.pop();
                }
            }
            if (!n.empty() && !q.empty()) {
            while ((q.top() == '&' && (s[i] == '&' || s[i] == '|')) || 
            (q.top() == '|' && s[i] == '|')) {
                    char z = q.top();
                    q.pop();
                    node a = n.top();
                    n.pop();
                    node b = n.top();
                    n.pop();
                    node temp;
                    temp.y = b.y;
                    temp.h = b.h;
                    if (z == '&') {
                        if (b.v == 0) temp.y++;
                        else {
                            temp.y += a.y;
                            temp.h += a.h;
                        }
                        temp.v = a.v & b.v;
                    }
                    if (z == '|') {
                        if (b.v == 1) temp.h++;
                        else {
                            temp.h += a.h;
                            temp.y += a.y;
                        }
                        temp.v = a.v | b.v;
                    }
                    n.push(temp);
                }
            }
            if (fff == false)
                q.push(s[i]);
        }
    }
    
    fout << n.top().v << endl;
    fout << n.top().y << ' ' << n.top().h << endl;

    fin.close();
    fout.close();

    return 0;
}
