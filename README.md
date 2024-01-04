---------------------------------------TRAIN SCHEDULE MANAGEMENT SYSTEM---------------------------------------------

This C program implements a simple Train Schedule Management System. Users can add, edit, and delete train details, and then perform various queries on the train schedule. 
The program uses a menu-driven approach to interact with the user.

FUNCTIONALITY
-List all trains departed from a particular station:

  Enter the departure station, and the program will display all trains departing from that station.
  
-List all trains departed from a particular station at a particular time:

  Enter the departure station and the desired departure time (hour and minute), and the program will display matching trains.
  
-List all trains departed from a particular station within the next one hour of a given time:

  Enter the departure station and a time (hour and minute), and the program will display trains departing within the next hour of that time.
  
-List all trains between a pair of start station and end station:

  Enter the departure and arrival stations, and the program will display trains between those stations.
  
Edit train details:

  Add a new train, delete an existing train, or exit the train edit menu.

Train Structure:

The program uses a TRAIN structure to store train information, including train number, name, start station, end station, departure time, and arrival time. 
The time is represented using a TIME structure with hour and minute fields.

Train Edit Menu:
The train edit menu allows users to add a new train, delete an existing train, or exit the menu.

The program uses a continuous loop for the main menu until the user chooses to exit.
