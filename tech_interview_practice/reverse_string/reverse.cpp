#include <iostream>
#include <string>

using namespace std;

string reverse(string text) {
  if (text.size() <= 1) {
    return text;
  }
  return reverse(text.substr(1)) + text[0];
}

int main() {
  string input;
  cout << "Enter some text: ";
  getline(cin, input);
  cout << reverse(input) << endl;
  return 0;
}
