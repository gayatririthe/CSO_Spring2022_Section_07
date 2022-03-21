/* 
 * <Gayatri Rithe>
 * gr2287
 * March 21 2022
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //uses Demogran's Law
  int first = ~(x&y);
  int second = ~(~x&~y);
  return first & second;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int result = 1 << 31; //left shift
  return result;
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  int first =  !(x + 1); //only becomes 1 if x is -1
  int second = ~((x + 1) ^ x); //gives us 0s if its TMax, sometimes -1
  int result = !(first + second); //statemnet only returns 1 if its TMax
  return result;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int result;
  //creates 0xAAAAAAAA by shifting and adding to itself
  int ran = (0xAA << 8);
  ran += 0xAA;
  ran = (ran << 16) + ran;

    
  result = (x & ran) ^ ran; //is only 0 when all odd bits are 1 and is comparing against itself
  result = !result; //gives us logical not of result

  return result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //uses two's complement formula for negation
  int result = ~x + 1;
  return result;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int ran = 1 << 31;
  int first = ~0x30; //the lower bound
  int second = ~(ran | 0x39); //the upper bound
  int result;

  first = ran & (first+1+x) >> 31; //gets the sign once x is added to lower bound
  second = ran & (second+x) >> 31; //gets the sign once x is added to upper bound

  result = !(first | second); //checks to see if either first or second is negative
  return result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int ran = (!x + ~0x00); //subtracts 1 from 0x00000000 or 0xffffffff depending on x's value
  int result = (ran & y) | (~ran & z); //masks y or z depending on ran's value
  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

  int first = (1 << 31) & x; //get x's sign bit
  int second = (1 << 31) & y; //get y's sign bit
  int sign = ((~x + y + 1) >> 31) & 1; //difference of x and y's sign bit
  int temp = ((first ^ second) >> 31) & 1; //gets sign bit of first and second xor

  return (!sign & !temp) | (temp & (first >> 31)); //returns 1 if x<= y
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int ran = (~x) & (~(~x+1)); //complement and inverse and complement
  //gets rans sign bit and returns it
  int result = ran >> 31;
  result = result & 1;
  return result;  
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int b0, b1, b2, b4, b8, b16;
    int ran = x >> 31; //gets the sign bit
    x = (ran & ~x) | (~ran & x);
    
    //checks first 16 bits for any nonzero bits, shifts if there are
    b16 = !!(x >> 16) << 4;
    x = x >> b16;
    
    //checks the next 8 bits for any nonzero bits, shifts if there are
    b8 = !!(x >> 8) << 3;
    x = x >> b8;
    
    //continues
    b4 = !!(x >> 4) << 2;
    x = x >> b4;
    
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    
    b1 = !!(x >> 1);
    x = x >> b1;
    
    b0 = x;
    
    return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    int exp = (uf >> 23) & 255; //gets bits
    int frat;
    
    //if exp is 0 denormalizes the number
    if(exp == 0)
        return (uf & (1 << 31)) | (uf << 1);
    //checks if it's NaN or infinity
    if(exp == 255)
        return uf;
    
    //adds to exponent and sees if it overflows
    exp = exp + 1;
    if(exp == 255)
        return (uf & (1 << 31)) | 0x7F800000;
   //if not builds the frac and returns bit-level equivalent of 2*f
    else
    {
        frat = uf & 0x7FFFFF;
        return (uf & (1 << 31)) | (frat | exp << 23);
    }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    int exp = 158;
    int pos = x & (1 << 31); //sign bit
    int frat;
    
    //get two's complement if necessary
    if (pos)
        x = ~x + 1;
    //returns 0 if x is 0
    if(!x)
        return 0;
    //checks if x is the min two's complement integers
    if (x == (1 <<31))
        return 0xCF000000;
   
    //sees where 1 is for the first time
    while(!(x & (1 << 31)))
    {
        exp--;
        x = x << 1;
    }
    
    //creates the frat
    frat = (x & ~(1<<31)) >> 8;
    if(((x & 127) > 0 || frat & 1) && (x & 128))
        frat++;
    
    return (exp << 23) + frat + pos;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
    //gets exponent value
    int exp = (uf >> 23) & 0xFF;
    int ran = exp - 127;
    int frat = uf & 0x7FFFFF; //gets bits for fraction
    
    //checks if ran is negative
    if (ran < 0)
        return 0;
    //checks if it's at max value or exponent is too big
    if (exp == 0x7F800000 || ran > 30)
        return 0x80000000u;
    
    //updates frat
    frat = frat | 0x800000;
    
    //sees if left shift or right shift is necessary
    if (ran >= 23)
        frat = frat << (ran-23);
    else
        frat = frat >> (23 - ran);
    
    //if two's complement is neg returns the pos value
    if(uf & (1 << 31))
        return ~frat + 1;
    
    //otherwise returns frat
    return frat;

}
