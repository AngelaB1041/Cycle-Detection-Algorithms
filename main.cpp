#include "dupFinder.h"
#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::cout;
using std::endl;

int main() {
    int dataVals[] = {1,3,4,2,5,6,7,9,8,19,17,14,13,12,10,15,16,18,20,11,19};
    int n = sizeof(dataVals) / sizeof(dataVals[0]);

    dupFinder letsLook;
    cout << "Duplicate number: " << letsLook.FloydsFindDup(dataVals,n) << endl;
    cout << "Duplicate number: " << letsLook.sortFindDup(dataVals,n) << endl;
    cout << "Duplicate number: " << letsLook.hashFindDup(dataVals,n) << endl;

    return 0;
}

