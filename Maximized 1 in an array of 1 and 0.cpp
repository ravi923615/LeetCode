class Solution{
public:
	/* Q: Find zeroes to be flipped so that number of consecutive 1's is maximized.
	A better solution is to use auxiliary space to solve the problem in O(n)
	time.
	For all positions of 0's calculate left[] and right[] which defines the number of
	consecutive 1's to left of i and right of i respectively.
	For example, for arr[] = [1,1,0.1,1,0,0,1,1,1] and m=1, left[2] = 2 and 
	right[2] = , left[5] = 2 and right[5] = 0, left[6] = 0 and right[6] = 3

	And efficient solution can solve the problem in O(n) time and O(1) space 
	By using Sliding Windows for the given array.

	Let us use the window covering fron index wL to indec wR. Let the number of zeros
	inside the window be zeroCount.
	We maintain the window with at most m zeros inside.

	The main steps are:
		-- While zeroCount is no more than m expand the window to right(wR++)
		and update the count zeroCount.
		-- While zeroCount exceeds m, shrink the window from left (wL++), updated
		zeroCount.
		-- Update the widest window along the way. The positions of output zeros are
		inside the best window.
	*/

	void findZeros(vector<int> &arr,int sze,int m){
	// Left and right indexes of current window.
		int wL = 0, wR = 0;
	//Left index and size of the widest window.
		int bestL = 0, bestWindow = 0
	//Count of zeroes in current window.
		int zeroCount = 0;
		while(wR<n){
			//If zero count of current winfow is less than m,
			// widen the window from right
			if(zeroCount<m){
				if(arr[wR]==0)
					zeroCount++;
				wR++;
			}

			//if zero count of current window is more than m,
			// reduce the window from left
			if(zeroCount>m){
				if(arr[wL]==0)
					zeroCount--;
				wL++;
			}

			//Update widest window if this window size is more
			if(wR-wL>bestWindow){
				bestWindow = wR-wL;
				bestL = wL;
			}
		}

		//Print position of zeros in the widest window
		for (int i = 0; i < bestWindow; ++i)
		{
			if(arr[bestL+i]==0)
				cout<<bestL+i<<" ";
		}
		
	}
}