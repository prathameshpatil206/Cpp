#include <iostream>
#include <stack>
#include <string>
using namespace std;

// TC=O(n)
// SC=O(n)
bool isValid(string str) {
  int n = str.size();
  stack<char> s;

  for (int i = 0; i < n; i++) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      s.push(str[i]);
    } else {
      if (!s.empty()) {
        if ((s.top() == '{' && str[i] == '}') ||
            (s.top() == '(' && str[i] == ')') ||
            (s.top() == '[' && str[i] == ']')) {
          s.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }

  return s.size() == 0;
}

int main() {
  string s;
  cout << "Enter String: ";
  getline(cin, s);
  cout << isValid(s);
}