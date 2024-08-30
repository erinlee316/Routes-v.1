// Assignment 6 (part 1), Routes v.1

// Program will use one leg class, and will create an array to store 40 objects 
// that contains the start and end city (connected), and approximate distance 
// it takes to travel that path. The program will sort each object in array by 
// distance and output each of the routes' distances from shortest to longest.

// c++ libraries
#include <iostream>
#include <algorithm>    // used for sorting
using namespace std;

// class variables
class Leg
{
  // private data members
  const char* const startCity;
  const char* const endCity;
  const double distance;

  // public access with constructor, assignment operator, two getter functions
  public:
  Leg(const char* const start, const char* const end, const double dist) : startCity(start),
                                                                           endCity(end),
                                                                           distance(dist){}  
  Leg& operator=(const Leg&);
  double getDistance() const;
  void output(ostream&) const;
};

// function prototype
void id();

int main()
{
  // function call for identification information
  id();

  // declare array with 40 leg obejcts
  Leg l[] = 
  {
    Leg("Miami", "Orlando", 236.3),              
    Leg("Orlando", "Atlanta", 437.8),
    Leg("Atlanta", "Augusta", 145.0),
    Leg("Augusta", "Memphis", 536.5),
    Leg("Memphis", "Philadelphia", 1015.2),
    Leg("Philadelphia", "Pittsburgh", 305.2),
    Leg("Pittsburgh", "Erie", 127.8),
    Leg("Erie", "New Haven", 474.0),
    Leg("New Haven", "Princeton", 130.9),
    Leg("Princeton", "Jersey City", 47.4),
    Leg("San Francisco", "Berkeley", 13.6), 
    Leg("San Francisco", "Walnut Creek", 25.0),
    Leg("San Francisco", "San Jose", 48.8),
    Leg("San Francisco", "Concord", 31.4),
    Leg("San Francisco", "Sacramento", 87.9),
    Leg("Los Angeles", "San Diego", 120.2),
    Leg("Los Angeles", "Irvine", 39.7),
    Leg("Los Angeles", "Santa Monica", 16.2),
    Leg("Los Angeles", "Pasadena", 10.0),
    Leg("Los Angeles", "Riverside", 56.0),
    Leg("New York City", "Albany", 152.2),
    Leg("New York City", "Syracuse", 246.6),
    Leg("New York City", "Ithaca", 222.4),
    Leg("New York City", "Rochester", 332.7),
    Leg("New York City", "Buffalo", 372.8),
    Leg("Boston", "Quincy", 10.4),
    Leg("Boston", "Cambridge", 3.1),
    Leg("Boston", "Amherst", 94.4),
    Leg("Boston", "New Bedford", 59.2),
    Leg("Boston", "Worcester", 47.5),
    Leg("Austin", "Houston", 165.3),
    Leg("Austin", "Dallas", 195.2),
    Leg("Austin", "San Antonio", 79.6),
    Leg("Austin", "Texas City", 209.9),
    Leg("Austin", "Fort Worth", 189.8),
    Leg("Chicago", "Springfield", 201.9),
    Leg("Chicago", "Rockford", 88.9),
    Leg("Chicago", "Champaign", 135.4),
    Leg("Chicago", "Illinois City", 196.9),
    Leg("Chicago", "Naperville", 33.0)
  };

  // declare and initialize integer with size of leg object array
  const int LEG_SIZE = sizeof(l) / sizeof(l[0]);

  // sort all objects by distance from shortest to longest
  // move through all objects in bag
  for (int i = 0; i < LEG_SIZE; i++)
  {
    // compare current object type with all other object types
    for (int j = i + 1; j < LEG_SIZE; j++)
    {
      // object's distance at index j is less than object's distance at index i
      // switch places to make object at index i smaller
      if (l[j].getDistance() < l[i].getDistance())
          swap(l[i], l[j]);
    }
  }

  // output array of cities in ascending order of distance
  for (int k = 0; k < LEG_SIZE; k++)
    l[k].output(cout);

  return 0;
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// assignment operator function for leg class
// used for copying information from one leg object to another leg object
Leg& Leg::operator=(const Leg& copyThis)
{
  // declare reference variable to host object
  Leg& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host and assign copy to parameter 
  if (this != &copyThis)
  {
    const_cast<const char*&>(host.startCity) = copyThis.startCity;
    const_cast<const char*&>(host.endCity) = copyThis.endCity;
    const_cast<double&>(host.distance) = copyThis.distance;
  }

  // return reference variable
  return host;
}

// getter function will return distance without manipulating the variable
double Leg::getDistance() const
{
  return distance;
}

// getter function will display output to console 
void Leg::output(ostream& out) const
{
  out << "Leg: " << startCity << " to " << endCity << ", " << getDistance() << " miles." << endl;
}

