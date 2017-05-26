Algorithm Applied: Temporal Difference(0)

Algorithm:
----------
1. Read the input data from the data file passed through the command line argument.
2. Initialize all the state values to 0.
3. Run step 4 to 5 a large number of times so that the state values gets converged to the final state value:
4. For each of the simulation updated state value needs to be calculated using the below given formula. 
5. The updated value of the current state would be: Old value of the current state + Alpha(i.e. a small number) * ((Reward from the current state + discount_factor * State value of the next state) - Old value of the current state).
6. When the value converged to the final value then terminate the procedure.
7. Print the caclculated values on the standard output.


Reference:
----------
1. Reinforcement Learning: An Introduction by Richard S. Sutton and Andrew G. Barto

