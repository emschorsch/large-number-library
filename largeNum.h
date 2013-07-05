#ifndef LARGENUM_H_
#define LARGENUM_H_

/*
 * Written by Emanuel Schorsch
 * The header file for a class which can handle large numbers.
 * Basic mathematical operations such as summation and multiplication are 
 * implemented.
 */
class LargeNum
{
   public:
     LargeNum();
     ~LargeNum();
     int* sum(int size1,int size2,int* num1,int* num2, int& size);
     int* toArray(int num,int& size);
     int* multiply(int size1,int size2, int* num1, int* num2, int& size);
};
#endif //largeNum_h_
