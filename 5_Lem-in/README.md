# 5_Lem-in

The goal of this project is to find the quickest way to get n ants across the farm.

Quickest way means the solution with the least number of lines.

At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time.

In our project we used BFS as a main algorithm for traversing our graph data structure. Still, we optimized it, determinig and cutting of inherently unrealistic or ineffective paths in the process of search and stopping when the best option was definitely already found.

Usage:  ./lem-in < maps/*map_test*

Run the program with [-v] flag to see the wonderful graphics! :)
Press ctrl to highlight the paths we chose and numeric enter to make ants move. 
