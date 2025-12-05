#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; t++)
  {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }
    long long maxi = 0;
    long long mini = 0;
    for (int i = 0; i < n; i++)
    {
      long long red = a[i];
      long long blue = b[i];

      long long best = max(maxi - red, blue - mini);
      long long worst = min(mini - red, blue - maxi);

      maxi = best;
      mini = worst;
    }
    cout << maxi << endl;
  }
  return 0;
}
