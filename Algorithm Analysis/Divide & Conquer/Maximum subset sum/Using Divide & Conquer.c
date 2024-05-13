#include <stdio.h>
#include <math.h>

struct SubArrayInfo{
    int LowIndex;
    int HighIndex;
    int Sum;
};

typedef struct SubArrayInfo SubArrayInfo;

/**Function Header Declaration*/
SubArrayInfo Find_Maximum_SubArray(int [],int, int);
SubArrayInfo Find_Max_Crossing_SubArray(int [], int, int,int );
void PrintSubArray_Sum(int [],int,int);

int main(){
    int Test[] = {-2,1,-3,4,-1,2,1,-5,4};
    
    int Test_Length = sizeof(Test)/sizeof(Test[0]);
    int Low = 0;
    int High = Test_Length - 1;
    int Mid = (Low + High)/2;
    
    
    SubArrayInfo Ans = Find_Maximum_SubArray(Test, Low, High);
    PrintSubArray_Sum(Test,Ans.LowIndex,Ans.HighIndex);
    
    return 0;
}

SubArrayInfo Find_Maximum_SubArray(int A[],int low,int high){
    if (high == low){
        SubArrayInfo S;
        S.LowIndex = low;
        S.HighIndex = high;
        S.Sum = A[low];
        
        return S;
    } else {
        SubArrayInfo LeftArray;
        SubArrayInfo RightArray;
        SubArrayInfo CrossArray;
        
        int mid = (low + high)/2;
        
        LeftArray = Find_Maximum_SubArray(A,low,mid);
        RightArray = Find_Maximum_SubArray(A,mid+1,high);
        CrossArray = Find_Max_Crossing_SubArray(A,low,mid,high);
        
        if(LeftArray.Sum >= RightArray.Sum && LeftArray.Sum >= CrossArray.Sum){
            return LeftArray;
        } else if (RightArray.Sum >= LeftArray.Sum && RightArray.Sum >= CrossArray.Sum){
            return RightArray;
        } else {
            return CrossArray;
        }
    }
}

SubArrayInfo Find_Max_Crossing_SubArray(int A[],int low,int mid,int high){
    SubArrayInfo S;
    
    double leftSum = -INFINITY;
    int sum = 0;
    int maxLeft;
    for(int i = mid;i>=low;i--){
        sum = sum + A[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    double rightSum = -INFINITY;
    int maxRight;
    sum = 0;
    for(int j = mid+1;j<=high;j++){
        sum = sum + A[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    
    S.LowIndex = maxLeft;
    S.HighIndex = maxRight;
    S.Sum = leftSum + rightSum;
    
    return S;
}

void PrintSubArray_Sum(int A[],int l,int h){
    printf("The Maximum Sub Array :{");
    int Sum = 0;
    for(int i = l;i<=h;i++){
        printf("%d ,",A[i]);
        Sum += A[i];
    }
    printf("}\n");
    printf("Maximum Sum :%d\n",Sum);
}
