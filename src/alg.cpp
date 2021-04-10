// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count = 0;
for (int i = 0; i < len; ++i) {
for (int j = i+1; j < len; ++j) {
if (arr[i] + arr[j] == value)
count += 1;
}
}
return count;
}

int countPairs2(int* arr, int len, int value) {
int count = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
    mid = (i + j) / 2;
    if (arr[mid] <= value)
    i = mid + 1;
    else
    j = mid;
    }
    while (j > 0) {
        while (i < j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
            ++i;
        }
        i = 0;
        --j;
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int i = 0;
    int mid;
    int j = len - 1;
    while (i < j) {
    mid = (i + j) / 2;
    if (arr[mid] <= value)
    i = mid + 1;
    else
    j = mid;
    }
    for (i; i < j; ++i) {
        int left = i;
        int right = j;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] == (value - arr[i])) {
                count += 1;
                int cnt = 1;
                while ((arr[mid + cnt] == (value - arr[i])) && cnt < j) {
                    count += 1;
                    ++cnt;
                }
                cnt = 1;
                while ((arr[mid - cnt] == (value - arr[i])) && cnt> i) {
                    count += 1;
                    --cnt;
                }
                break;
            } else { if ((value-arr[left]) < arr[mid])
                right = mid;
            else
                left = mid;}
        }
    }
    return count;
}
