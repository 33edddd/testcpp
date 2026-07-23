#include <bits/stdc++.h>
using namespace std;

int main()
{
      string s;
      getline(cin, s);

      int a[26] = {0};
      for (int i = 0; i < s.length(); i++)
            a[s[i]-'a'] = i;

      string t;
      vector<bool> v(26, false);

      for (int i = 0; i < s.length(); i++)
      {
            if (v[s[i]-'a'])
                  continue;

            while (!t.empty() &&
                   t.back() > s[i] &&
                   a[t.back()-'a'] > i)
            {
                  v[t.back()-'a'] = false;
                  t.pop_back();
            }

            t.push_back(s[i]);
            v[s[i]-'a'] = true;
      }

      cout << t << endl;
}