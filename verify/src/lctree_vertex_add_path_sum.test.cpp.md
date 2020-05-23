---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: src/lctree_vertex_add_path_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#25d902c24283ab8cfbac54dfa101ad31">src</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/lctree_vertex_add_path_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 17:50:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_path_sum">https://judge.yosupo.jp/problem/vertex_add_path_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/src/base.hpp.html">src/base.hpp</a>
* :heavy_check_mark: <a href="../../library/src/datastructure/linkcuttree.hpp.html">src/datastructure/linkcuttree.hpp</a>
* :heavy_check_mark: <a href="../../library/src/util/fast_io.hpp.html">src/util/fast_io.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "base.hpp"
#include "util/fast_io.hpp"
#include "datastructure/linkcuttree.hpp"

struct Node {
    using D = ll;
    static D e_d() {
        return 0;
    }
    static D op_dd(const D& l, const D& r) {
        return l + r;
    }
    static D rev(const D& x) {
        return x;
    }
};

int main() {
    Scanner sc(stdin);
    Printer pr(stdout);
    int n, q;
    sc.read(n, q);
    V<LCNode<Node>> lct(n);
    for (int i = 0; i < n; i++) {
        ll a;
        sc.read(a);
        lct[i].init_node(a);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        sc.read(u, v);
        lct[u].link(&(lct[v]));
    }
    for (int i = 0; i < q; i++) {
        int t;
        sc.read(t);
        if (t == 0) {
            int p; ll x;
            sc.read(p, x);
            lct[p].expose();
            lct[p].single_add(x);
        } else {
            int u, v;
            sc.read(u, v);
            lct[u].evert();
            lct[v].expose();
            pr.writeln(lct[v].sm);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/lctree_vertex_add_path_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#line 2 "src/base.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T> ostream& operator<<(ostream& os, const V<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T> ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
    os << "[";
    bool f = false;
    for (auto d : a) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool f = false;
    for (auto d : s) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
    os << "{";
    bool f = false;
    for (auto p : s) {
        if (f) os << ", ";
        f = true;
        os << p.first << ": " << p.second;
    }
    return os << "}";
}

struct PrettyOS {
    ostream& os;
    bool first;

    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif
#line 2 "src/util/fast_io.hpp"
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
#line 1 "src/datastructure/linkcuttree.hpp"
template <class N> struct LCNode {
    using NP = LCNode*;
    using D = typename N::D;
    NP p = nullptr, l = nullptr, r = nullptr;
    int sz = 1;
    bool rev = false;
    D v = N::e_d(), sm = N::e_d();

    void single_set(D x) {
        v = x;
        update();
    }
    void single_add(D x) {
        v = N::op_dd(v, x);
        update();
    }

    void init_node(D _v) {
        v = _v;
        sm = _v;
    }
    void update() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
        sm = l ? N::op_dd(l->sm, v) : v;
        if (r) sm = N::op_dd(sm, r->sm);
    }
    void push() {
        if (rev) {
            if (l) l->revdata();
            if (r) r->revdata();
            rev = false;
        }
    }
    void revdata() {
        rev ^= true;
        swap(l, r);
        sm = N::rev(sm);
    }

    inline int pos() {
        if (p) {
            if (p->l == this) return -1;
            if (p->r == this) return 1;
        }
        return 0;
    }
    void rot() {
        NP q = p->p;
        int pps = p->pos();
        if (pps == -1) q->l = this;
        if (pps == 1) q->r = this;
        if (p->l == this) {
            p->l = r;
            if (r) r->p = p;
            r = p;
        } else {
            p->r = l;
            if (l) l->p = p;
            l = p;
        }
        p->p = this;
        p->update();
        update();
        p = q;
        if (q) q->update();
    }
    void all_push() {
        if (pos()) p->all_push();
        push();
    }
    void splay() {
        all_push();
        int ps;
        while ((ps = pos())) {
            int pps = p->pos();
            if (!pps) {
                rot();
            } else if (ps == pps) {
                p->rot();
                rot();
            } else {
                rot();
                rot();
            }
        }
    }
    void expose() {
        NP u = this, ur = nullptr;
        do {
            u->splay();
            u->r = ur;
            u->update();
            ur = u;
        } while ((u = u->p));
        splay();
    }
    // 親としてnpを接続する
    void link(NP np) {
        evert();
        np->expose();
        p = np;
    }
    // 親から自分を切り離す
    void cut() {
        expose();
        assert(l);
        l->p = nullptr;
        l = nullptr;
        update();
    }
    void evert() {
        expose();
        revdata();
    }

    NP lca(NP n) {
        n->expose();
        expose();
        NP t = n;
        while (n->p != nullptr) {
            if (!n->pos()) t = n->p;
            n = n->p;
        }
        return (this == n) ? t : nullptr;
    }
};
#line 6 "src/lctree_vertex_add_path_sum.test.cpp"

struct Node {
    using D = ll;
    static D e_d() {
        return 0;
    }
    static D op_dd(const D& l, const D& r) {
        return l + r;
    }
    static D rev(const D& x) {
        return x;
    }
};

int main() {
    Scanner sc(stdin);
    Printer pr(stdout);
    int n, q;
    sc.read(n, q);
    V<LCNode<Node>> lct(n);
    for (int i = 0; i < n; i++) {
        ll a;
        sc.read(a);
        lct[i].init_node(a);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        sc.read(u, v);
        lct[u].link(&(lct[v]));
    }
    for (int i = 0; i < q; i++) {
        int t;
        sc.read(t);
        if (t == 0) {
            int p; ll x;
            sc.read(p, x);
            lct[p].expose();
            lct[p].single_add(x);
        } else {
            int u, v;
            sc.read(u, v);
            lct[u].evert();
            lct[v].expose();
            pr.writeln(lct[v].sm);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
