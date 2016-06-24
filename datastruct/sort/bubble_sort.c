

int bubble_sort(int num[],int size){

	for(int i = 0;i <= size-1;i++){
	
		for(int j = 0;j < size-(i+1);j++){
		
			if(num[j] > num[j+1]){
			
				num[j] = num[j]^num[j+1];
				num[j+1] = num[j]^num[j+1];
				num[j] = num[j]^num[j+1];
			}
		}
	}
	return 0;
}
