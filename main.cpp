#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::cout;
using std::endl;


int FloydsFindDup(int* nums, int numsSize){
    int tortoise;   //slow pointer that moves by 1 space
    int hare;       //fast pointer that moves by 2 spaces

    tortoise = nums[0];
    hare = nums[nums[0]];

    while(tortoise != hare){            //while the pointers do not point to the same number
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }

    //Find the beginning of the cycle, which is the duplicate number
    hare = 0;
    while(tortoise != hare){
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}

int hashFindDup(int* nums, int numSize){
    unordered_set<int> numbers;

    for(int i = 0; i < numSize; i++){
        if(numbers.find(nums[i]) == numbers.end())
            numbers.insert(nums[i]);
        else
            return nums[i];
    }
}


int main() {
    int dataVals[] = {1,3,4,2,1};
    int n = sizeof(dataVals) / sizeof(dataVals[0]);

    cout << "Duplicate number: " << hashFindDup(dataVals,n) << endl;


    return 0;
}
