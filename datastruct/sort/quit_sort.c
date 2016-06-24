#include"FXsort.h"

/*int quick_sort(int num[],int left,int right){

	int mid = (left+right)/2;
	printf("num[mid] is %d\n",num[mid]);
	int r = right;
	int l = left;
	for(;l < r;l++,r--){
	
		if(num[l] > num[mid]&& l<mid){
		
			FXsweep(num+l,num+mid);
			mid = l;
		}else if(l>=mid){
		
			l--;
		}
		if(num[r] < num[mid]&& r >mid){
		
			FXsweep(&num[r],&num[mid]);
			mid = r;
		}else if(r <= mid){
		
			r++;
		}
	}//end for
	printf("mid is %d\n",mid);

	if((mid-left) >= 8){
		quick_sort(num,left,mid-1);
    }else{
        bubble_sort(num+left,mid-left);
    }
	if((right-mid) >= 8){
		quick_sort(num,mid+1,right);
    }else{
        bubble_sort(num+mid+1, right-mid);
    }

	return 0;


}*/

int quick_sort(int data[],int left,int right){
    int p=(left+right)/2;
    int pivot=data[p];
    int i=left,j=right;
    while(i<j){
        for(;!(i>=p||data[i]>pivot);i++);
        if(i<p){
            data[p]=data[i];
            p=i;
        }
        for(;!(j<=p||data[j]<pivot);j--);
        if(j>p){
            data[p]=data[j];
            p=j;
        }
    }
    data[p]=pivot;
    if(p-left>8){
        quick_sort(data,left,p-1);
    }else{
        bubble_sort(data+left, p-left);
    }
    if(right-p>8){
        quick_sort(data,p+1,right);
    }else{
        bubble_sort(data+p+1, right-p);
    }
    return 0;
}
