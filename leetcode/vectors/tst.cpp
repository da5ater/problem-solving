#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // visualize `myGraphJson`!
  string myGraphJson = "{\"kind\":{\"graph\":true},"
                       "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
                       "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
  cout << myGraphJson;
}