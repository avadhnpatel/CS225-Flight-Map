# kandula4-rnavin2-apate429-neehar2

Final Project

To run test: make test -> ./test

To run with user input: make -> ./flightmap
Input "Fastest" for Dijkstras Algorithm
Input "Landmark" for Landmark Algorithm

Airports data set contains airports without IATA values,
which was replaced by a "\N". This value was changed to
"N/A" and if this value was seen while parsing, that
airport was not added to the graph. Additionally, there was
about 20 instances out of 8000 airports where an additional
comma was included in the airport name. Our parsing
code splits the data based on commas so these additional
commas led to incorrect data being stored. These additional
commas were manually removed and any data set that is run
on this code must not have additional commas. Each element must
be seperated by a single comma. Each input line for airports and routes must be on a new line.
Input files must be named "airports.dat" and "routes.dat".

The airports data set must have airport name as second element, 
the IATA as the fifth element, the latitude is seventh element, 
and longitude is eighth element. In the airport data set, the IATA and
airport name begin and end with double quotation marks; 
ex: ("EWR")
ex: ("Newark Liberty International Airport")
This is a valid input line for Airports:
3830,"Chicago O'Hare International Airport","Chicago","United States","ORD","KORD",41.9786,-87.9048,672,-6,"A","America/Chicago","airport","OurAirports"

The routes data set must have source airport IATA as third element,
and the destination airport as fifth element.
This is a valid input line for routes:
AA,24,ORD,3830,ATL,3682,Y,0,E75 CR7