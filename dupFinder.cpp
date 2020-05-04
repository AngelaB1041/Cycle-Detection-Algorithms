#include "dupFinder.h"
#include <unordered_set>
#include <algorithm>

using std::unordered_set;

int dupFinder::FloydsFindDup(int* nums, int numsSize){
    int tortoise;   //slow pointer that moves by 1 space
    int hare;       //fast pointer that moves by 2 spaces

    tortoise = nums[0];
    hare = nums[nums[0]];

    while(tortoise != hare){            //while the pointers do not point to the same number
        tortoise = nums[tortoise];      //move tortoise by one space
        hare = nums[nums[hare]];        //move hare by two spaces
    }

    //Find the beginning of the cycle
    hare = 0;
    while(tortoise != hare){             //Duplicate number is where tortoise and hare meet
        tortoise = nums[tortoise];       //advance tortoise by one
        hare = nums[hare];               //advance hare by one
    }
    return hare;
}




int dupFinder::hashFindDup(int* nums, int numSize){     //Find duplicate using hash table
    unordered_set<int> numbers;

    for(int i = 0; i < numSize; i++){
        //If number not already in hash table, add to table
        if(numbers.find(nums[i]) == numbers.end())
            numbers.insert(nums[i]);
        else
            //If number already in hash table, we know it is the duplicate
            return nums[i];
    }
}




int dupFinder::sortFindDup(int *nums, int numsSize) {    //Find duplicate by sorting

    //sort numbers in the array
    std::sort(nums,nums+numsSize);

    for(int i = 1; i < numsSize; i++){
        //if number is identical to one before it, it must be the duplicate
        if(nums[i] == nums[i-1]){
            return nums[i];
        }
    }

    return -1;
}
