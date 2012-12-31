#ifndef LARGENUM2_H_
#define LARGENUM2_H_

/*
 * Written by Emanuel Schorsch
 * The header file for a class which can handle large numbers.
 * Basic mathematical operations such as summation and multiplication are 
 * implemented.
 */
class LargeNum2
{  	
   public:
     LargeNum2();
     LargeNum2( int initNum );
     LargeNum2( int* num1, int size1 );
     ~LargeNum2();
     void print();
     void set( int value );
     LargeNum2 sum(LargeNum2 number1, LargeNum2 number2);     
     int* multiply(int size1, int size2, int* num1, int* num2, int& size);

   private:
     int* toArray(int num, int& size);
     int size;
     int* num;
};
#endif //largeNum2_h_
