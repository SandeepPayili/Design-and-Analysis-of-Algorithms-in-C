/*

ID : B171452
Code By Sandeep Payili on 01/11/2021

Problem Description : Huffman Coding (Greedy Algorithm)

(Huffman Coding is a technique of compressing data to reduce its size without losing any of the details. 
It was first developed by David Huffman.Huffman Coding is generally useful to compress the data in which 
there are frequently occurring characters.)

*/

//The most frequent character gets the smallest code and the least frequent character gets the largest code.

/*

Huffman coding first creates a tree using the frequencies of the character and then generates code for each character.

Once the data is encoded, it has to be decoded. Decoding is done using the same tree.

Huffman Coding prevents any ambiguity in the decoding process using the concept of prefix code 
ie. a code associated with a character should not be present in the prefix of any other code. 
The tree created above helps in maintaining the property.


*/

/*

Huffman Coding Complexity :-

The time complexity for encoding each unique character based on its frequency is O(nlog n).

Extracting minimum frequency from the priority queue takes place 2*(n-1) times and its complexity is O(log n). 
Thus the overall complexity is O(nlog n).

*/

/*

Huffman Coding Applications :-

    1) Huffman coding is used in conventional compression formats like GZIP, BZIP2, PKZIP, etc.
    2) For text and fax transmissions.

*/