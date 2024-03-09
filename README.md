# MetroWayFinder

The Metro Route Finder is a software application designed to assist commuters in finding the shortest route and calculating fares between two metro stations in a metro network. This application utilizes graph and heap data structures to represent the metro network, where nodes represent metro stations and edges represent connections between stations.

# Features:

* Graph Representation: The metro network is represented as a graph, where each node represents a metro station containing information such as its name and the lines it connects to. The edges between nodes represent the distance between two stations, and the cost of each edge is equal to the distance between the connecting stations.

* Shortest Path Algorithms: The application implements various algorithms such as Dijkstra, breadth-first search, and depth-first search to determine the shortest path between a source station and a destination station.

* Fare Calculation: The application calculates the fare based on the total distance between the source and destination stations. The fare is determined according to the metro fare structure.

* Special Node Specification: Users have the option to specify a special node that should be included in the path between the source and destination stations. This allows commuters to include specific stations or lines in their route if desired.

# Usage:

* Input Stations: Enter the source and destination metro stations.
* Specify Special Node: Optionally specify a special node that should be included in the path.
* Calculate Route: The application calculates the shortest route and fare between the specified stations.
* Display Route: The metro route between the source and destination stations, along with the total fare, is displayed to the user.

# Implementation Details:

Graph Data Structure: The metro network is represented as a graph using adjacency lists or adjacency matrices.
Set Data Structure: A set is used to efficiently determine the shortest path between stations.
Algorithms: Various graph traversal and shortest path algorithms are implemented, such as Dijkstra's algorithm, to find the shortest route.
Unorderd Map:Used to store shortest distance of each node from the source and the parent of the source.
