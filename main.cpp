#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <stdexcept>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
  unsigned minIndex = index;
  for (unsigned int i = index; i < vals.size(); ++i){
    if (vals.at(minIndex)> vals.at(i)){
      minIndex = i;
    }
  }
  return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals){
  for (unsigned int i = 0; i + 1 < vals.size(); ++i){
    unsigned minIndex = min_index(vals,i);
    T temp = vals.at(i);
    vals.at(i) = vals.at(minIndex);
    vals.at(minIndex) = temp;
  }
}

template<typename T>
T getElement(vector<T> vals, int index){
  return vals.at(index);
}

vector<char> createVector(){
  int vecSize = rand() % 26;
  char c = 'a';
  vector<char> vals;
  for (int i = 0; i < vecSize; i++){
    vals.push_back(c);
    c++;
  }
  return vals;
}

int main() {
  
  vector<int> vec;
  vec.push_back(10);
  vec.push_back(5);
  vec.push_back(30);
  vec.push_back(15);
  vec.push_back(20);
  vec.push_back(50);
  vec.push_back(40);

  for (unsigned int i = 0; i < vec.size(); ++i){
    cout << vec.at(i) << " " << endl;
  }
  cout << endl;
  cout << "Testing selection sort: " << endl;
  selection_sort(vec);
  
  for (unsigned int i = 0; i < vec.size(); ++i){
    cout << vec.at(i) << " " << endl;
  }
  cout << endl;

  srand(time(0));
  vector<char> vals = createVector();
  char curChar;
  int index;
  int numOfRuns = 10;
  unsigned indexRange = 0;
  while (--numOfRuns >= 0){
    cout << "Enter a number: " << endl;
    cin >> index;

    curChar = getElement(vals, index);
    cout << "Element located at " << index << ": is " << curChar << endl;

    try{
      if (indexRange > vals.size()){
        throw std::out_of_range("Too high");
      }
      return vals.at(indexRange);
    }
    catch (const std::out_of_range &exception){
      cout << "Out of range exception occured" << endl;
    }
  }
  return 0;
}