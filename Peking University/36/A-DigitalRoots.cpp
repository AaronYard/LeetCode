/*****
A - Digital Roots

题目描述
Time Limit: 1000 ms
Memory Limit: 64 mb
The digital root of a positive integer is found by summing the digits of the integer. If the resulting value is a single digit then that digit is the digital root. If the resulting value contains two or more digits, those digits are summed and the process is repeated. This is continued as long as necessary to obtain a single digit.

For example, consider the positive integer 24. Adding the 2 and the 4 yields a value of 6. Since 6 is a single digit, 6 is the digital root of 24. Now consider the positive integer 39. Adding the 3 and the 9 yields 12. Since 12 is not a single digit, the process must be repeated. Adding the 1 and the 2 yeilds 3, a single digit and also the digital root of 39.

输入输出格式
输入描述:
The input file will contain a list of positive integers, one per line. 
The end of the input will be indicated by an integer value of zero.
输出描述:
For each integer in the input, output its digital root on a separate line of the output.

输入输出样例

输入样例:
24
39
0

输出样例:
6
3
*****/

#include <math>
#include <iostream>
using namespace std;

long int diedai(long int IntegerSumA){
	long int temp = IntegerSumA;
	long int IntegerSumB = 0;
	if(temp != 0){
		IntegerSumB += temp - temp%10;
		temp = temp%10;
	}
	if(IntegerSumA%IntegerSumB)
	{
		return IntegerSumB;
	}else{
		diedai(IntegerSumB);
	}
}

int main(){
	long int[] IntegerList=[];
	
	cout>>"Please input a list of positive intergers,the end must input zero.">>endl;
	when(getline() != 0){
		IntegerList[totalInteger] = getline();
	}
	cout<<"This is your Output list"<<endl;
	for(long int i = 0;i < IntegerList.count;i++)
	{
		IntegerList[i] = diedai(IntegerList[i])
			cout<<IntegerList[i]<<endl;
	}
	return 0;
}