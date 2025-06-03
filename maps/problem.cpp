#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solve(vector<int> &arr, int N, int K)
{
  int sum = 0;
  unordered_map<int, pair<int, int>> mp;
  for (int i = 0; i < N; i++)
  {
    if (arr[i] < 0)
    {

      mp[arr[i]].first = arr[i];
      mp[arr[i]].second = 1;
    }
    else
    {
      mp[arr[i]].first = arr[i];
      mp[arr[i]].second++;
    }
  }
  sort(arr.begin(), arr.end());
  if (N > K)
  {
    for (int i = N - 1; i >= N - K; i--)
    {
      sum += mp[arr[i]].first * mp[arr[i]].second;
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      sum += mp[arr[i]].first * mp[arr[i]].second;
    }
  }

  return sum;
}

int main()
{
  cout << "enter the count: ";
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cout << "enter N and K:" << endl;
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    cout << "enter vector values:" << endl;
    for (int j = 0; j < N; j++)
    {
      cin >> arr[j];
    }
    cout << "max sum is : " << solve(arr, N, K) << endl;
  }
  return 0;
}