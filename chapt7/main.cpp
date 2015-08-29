#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, Rule_Collection> Grammar;

vector<string> split(const string &s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = begin(s);
    while (b != end(s)) {
        b = find_if(b, end(s), [](char c) -> bool { return !isspace(c); });
        iter e = find_if(b, end(s), [](char c) -> bool { return isspace(c); });

        if (b != e) {
            ret.push_back(string(b, e));
        }
        b = e;
    }
    return ret;
}

Grammar read_grammar(istream &in) {
    Grammar ret;
    string s;
    while (getline(in, s)) {
        auto entry = split(s);
        if (!entry.empty()) {
            ret[entry[0]].push_back(Rule(begin(entry) + 1, end(entry)));
        }
    }
    return ret;
}

/*
 * define nrand() function
 */

int nrand(int n) {
    if (n <= 0 || n > RAND_MAX) {
        throw domain_error("random number out of range");
    }

    const int bucket_size = RAND_MAX / n;
    int r;

    do {
        r = rand() / bucket_size;
    } while( r >= n);
    return r;
}
/*
 * using gen_aux to choose word and expand it according to grammar, add the result to ret
 */
void gen_aux(Grammar &g, const string &word, vector<string> &ret) {
    // lambda function to check whether a string is bracked
    auto bracked = [](const string& s){return s.size() > 1 && *(begin(s)) == '<' && *(end(s)-1) == '>';};

    if (!bracked(word)) {
        ret.push_back(word);
    }
    else {
        auto it = g.find(word);
        if (it == end(g)) {
            throw logic_error("empty rule");
        }
        const auto& c = it->second;
        const auto& r = c[nrand(c.size())];
        for (const auto &i : r) {
            gen_aux(g, i, ret);
        }
    }
}

vector<string> gen_sentence(Grammar g) {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void counter_test() {
    ios::sync_with_stdio(false);
    vector<string> strs{"hello", "hello", "world", "jellyshen"};
    map<string, int> counter;

    for (const auto &s : strs) {
        counter[s]++;
    }

    for (const auto &c : counter) {
        cout << c.first << " " << c.second << "\n";
    }
}


map<string, vector<int>> xref(istream &in, vector<string> find_words(const string &) = split) {
    map<string, vector<int>> ret;
    string s;
    int line_number = 0;
    while (getline(cin, s)) {
        line_number++;
        auto v = find_words(s);
        for (const auto &i : v) {
            ret[i].push_back(line_number);
        }
    }
    return ret;
}


int main() {
//    counter_test();
//    map<string, vector<int>> m;
//    m["a"].push_back(3);
//    for (auto &i : m) {
//        cout << i.first << " " << i.second[0] << "\n";
//    }
//    cout << m.size() << "\n";
//
//    auto v = xref(cin);
//    for (const auto &i : v) {
//        cout << i.first << " ";
//        for (const auto &j : i.second) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }

    vector<string> v = gen_sentence(read_grammar(cin));
    for (const auto &i : v) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}