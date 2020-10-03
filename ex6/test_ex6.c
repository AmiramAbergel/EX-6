/*************************************************
*  test_ex6.c
*  ----------
*  A program containing testing functions
*  for Problems 1 and 2 in Ex 6.
*************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "/share/ex_data/ex6/bigInt.h"
#include "/share/ex_data/ex6/sortedBigIntList.h"
#include "/share/ex_data/ex6/virtualHeap.h"
 // #include "/share/ex_data/ex6/sortedBigIntList.h"

/*** internal function ***/
/*** print an array of chars ***/
void printBuffer(const char* buffer, int len);

/********************************/
/**    MAIN TESTING FUNCTION   **/
/********************************/

int main() {

#ifdef TEST_1_3
#define NUM_DIGITS
#define INT_STR
#endif

#ifdef TEST_1_4
#define NUM_DIGITS
#define INT_STR
#define BIG_INT1
#endif


#ifdef TEST_1_5
#define NUM_DIGITS
#define INT_STR
#define BIG_INT1
#endif

#ifdef TEST_1_6
#define NUM_DIGITS
#define INT_STR
#define BIG_INT1
#endif

#ifdef TEST_1_7
#define INT_STR
#define BIG_INT1
#define BIG_INT2
#endif

#ifdef TEST_2_2
#define LIST
#endif

#ifdef TEST_2_4
#define BIG_INT1
#define LIST
#endif


#ifdef TEST_2_5
#define BIG_INT1
#define LIST
#endif

#ifdef BIG_INT1
   BigInt bigInt1;
#endif
#ifdef BIG_INT2
   BigInt bigInt2;
#endif
#ifdef INT_STR
   char* intStr;
#endif
#ifdef NUM_DIGITS
   int numDigits = 0;
#endif
#ifdef LIST
   SortedBigIntList list;
#endif
   
#ifdef TEST_1_1
   printf("Tests for computeExponent() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("computeExponent(%15s) = %3d\n", "\"000\"",        computeExponent("000"));
   printf("computeExponent(%15s) = %3d\n", "\"009\"",        computeExponent("009"));
   printf("computeExponent(%15s) = %3d\n", "\"123000\"",     computeExponent("123000"));
   printf("computeExponent(%15s) = %3d\n", "\"001203000\"",  computeExponent("001203000"));
   printf("computeExponent(%15s) = %3d\n", "\"-12\"",        computeExponent("-12"));
   printf("computeExponent(%15s) = %3d\n", "\"12 34\"",      computeExponent("12 34"));
   printf("computeExponent(%15s) = %3d\n", "\"\"",           computeExponent(""));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_2
   printf("Tests for fullMantissaLength() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("fullMantissaLength(%15s) = %3d\n", "\"000\"",        fullMantissaLength("000"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"009\"",        fullMantissaLength("009"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"123000\"",     fullMantissaLength("123000"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"001203000\"",  fullMantissaLength("001203000"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"-12\"",        fullMantissaLength("-12"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"12 34\"",      fullMantissaLength("12 34"));
   printf("fullMantissaLength(%15s) = %3d\n", "\"\"",           fullMantissaLength(""));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_3
   printf("Tests for copyMantissa() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   int res; 
   char buffer1[15] = {0};
   char *bufferInit = "ABCDEFGHIJKLMN";
   
   printf("Copying different mantissas into a buffer, starting from the 2nd entry.\n");
   strcpy(buffer1, bufferInit);
   printf("Initializing buffer conent to: ");
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "9876543210";
   numDigits = 1;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));
   
   intStr = "000987654321000";
   numDigits = 3;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));
   
   numDigits = 5;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   numDigits = 9;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   numDigits = 10;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));
   
   numDigits = 15;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   strcpy(buffer1, bufferInit);
   printf("Reinitializing buffer conent to: ");
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "00000000000000000000";
   numDigits = 3;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "000900000001000";
   numDigits = 3;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   strcpy(buffer1, bufferInit);
   printf("Reinitializing buffer conent to: ");
   printBuffer(buffer1, sizeof(buffer1));

   printf("Testing invalid inputs:\n");

   numDigits = 1;
   intStr = "-12";
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "12 34";
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "0-12";
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   intStr = "";
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));


   intStr = "1234";
   numDigits = 0;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   numDigits = -3;
   res = copyMantissa(intStr, buffer1+1, numDigits);
   printf("copyMantissa(\"%s\", buffer+1, %2d) returns %2d and updates buffer content to:  ", intStr, numDigits, res);
   printBuffer(buffer1, sizeof(buffer1));

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_4
   printf("Tests for newBigInt() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

   printf("\n!!! Important note: the BigInt_st structure takes up %ld bytes on the server!!!\n\n",sizeof(BigInt_st));

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="-000987654321000";
   numDigits = 1;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   numDigits = 0;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   numDigits = -10;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="+000987654321000";
   numDigits = 20;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="000900000001000";
   numDigits = 3;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack. [MORE OPTIMAL IMPLEMENTATIONS ALLOCATE 2 LESS BYTES FOR THE MANTISSA STRING]\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="-0000000000000";
   numDigits = 3;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   setMaxBytes(3);
   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   printf("Checking what happens when there is no space in heap\n");
   intStr="0";
   numDigits = 3;
   bigInt1 = newBigInt(intStr, numDigits);
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   setMaxBytes(sizeof(BigInt_st));
   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   printf("Checking what happens when there is space in heap for struct or the mantissa array but not for both\n");
   intStr="0";
   numDigits = 3;
   bigInt1 = newBigInt(intStr, numDigits);
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Testing invalid inputs:\n");

   setMaxBytes(1);
   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="--0";
   numDigits = 3;
   bigInt1 = newBigInt(intStr, numDigits);
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="+1234.";
   numDigits = 1;
   bigInt1 = newBigInt(intStr, numDigits);
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_5
   printf("Tests for freeBigInt() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

   printf("\n!!! Important note: the BigInt_st structure takes up %ld bytes on the server!!!\n\n",sizeof(BigInt_st));

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   intStr="-000987654321000";
   numDigits = 1;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeBigInt(bigInt1);
   printf("After freeing the BigInt object there are %2d bytes allocated in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   numDigits = 0;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeBigInt(bigInt1);
   printf("After freeing the BigInt object there are %2d bytes allocated in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("Resetting virtual heap with %d allocated blocks and maximum capacity of %d bytes.\n", getNumAllocatedBlocks(),getMaxBytes());
   numDigits = -10;
   printf("newBigInt(\"%s\", %2d) results in ",intStr, numDigits);
   bigInt1 = newBigInt(intStr, numDigits);
   if(bigInt1) printf("new BigInt object with sign='%c', exp=%2d, mantissa=\"%s\". ", bigInt1->sign, bigInt1->exp, bigInt1->mantissa);
   else        printf("NULL pointer. ");
   printf("Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeBigInt(bigInt1);
   printf("After freeing the BigInt object there are %2d bytes allocated in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_6
   printf("Tests for printBigInt() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   intStr="0000009876543210";
   printf("Creating BigInt object from string \"%s\" with full mantissa.\n",intStr);
   bigInt1 = newBigInt(intStr,0);

   numDigits = 1;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = 3;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = 12;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = 0;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   freeBigInt(bigInt1);

   intStr="-00000300000";
   printf("Creating BigInt object from string \"%s\" with full mantissa.\n",intStr);
   bigInt1 = newBigInt(intStr,0);

   numDigits = 1;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = 15;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = -15;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   freeBigInt(bigInt1);

   intStr="-0000000000";
   printf("Creating BigInt object from string \"%s\" with full mantissa.\n",intStr);
   bigInt1 = newBigInt(intStr,0);

   numDigits = 3;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   numDigits = 0;
   printf("printBigInt(bigInt, %2d) prints \"",numDigits);
   printBigInt(bigInt1, numDigits);
   printf("\"\n");

   freeBigInt(bigInt1);
   printf("Making sure all allocations are clean before leaving: Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif
   
#ifdef TEST_1_7
   printf("Tests for compareBigInt() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   char* intStr2;

   intStr ="9876543210000";
   intStr2="9876540000000";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr,  compareBigInt(bigInt2, bigInt1));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr2, compareBigInt(bigInt2, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr,  compareBigInt(bigInt1, bigInt1));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);

   intStr ="-9876543210000";
   intStr2="9876540000000";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr,  compareBigInt(bigInt2, bigInt1));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr2, compareBigInt(bigInt2, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr,  compareBigInt(bigInt1, bigInt1));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);

   intStr ="-9876543210000";
   intStr2= "9876543210000";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr,  compareBigInt(bigInt2, bigInt1));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr2, compareBigInt(bigInt2, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr,  compareBigInt(bigInt1, bigInt1));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);

   intStr ="-9876543210";
   intStr2="-987654321";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr,  compareBigInt(bigInt2, bigInt1));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr2, compareBigInt(bigInt2, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr,  compareBigInt(bigInt1, bigInt1));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);

   intStr ="-9876543210";
   intStr2="-9876543211";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr,  compareBigInt(bigInt2, bigInt1));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr2, intStr2, compareBigInt(bigInt2, bigInt2));
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr,  compareBigInt(bigInt1, bigInt1));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);

   intStr ="9876543210";
   intStr2="+9876543210";
   bigInt1 = newBigInt(intStr,0);
   bigInt2 = newBigInt(intStr2,0);
   printf("compareBigInt(bigInt(\"%s\") , bigInt(\"%s\")) returns %2d\n", intStr,  intStr2, compareBigInt(bigInt1, bigInt2));
   freeBigInt(bigInt1);
   freeBigInt(bigInt2);


   printf("Making sure all allocations are clean before leaving: Allocated %2d bytes in %2d blocks in virtual stack.\n",getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_2_1
   printf("No separate tests for Problem 2.1.\n");
#endif

#ifdef TEST_2_2
   printf("Tests for newSortedBigIntList() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("newSortedBigIntList(INC) creates ");
   list = newSortedBigIntList(INC);
   if(list) printf("new SortedBigIntList object that takes up %d bytes.\n", getNumAllocatedBytes());
   else     printf("no new object.\n");
   freeAll();

   printf("newSortedBigIntList(DEC) creates ");
   list = newSortedBigIntList(INC);
   if(list) printf("new SortedBigIntList object that takes up %d bytes.\n", getNumAllocatedBytes());
   else     printf("no new object.\n");
   freeAll();
   
   printf("newSortedBigIntList(131415) creates ");
   list = newSortedBigIntList(131415);
   if(list) printf("new SortedBigIntList object that takes up %d bytes.\n", getNumAllocatedBytes());
   else     printf("no new object.\n");
   freeAll();

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif


#ifdef TEST_2_3
   printf("No separate tests for addBigIntToSortedList (). Test after you implement printSortedBigIntList().\n");
#endif

#ifdef TEST_2_4
   printf("Tests for addBigIntToSortedList() and printSortedBigIntList() functions:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   char* intStrings[] = {"3400","340","3401","340","3400","-1000000000000000000000000000001"};
   int types[] = {INC, DEC};
   char* typeString;
   int i, t;

   for(t=0; t<sizeof(types)/sizeof(types[0]); t++) {
      freeAll();
      typeString=(types[t]==INC)?"INC":"DEC";
      list = newSortedBigIntList(types[t]);
      if(!list) {
         printf("Cannot allocate new sorted big int list with type %s\n",typeString);
         continue;
      }
      printf("Printing empty list of type %s, which takes %3d bytes in %2d blocks on the heap:\n",typeString, getNumAllocatedBytes(), getNumAllocatedBlocks());
      printSortedBigIntList(list,0);
      for(i=0; i<sizeof(intStrings)/sizeof(intStrings[0]); i++) { 
         bigInt1 = newBigInt(intStrings[i],0);
         if(!addBigIntToSortedList(list,bigInt1)) {
            printf("Cannot add number \"%s\" to list\n",intStrings[i]);
         } else {
            printf("Printing list after adding number \"%s\" to list, which now takes %3d bytes in %2d blocks on the heap:\n",intStrings[i], getNumAllocatedBytes(), getNumAllocatedBlocks());
            printSortedBigIntList(list,0);
         }
      } // end of for(i)
   } // end of for(type)
   printf("Printing list with precision=1:\n");
   printSortedBigIntList(list,1);
   printf("Printing list with precision=2:\n");
   printSortedBigIntList(list,2);
   printf("Printing list with precision=3:\n");
   printSortedBigIntList(list,3);
   freeAll();

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
#endif

#ifdef TEST_2_5
   printf("Tests for freeSortedBigIntList() function:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   char* intStrings2[] = {"3400","340","3401","340","3400","-1000000000000000000000000000001"};
   int j;
   list = newSortedBigIntList(INC);
   if(!list) {
      printf("Cannot allocate new sorted big int list with type INC\n");
      return 1;
   }
   printf("Empty list of type INC takes %3d bytes in %2d blocks on the heap.\n", getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeSortedBigIntList(list);
   printf("After calling freeSortedBigIntList() there are %3d bytes in %2d blocks allocated on the heap.\n", getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();
   list = newSortedBigIntList(INC);
   if(!list) {
      printf("Cannot allocate new sorted big int list with type INC\n");
      return 1;
   }
   printf("Recreating empty list of type INC with %3d bytes in %2d blocks on the heap.\n", getNumAllocatedBytes(), getNumAllocatedBlocks());

   for(j=0; j<sizeof(intStrings2)/sizeof(intStrings2[0]); j++) {
      bigInt1 = newBigInt(intStrings2[j],0);
      if(!addBigIntToSortedList(list,bigInt1)) {
         printf("Cannot add number \"%s\" to list\n",intStrings2[j]);
      } else {
         printf("After adding number \"%s\" to list, it now takes %3d bytes in %2d blocks on the heap.\n",intStrings2[j], getNumAllocatedBytes(), getNumAllocatedBlocks());
      }
   } // end of for(j)
   freeSortedBigIntList(list);
   printf("After calling freeSortedBigIntList() there are %3d bytes in %2d blocks allocated on the heap.\n", getNumAllocatedBytes(), getNumAllocatedBlocks());
   freeAll();
#endif

   return 0;
}

void printChar(char c) {
   if(isprint(c))  printf("'%c'"  ,c);
   else            printf("'\\%d'",c);
}

void printBuffer(const char* buffer, int len) {
   int i;
   printf("{");
   if(len>0) printChar(buffer[0]);
   for (i=1; i<len; i++) {
      printf(", ");
      printChar(buffer[i]);
   }
   printf("}\n");
}
