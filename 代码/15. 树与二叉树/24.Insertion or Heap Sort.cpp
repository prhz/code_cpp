#include <stdio.h>
#include <algorithm>
using namespace std;
bool isEqual(int array1[105], int array2[105], int n);
bool isEqual2(int array1[105], int array2[105], int n);
void InsertionSort(int array[105], int tempdata[105],int n, bool &flag);
void heapSort(bool &flag, int tempdata[105]);
void downAdjust(int low, int high);
void createHeap();
int heap[105];
int n;
int main()
{
   
    int inputdata[105];
    int tempdata[105];
    scanf("%d", &n);
    for(int i = 0; i< n;i++)
    {
        scanf("%d", &inputdata[i]);
    }

    for(int i = 0; i< n;i++)
    {
        scanf("%d", &tempdata[i]);
    }
    bool flag2 = false;

    for(int i = 0; i< n;i++)
    {
        heap[i+1] = inputdata[i];
    }

    bool flag1 = false;
    InsertionSort(inputdata, tempdata, n, flag1);
    if(flag1){
        printf("Insertion Sort\n");
        for(int i = 0; i < n;i++)
        {
            printf("%d", inputdata[i]);
            if(i<n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
   

    heapSort(flag2, tempdata);
    
    if(flag2){
        printf("Heap Sort\n");
        for(int i = 0; i < n;i++)
        {
            printf("%d", heap[i+1]);
            if(i<n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }

    return 0;
}

void InsertionSort(int array[105], int tempdata[105],int n, bool &flag)
{
    flag = false;
    for(int i = 1; i < n; i++)
    {
        // 
        if(array[i] < array[i-1]){ // 移动元素
            int temp = array[i];
            int j;
            for(j = i-1 ; array[j]>temp && j >=0; j--)
            {
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }// 否则，进入下一个元素
        if(isEqual(array, tempdata, n)){
            flag = true;
            i++;
            if(array[i] < array[i-1]){ // 移动元素
                int temp = array[i];
                int j;
                for(j = i-1 ; array[j]>temp && j >=0; j--)
                {
                    array[j+1] = array[j];
                }
                array[j+1] = temp;
            }// 否则，进入下一个元素
            break;
        }
    }


}
bool isEqual(int array1[105], int array2[105], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(array1[i]!=array2[i]){
            return false;
        }
    }
    return true;
}

void downAdjust(int low, int high)
{
    int parent = low;
    int child = parent * 2;
    while(child <= high){ // 存在左孩子
        if(child + 1 <= high && heap[child+1] > heap[child]){ // 存在右孩子且右孩子值更大
            child = child + 1;
        }
        if(heap[child] > heap[parent]){ // 调整
            swap(heap[child], heap[parent]);
            parent = child; // 继续向下调整指导 没有孩子
            child = parent * 2;
        }else{ // 满足堆的定义，不需要调整了
            break;
        }
    }
}
// 时间复杂度 O(n)
void createHeap()
{
    for(int i = n/2; i>=1; i--)
    {
        downAdjust(i, n);
    }
}

void heapSort(bool &flag, int tempdata[105])
{
    flag = false;
    createHeap();
    
    for(int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        downAdjust(1, i-1);
        if(isEqual2(heap, tempdata, n)){

            flag = true;
            i--;
            swap(heap[1], heap[i]);
            downAdjust(1, i-1);
            break;
        }
    }
    
}
bool isEqual2(int array1[105], int array2[105], int n)
{
    for(int i = 0; i< n;i++)
    {
        if(array1[i+1] != array2[i])
        {
            return false;
        }
    }
    return true;
}