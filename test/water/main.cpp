
#include <iostream>

using namespace std;

unsigned int waterLeft(unsigned int *arr, unsigned int size);

int main() {
unsigned int size;
    cout << "Hello, input the size, please:" << endl;
    cin >>size;
    unsigned int arr[size];
    for(unsigned int i = 0; i < size; ++i){
        cout << "Element "<< i+1 << endl;
        cin >> arr[i];
    }
    cout<<"Total number of water is: " << waterLeft(arr,size)<<endl;
    return 0;
}

unsigned int waterLeft(unsigned int arr[], unsigned int size) {
    if (!size) {
        return 0;
    }
    unsigned int numofWater = 0;
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
        if (currentMaxPos < size - 1) {
            for (unsigned int k = currentMaxPos + 1;
                 k < size; ++k) { // If pit is lower than current max, it searches pits at lower attitude
                if (arr[k] >= preMax) {
                    preMax = arr[k];
                    preMaxPos = k;
                }
            }
            for (int l = currentMaxPos + 1;
                 l < preMaxPos; ++l) { // It goes through the values between max position and premax positions
                numofWater += preMax - arr[l];
            }
            currentMaxPos = preMaxPos;// And then the cycle begins from the rest of unscaned array
            preMax = 0;
            preMaxPos = 0;
        }
    }
    return numofWater;
}