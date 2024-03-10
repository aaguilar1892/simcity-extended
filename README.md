**Project 1: SimCity**

Group 207-2

Group Members: Alexis Aguilar, Corinna Martin, Claire Pacquing, Britton Womble

Compile Method:
    g++ -o simcity main.cpp intialization.cpp zone.cpp output.cpp
    ./simcity

Optional Compile Method with Makefile:
    make
    ./simcity
Files needed:
    config1.txt , region1.csv
    
    Format configuration file as follows:
    
    Region Layout:
    Time Limit:
    Refresh Rate:

Program Function:
    The program inputs the region, refresh rate, and max number of time steps using a configuration file specified by the user, then it outputs the initial state of the region. It then determines the growth of residential, industrial, and commercial zones in the region, and outputs the state of the region at the specified refresh rate along with the total number of available workers and goods in the region. When no changes have occurred between two times steps or if the max number of time steps has been reached, the program outputs the final region map. It then prompts for coordinates to look at a specific zone and outputs that zone.


