//
// Created by Machine on 26.10.2020.
//
#include "LibSearches.h"
int BinarySearch(const char a[],int leng, char searchKey ) {
    int midd = 0;
    int left = 0;
    int right = leng - 1;
    while (1) {
        midd = (left + right) / 2;

        if (searchKey < a[midd])
            right = midd - 1;
        else if (searchKey > a[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}
    int InterpolationSearch(const char a[],int leng, char key ){
        int low = 0;
        int high = leng - 1;
        int mid;
        while (a[low] < key && a[high] >= key) {
            mid = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);
            if (a[mid] < key) {
                low = mid + 1;
            }
            else {
                if (a[mid] > key)
                    high = mid - 1;
                else
                    return mid;
            }
        }
        if (a[low] == key)
            return low;
        return -1;
    }

