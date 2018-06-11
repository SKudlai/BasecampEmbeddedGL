
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
}
