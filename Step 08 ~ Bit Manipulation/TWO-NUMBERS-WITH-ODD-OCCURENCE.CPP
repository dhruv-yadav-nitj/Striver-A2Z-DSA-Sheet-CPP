#include <bits/stdc++.h>
using namespace std ;

// approach #1 : using map
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N){
        // code here
        vector<long long> ans ;
        unordered_map<long long, long long> mp ;
        for(long long i= 0; i < N ; i++){

            mp[Arr[i]]++ ;
        }

        for(auto it : mp){
            if((it.second&1)==1){
                ans.push_back(it.first) ;
            }
        }
        sort(ans.begin() , ans.end(), greater<long long>()) ;
        return ans;

    }
};

// approach #2 : using bitwise operation
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N){
        // code here

        long long int xori= 0 ;
        for(long long i =0; i < N ; i++){
            xori = (xori ^ Arr[i]) ;
        }

        long long set_bit = (xori & (~(xori) + 1)) ;
        long long first =0, second =0 ;
        for(long long i =0 ;i < N ;i++){
            if(Arr[i]&set_bit){
                first = first ^ Arr[i] ;
            }
            else{
                second = second ^ Arr[i] ;
            }
        }

        vector<long long> ans ; 
        ans.push_back(first) ; ans.push_back(second) ;
        sort(ans.begin() , ans.end() , greater<int>()) ;return ans ;

    }
};

// very well explained : source gfg : https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/

/* Let the two odd occurring numbers be x and y. We use bitwise XOR to get x and y. We try to make 2 groups such that x and y go to different groups. E.g. [a, a, b, b, x], . Then the problem will become “Find ‘one’ number with odd occurrence in an unsorted array”, which becomes a simple problem and will be solved using XOR. Below are steps to group x and y differently.

1.    The first step is to do XOR of all elements present in array. XOR of all elements gives us XOR of x and y because of the following properties of XOR operation. 
        1) XOR of any number n with itself gives us 0, i.e., n ^ n = 0 
        2) XOR of any number n with 0 gives us n, i.e., n ^ 0 = n 
        3) XOR is cumulative and associative.

        So we have XOR of x and y after the first step, in decimal form. E.g. 5 ^ 6 returns 3, which is computed in bit form as 101 ^ 110 = 011. Let the ‘value’ of XOR be xor2. Every Set bit** in xor2 indicates that ‘the corresponding bits in x and y have values different from each other’ (XOR property- ‘1 when bits are different’). 

** ( Set-bits are 1’s in binary form. E.g. 101 has 2 set bits(1’s), at 0th index and at 2nd index. )

For example, if x = 6 (0110) and y = 15 (1111), then xor2 will be (1001), the two set bits in xor2 indicate that the corresponding bits in x and y are different, at 0th index and at 3rd index both. 

2.    In the second step, we pick a set bit of xor2. Idea is to use the fact that xor2 is ‘1’ in indexes where bits of x and y are different. So we separate x and y to different groups, along with rest of the numbers of list, based on whether the number has same set-bit or not.  

     We choose the rightmost set bit of xor2 as it is easy to get rightmost set bit of a number (bit magic). If we bitwise AND a number with its negative counterpart, we get rightmost set bit. (just an observation based property, do remember). So, (xor2) & (-xor2) will give us right set bit. Find (-number) by 2’s complement, that is ((1’s complement) +1 ). It can also be written as (~number)+1. 

   a)    Example of 2’s complement :

 7 is 00111(any no. of preceding zeroes). 1’s complement is obtained by flipping bits , 11000. Then add 1, so 2’s complement of 7 is 11001. Since first bit is 1, its a negative no. 

 (-1)*16 + 1*8 +1*1  =  -7

   b)    Example of (number) & (-number) = right set bit :

 Continuing example of 7,  7 is 00111 and -7 is 11001 , 7 & -7 is  00001. So, rightmost set bit of 7 is 1.

 Another example with 12 & -12:

 12 is 01100 ** and -12 is calculated by flipping digits and adding 1. So, 10011 and adding 1 gives 10100.  12 & -12,  01100 & 10100  gives  00100 as set bit, that is returned as 4 in decimal system, also referred as Set-bit Number here.

 ** (since number is 32 bit, there are 28 0’s left of ‘left set-bit’, but taking only a few is okay. Positive numbers have leftmost bit 0 and negative have 1 )

3.    In third step, we separate x and y in different groups : We now know that for selected set bit index, x and y have different corresponding bits. If we AND all numbers in list with set bit, some will give 0 and others will give 1. We will put all numbers giving zeroes in one group and ones in another. x and y will fall in different groups. 

Explained with example:-

E.g. arr = [4, 2, 4, 10, 2, 3, 3, 12] ,  

Step 1) XOR of all in arr will cancel all repeating nos. 10 ^12 will be ans. 1010 ^ 1100 will be 0110 that is xor=6. 

Step 2) Set bit is 10 from 0110 from visualization. (number) & (-number) is also a quick way to find right set bit.

            xor & (-xor) can be coded directly. 6 is 0110 and finding -6 by flipping digits and adding 1, 1001 +1 = 1010.

            So 6 AND -6 is essentially 0110 & 1010, that is 0010 i.e. 2 – Set-bit Number.

Step 3) AND of all in list with 2 (Set bit no.) will give us numbers that give either 1 or 0, and we make groups.

            [4, 4, 12] and [2, 10, 2, 3, 3], giving 0 and 1 respectively on AND with Set-bit number.

Step 4) XOR of 1st group will give us x=12, x ^ y is known from 1st step i.e. 6. x ^(x ^y) will give us y. 12 ^6 is 10.

           x=12, y=10

    This step works because of the same properties of XOR. All the occurrences of a number will go in same set. XOR of all occurrences of a number which occur even number of times will result in 0 in its set. And the xor of a set will be one of the odd occurring elements.  */