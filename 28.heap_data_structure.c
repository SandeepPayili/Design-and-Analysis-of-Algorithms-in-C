/*

ID : B171452
Description : Heap  Data Structure
Code by Sandeep Payili on 01/11/2021

*/

/*

Building Heap from Array :-
	
	 heapify the complete binary tree formed from the array in reverse level order following a top-down approach.
	 That is first heapify, the last node in level order traversal of the tree, then heapify the second last node and so on.

Time Complexity:

      Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. 
      Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).

	  In reality, building a heap takes O(n) time depending on the implementation.

Optimized Approach: 

      The above approach can be optimized by observing the fact that the leaf nodes need not to be heapified as they already 
      follow the heap property.Also, the array representation of the complete binary tree contains the level order traversal of the tree.

	  So the idea is to find the position of the last non-leaf node and perform the heapify operation of each non-leaf node in reverse level order.


Last non-leaf node = parent of last-node.
or, Last non-leaf node = parent of node at (n-1)th index.  (n=no.of elements)
or, Last non-leaf node = Node at index ((n-1) - 1)/2.
                       = (n/2) - 1.

Insertion and Deletion in Heaps:-

Process of Deletion: 
		Since deleting an element at any intermediary position in the heap can be costly, so we can simply replace the element
		to be deleted by the last element and delete the last element of the Heap. 

    	>> Replace the root or element to be deleted by the last element.
    	>> Delete the last element from the Heap.
    	>> Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. 
    	   Therefore, heapify the last node placed at the position of root.

Process of Insertion: 
		Elements can be inserted to the heap following a similar approach as discussed above for deletion. The idea is to: 

    	>> First increase the heap size by 1, so that it can store the new element.
    	>> Insert the new element at the end of the Heap.
    	>> This newly inserted element may distort the properties of Heap for its parents. So, in order to keep the properties of Heap, 
    	   heapify this newly inserted element following a bottom-up approach.



Q) How do you implement buildHeap so it runs in O(n) time?
Q) How do you show that buildHeap runs in O(n) time when implemented correctly?
Q) Why doesn't that same logic work to make heap sort run in O(n) time rather than O(n log n)?

>> How do you implement buildHeap so it runs in O(n) time?
	The number of operations required for siftDown and siftUp is proportional to the distance the node may have to move. 
	For siftDown, it is the distance to the bottom of the tree, so siftDown is expensive for nodes at the top of the tree. 
	With siftUp, the work is proportional to the distance to the top of the tree, so siftUp is expensive for nodes at the bottom of the tree. 
	Although both operations are O(log n) in the worst case, in a heap, only one node is at the top whereas half the nodes lie in the bottom layer. 
	So it shouldn't be too surprising that if we have to apply an operation to every node, we would prefer siftDown over siftUp.

	Both of these solutions will produce a valid heap. Unsurprisingly, the more efficient one is the second operation that uses siftDown.

*/