#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

  unordered_map<string, int> m;

  pair<string, int> p = make_pair("ishan", 3);
  m.insert(p);

  pair<string, int> p2("amrit", 2);
  m.insert(p2);

  m["srivastava"] = 1;
  cout << m.at("ishan") << endl;
  cout << m["yoyoyo"] << endl;
  cout << m.at("yoyoyo") << endl;
  cout << m.size() << endl;
  cout << m.count("aa") << endl;
  cout << m.count("ishan") << endl;
  // m.erase("yoyoyo");
  cout << m.size() << endl;

  // traverse using iterator
  cout << m["yoyoyo"] << endl;
  unordered_map<string, int>::iterator it = m.begin();

  while (it != m.end())
  {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  return 0;
}
