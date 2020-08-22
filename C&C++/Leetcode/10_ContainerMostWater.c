int maxArea(int* height, int heightSize){

    int capacity = 0;
    int i = 0, j = heightSize - 1;
    while(i!=j){

        int tmp = height[i] < height[j] ? (j - i) * (height[i++]) : (j - i) * (height[j--]);
        capacity = tmp > capacity ? tmp : capacity;

    }

    return capacity;

}