//#define NDEBUG  实际使用时需在引用assert header前,定义NDEBUG禁用
#include <stdio.h>
#include <assert.h>

/**
 * 折半查找,包含测试代码
 * 
*/
#define LEN 6
int arr[LEN] = {1, 8, 4, 5, 6, 7};

/**/
int is_sort(void){
    int i, sort = 1;
    for(i = 0; i < LEN; i++){
        sort = sort && arr[i - 1] <= arr[i];
    }
    return sort;
}

/**/
int must_be(int start, int end, int num){
    int i;
    for(i = 0; i < LEN; i++)
    {
        if (i>=start && i<=end)
            continue;
        
        if (arr[i]==num) {
            return 0;
        }
    }
    return 1;
}


int halfsearch(int num){
    int mid, start = 0, end = LEN - 1;
    assert(is_sort());  //断言assertion测试数组是否排好序、无越界, precodition
    
    while(start <= end){
        assert(must_be(start, end, num));  //maitenance,确保拍好序
        mid = (start + end) / 2;
        if (arr[mid] < num){
            start = mid + 1;
        }
        else if(arr[mid > num]){
            end = mid - 1;
        }
        else{
            return mid;
        }
    }
    assert(must_be(start, end, num));  //确保在num不包含时,一定反馈-1
    return -1;
}