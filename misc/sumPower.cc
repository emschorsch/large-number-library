#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;
int main(){
  int max,base;
  cout<<"enter what base: ";
  cin>>base;
  cout<<"enter "<<base<<" to what power: ";
  cin>>max;
  
  int sum[max*base+4];
  //int prod[200];//maybe use array of longs
  long size=0;//applies to sum
  int* num1 = new int[max*base+4];
  int* num2 = new int[max*base+4];
  num1[0]=1;//accumulator
  long size1=1;

  long size2 = 0;
  int temp = base;
  while(temp > 0){
	  num2[size2] = temp%10;
	  temp = temp/10;
	  size2++;
  }

  for(int i=0;i<max*base+4;i++){
	  sum[i]=0;
  }

  
 if(max == 0){
    goto sum;
 }
 else{
    if(max % 2 == 0) {
      max /= 2;
      goto square;
    } 
    else {
      max -= 1;
      goto mult;
   }
 }

   
   square://squares num2
    for(int i=0;i<size2;i++){
	for(int j=0;j<size2;j++){
		sum[i+j]+=num2[j]*num2[i];//ones digits are in column 0
	}
    }
    //cout<<sum[0]<<endl;
    size=size2+size2-1;
    for(int i=0;i<size;i++){
	  sum[i+1]+=sum[i]/10;
	  num2[i]=sum[i]%10;
	  sum[i]=0;

    }
    if(sum[size]!=0){
      num2[size]=sum[size];
      sum[size]=0;
      size2=size+1;
    }else{
	  size2=size;
    }
  
 if(max == 0){
    goto sum;
 }
 else{
    if(max % 2 == 0) {
      max /= 2;
      goto square;
    } 
    else {
      max -= 1;
      goto mult;
   }
 }

  mult://if a=base and b=exp then multiplies accumulater so that it ends up
 //equal to (a^b)/(a^2^c) such that 2^c < b   for some integer c
   for(int i=0;i<size2;i++){
	for(int j=0;j<size1;j++){
		sum[i+j]+=num1[j]*num2[i];//ones digits are in column 0
	}
   }

   size=size1+size2-1;
   for(int i=0;i<size;i++){
	  sum[i+1]+=sum[i]/10;
	  num1[i]=sum[i]%10;
	  sum[i]=0;

    }
    if(sum[size]!=0){
      num1[size]=sum[size];
      sum[size]=0;
      size1=size+1;
    }else{
	  size1=size;
    }

     if(max == 0){
    goto sum;
 }
 else{
    if(max % 2 == 0) {
      max /= 2;
      goto square;
    } 
    else {
      max -= 1;
      goto mult;
   }
 }


  sum:
  long tsum=0;
  for(int i=size1-1;i>=0;i--)
	  tsum+=num1[i];
  cout<<tsum<<endl;
  cout<<"elapsed time: "<<(double)clock()/CLOCKS_PER_SEC<<endl;
  delete [] num1;
  delete [] num2;
  return 0;
}
