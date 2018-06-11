
/*
struct retdata {
    int min, max, avg;
};
int super_func(int *arr, unsigned int len, struct retdata *ret) {
    if(!len){ // or (len == 0x00)
        return 0x00; // Means false
    }
    unsigned int cnt;
    ret->min = ret->max = *arr;
    ret->avg = 0;// I don't know the aim of this variable. So let it be the sum of all elements divide by len
    for (cnt = 0; cnt < len; cnt++) {
        if (arr[cnt] < ret->min) {
            ret->min = *arr;
        }
        else if (arr[cnt] > ret->max) {
            ret->max = *arr;
        }
        ret->avg += arr[cnt];
    }
    ret->avg /= len;
    return 0x01; // Means true
}*/
#include <iostream>

using namespace std;

int waterLeft(unsigned int *arr, unsigned int size);

int main() {
unsigned int size;
    cout << "Hello, input the size, please:" << endl;
    cin >>size;
    unsigned int* arr = new unsigned int[size];
    for(unsigned int i = 0; i < size; ++i){
        cout << "Element "<< i+1 << endl;
        cin >> arr[i];
    }
    cout<<"Total number of water is: " << waterLeft(arr,size)<<endl;
    return 0;
}

int waterLeft(unsigned int arr[], unsigned int size) {
    if (!size) {
        return -1;
    }
    int numofWater = 0;
    unsigned int currentMaxPos = 0;
    unsigned int preMax = 0; // this variable is need for the cycle
    unsigned int preMaxPos = 0;
    while (currentMaxPos < size - 1) {
        for (unsigned int i = currentMaxPos + 1; i < size; ++i) { // It searches the pits at maximum attitude
            if (arr[i] >= arr[currentMaxPos]) {
                if (i - currentMaxPos > 1) {
                    for (unsigned int j = currentMaxPos; j < i; ++j) {
                        numofWater += arr[currentMaxPos] - arr[j];
                    }
                }
                currentMaxPos = i;
            }
        }
        for (unsigned int k = currentMaxPos + 1; k < size; ++k) { // If pit is lower than current max, it searches pits at lower attitude
            if (arr[k] >= preMax) {
                preMax = arr[k];
                preMaxPos = k;
            }
        }
        for (int l = currentMaxPos + 1; l < preMaxPos; ++l) { // It goes through the values between max position and premax positions
            numofWater += preMax - arr[l];
        }
        currentMaxPos = preMaxPos;// And then the cycle begins from the rest of unscaned array
        preMax = 0;
        preMaxPos = 0;
    }
    return numofWater;
}