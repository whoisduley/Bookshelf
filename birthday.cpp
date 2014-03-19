#include<iostream>
#include<vector>
#include<cstdlib>  // RAND_MAX and atoi
#include<algorithm>

using namespace std;

// write your countDupes here

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int numDupes = 0;   // try running uninitialized
  int numTrials = atoi(argv[1]);
  int classSize = atoi(argv[2])

  for(int t = 0; t < numTrials; t++) {
    vector<int> bdayList;
    for(int i = 0; i < classSize; i++) {
      bdayList.push_back(rand()%365);
    }

    bool foundDupe = false;
    for (auto i =  bdayList.begin(); i != bdayList.end(); i++) {
      int myCount = countDupes(bdayList);
      if (myCount > 1) {
      	foundDupe = true;
      }
    }
    if (foundDupe)
      numDupes++;
  }
  float prob = float(numDupes) / numTrials;
  cout << "probability of duplicate = " << prob << endl;

  return 0;
}
