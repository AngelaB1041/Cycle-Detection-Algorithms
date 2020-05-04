#ifndef CYCLE_DETECTION_ALGORITHMS_DUPFINDER_H
#define CYCLE_DETECTION_ALGORITHMS_DUPFINDER_H

class dupFinder {
public:
    int sortFindDup(int* nums, int numsSize);
    int hashFindDup(int* nums, int numSize);
    int FloydsFindDup(int* nums, int numsSize);


};


#endif //CYCLE_DETECTION_ALGORITHMS_DUPFINDER_H
