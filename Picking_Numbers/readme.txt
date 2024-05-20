The main idea behind this problem was first to sort the given array 
then we can calculate the subarray of the two different numbers
thing that we have to keep in mind to pass all the test cases
1. that both the number should be 1 digit apart 
2. if they are not one digit apart then directly breaking the loop is not good we should check the count
of both the array and see if one of the array alone is greater than max then swap int
3. if there is only one number present then we will not get num 2 so in that case the max is the
no of times that one element is present and we have to break.