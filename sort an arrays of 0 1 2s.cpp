class Solution{
public:
	/* Q: Given array A[] consiting of 0 1 and 2 sort it.
	Example
	input = {0,1,1,0,1,2,1,0,0,0,1}
	output = {0,0,0,0,0,1,1,1,1,1,2,2}
	*/
	// Dutch national Flag problem.
	void sort012(vector<int> &arr){
		int size = arr.size();
		int lo = 0;
		int high = size-1;
		int mid = 0;
		while(mid<=high){
			switch(a[mid]){
				case 0:
					swap(&a[lo++],&a[mid++]);
					break;
				case 1:
					mid++;
					break;
				case 2:
					swap(&a[mid],&a[high--]);
					break;
			}
		}
	}
}