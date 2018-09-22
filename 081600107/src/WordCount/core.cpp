#include "stdafx.h"
#include "core.h"

bool checkword(char ch) { return ch >= 'a' && ch <= 'z'; }

bool checknumber(char ch) { return ch >= '0' && ch <= '9'; }

struct Trie {
	static const int N = 2000006;
	int son[N][36], _, cnt[N];
	int ne() { fill_n(son[_], 36, -1); cnt[_] = 0; return _++; }
	void ini() { _ = 0; ne(); }
	set<int> Set;
	void add(const string &s) {
		int u = 0;
		for (auto ch : s) {
			int &v = son[u][checkword(ch) ? ch - 'a' + 10 : ch - '0'];
			if (!~v) v = ne();
			u = v;
		}
		cnt[u]++;
	}
	void qry(int u, vector<pair<string, int> > & tmp, string s) {
		if (cnt[u] > 0 && (sz(Set) < 10 || cnt[u] > *Set.begin())) {
			Set.insert(cnt[u]);
			tmp.pb(mp(s, cnt[u]));
			if (sz(Set) > 10) Set.erase(Set.begin());
		}
		rep(i, 0, 36) {
			int &v = son[u][i];
			if (~v) {
				qry(v, tmp, s + char(i < 10 ? i + '0' : i + 'a' - 10));
			}
		}
	}
} tree;

int CountChar(char *name) {
	int ch;
	FILE *stream;
	freopen_s(&stream, name, "r", stdin);
	int characters = 0, now = -1;
	while (ch = getchar()) {
		if (ch == -1) break;
		characters++;
	}
	if (characters == 0) { 
		cout << "File not found!"; 
		exit(1);
	}
	return characters;
}

pii CountWord(char *name) {
	int ch;
	FILE *stream;
	freopen_s(&stream, name, "r", stdin);
	int words = 0, line = 0, now = -1;
	while (ch = getchar()) {
		if (ch == -1) { if (now >= 4) words++; break; }
		if (ch == '\n') { if (now >= 4) words++; now = -1; continue; }
		if (ch >= 'A' && ch <= 'Z') ch -= 'A' - 'a';
		if (now == -2) { if (!checkword(ch) && !checknumber(ch)) now = 0; continue; }
		if (checkword(ch)) { if (now == -1) now = 1, line++; else now++; continue; }
		if (checknumber(ch)) {
			if (now == -1) now = -2, line++;
			else if (now >= 4) now++;
			else now = -2;
			continue;
		}
		if (now == -1) { if (ch != ' ') now = 0, line++; continue; }
		if (now >= 4) words++; now = 0;
	}
	return mp(words, line);
}

vector<pair<string, int> > CountFrequentWord(char *name) {
	FILE *stream;
	string s; tree.ini();
	freopen_s(&stream, name, "r", stdin);
	int now = -1, ch;
	while (ch = getchar()) {
		if (ch == -1) { if (now >= 4) tree.add(s); s = ""; break; }
		if (ch == '\n') { if (now >= 4) tree.add(s); s = ""; now = -1; continue; }
		if (ch >= 'A' && ch <= 'Z') ch -= 'A' - 'a';
		if (now == -2) { if (!checkword(ch) && !checknumber(ch)) now = 0; continue; }
		if (checkword(ch)) { if (now == -1) now = 1; else now++; s += ch; continue; }
		if (checknumber(ch)) {
			if (now == -1) now = -2;
			else if (now >= 4) now++, s += ch;
			else now = -2, s = "";
			continue;
		}
		if (now >= 4) tree.add(s); s = ""; now = 0;
	}
	vector<pair<string, int> > tmp;
	tree.qry(0, tmp, "");
	int n = sz(tmp);
	if (sz(tmp) >= 10) {
		nth_element(tmp.begin(),tmp.begin() + 10, tmp.end(), [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
		n = 10;
	}
	sort(tmp.begin(), tmp.begin() + n, [&](pair<string, int> a, pair<string, int> b) {if (a.se != b.se) return a.se > b.se; return a.fi < b.fi; });
	return tmp;
}
