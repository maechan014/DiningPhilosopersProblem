DINING-PHILOSOPHERS SIMULATOR IN C++

To run the program, you can use the .exe file or open the .cpp file in your IDE (in my case, it's CodeBlocks).

The user should choose a scenario/condition to simulate. The user then is asked to input the total number of philosophers and the number of hungry philosophers.
The position of each hungry philosophers should also be indicated.

CONDITIONS/SCENARIO
(1) Condition: The philosophers can eat one at a time
(2) Condition: Two philosophers can eat at a time

NOTE:
- There is an input checking on the number of hungry philosophers (it should be less than the total number of philosophers).
- There is also an input checking on the positioning of the philosophers (it's range should not exceed the total number of philosophers)
- The positioning and ids of the philosophers will start at 0 and ends with total_philosophers-1
	eg.
		Total Number of Philosophers: 5
		Philosopher [0]
		Philosopher [1]
		Philosopher [2]
		Philosopher [3]
		Philosopher [4]

LIMITATIONS:
- Be careful when putting the inputs because not everything were handled and checked
- On the second scenario, all the philosophers should be hungry for the program to work. If some are not hungry, there will be an "out of range" error

	