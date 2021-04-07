// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  for (int i = 0; i < len - 1; i++)  {
    for (int j = 0; j < len - 1; j++)  {
      if (arr[j] > arr[j + 1]) {
        int x = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = x;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < len - 1; i++)  {
    for (int j = i + 1; j < len - 1; j++)  {
      if ((arr[i] + arr[j] == value) && (i != j))
        res++;
    }
  }
  return res;
}

int countPairs2(int *arr, int len, int value) {
  for (int i = 0; i < len - 1; i++)  {
    for (int j = 0; j < len - 1; j++)  {
      if (arr[j] > arr[j + 1]) {
        int x = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = x;
      }
    }
  }
  int res = 0;
  for (int j = len - 1; j >= 0; j--) {
    if (arr[j] <= value) {
      for (int i = 0; i < j; i++) {
        if (arr[i] + arr[j] <= value) {
          if (arr[i] + arr[j] == value)
            res++;
        }
      }
    }
  }
  return res;
}

int countPairs3(int *arr, int len, int value) {
  for (int i = 0; i < len - 1; i++)  {
    for (int j = 0; j < len - 1; j++)  {
      if (arr[j] > arr[j + 1]) {
        int x = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = x;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < len - 2; i++)  {
    if (arr[i] <= value) {
      int n = value - arr[i];
      int left = i + 1, right = len - 1;
      while (left < right) {
        int c = (left + right) / 2;
        if (arr[c] >= n)
          right = c;
        else
          left = c + 1;
        if (arr[left] == n) {
          while (arr[left] == n) {
            res++;
            left++;
          }
        }
      }
    }
  }
  return res;
}
