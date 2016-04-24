_**ShortestPath**_

**INPUT:**


        4
        sitting
        6
        1 2 1 3 2 4
        knitting
        4
        4 2 3 1
        knowing
        5
        2 3 1 4 2
        kneeding
        4
        1 3 4 2
        sitting
        kneeding


 
The first line is the number of Realms.
We have created a graph with Realm # (int n) of vertices.

Then we get the information for the n Realms. The following runs in a loop for n times:

		line 1: charm                       (string)
		line 2: # of Magis                  (int)
		line 3: Magis order and powers      (int array[])

  
Magis' order and powers refers to the order in which the Magis come/present themselves by giving us each Magi's power.
A power is used to change, remove, or add a character to the charm string.
Once a string has converted to another, you can move to that Realm.
These ints are used as weights/costs. This is what we want to minimize using ShortestPath.
You can only use the weights/costs in increasing order.
For example:
	
  		line 1: sitting
  		line 2: 6
  		line 3: 1 2 1 3 2 4
  
  
  		[1, 2, 1, 3, 2, 4]
  If we use weight 2 (index 1 in array), we CANNOT use weight 1 nor 2 afterwards (index 2 and 4 in array).
  If we use weight 2 (index 1 in array), we CAN use weight 3 and 4 afterwards (index 3 and 5 in array).
  The best way to use this realm would be to use the 1, 2, 3, 4 weights in this increasing order.
When this is completed, we create the Realm (vertex) in the graph.

After we get the information for n Realms, we get the charm(string) for the starting position Realm
and then the charm(string) for the destination Realm:
  line 4: sitting                   (start)
  line 5: kneeding                  (end)


**OUTPUT:**

		7 19
		5 13
	
The first line consists of two parts. This if for the path from start to end.
Part 1 is the incantations(number of Magis' powers used).
Part 2 is the minimum total powers used (total weights/costs used).

The second line is the same but for the return path. From end to start.


**GOAL:**
The goal is to minimize the amount of power(weights/costs) used in going from the start Realm to the destination Realm(and vice versa).
Each time you use a power, this counts as one 'incantation'. Keep track of this as it is part of output.
We can move from realm to realm as long as we have anough powers to convert one string to another. If we can't, output IMPOSSIBLE.
