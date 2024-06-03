#include <iostream>
#include <utility>

class Location {
  private:
    int street;
    int avenue;
  public:
    Location() : street(0), avenue(0) {}
    Location( int street, int avenue){
      this->street = street; 
      this->avenue = avenue; 
    }
    void setStreet(int street ) {this->street = street;}
    void setAvenue(int avenue ) {this->avenue = avenue;}
    int getStreet() {return street;}
    int getAvenue() {return avenue;}
    int sumStreetAvenue() {return street + avenue;}

    int operator-( const Location& obj ){
      return abs(street - obj.street) + abs(avenue - obj.avenue );
    }

    Location &operator=( const Location& obj){
      street = obj.street;
      avenue = obj.avenue;
      return *this;
    }

    friend std::ostream &operator<<( std::ostream &out, const Location& obj){
      out << "(Street: " << obj.street << ", " 
        << "Avenue: " << obj.avenue << ")";
      return out;
    }

    friend std::istream &operator>>( std::istream &input, Location& p ){
      input >> p.street >> p.avenue;
      return input;
    }
};

class Grid {
  private:
    int numOfStreets;
    int numOfAvenues;
    int numOfFriends;
    Location *friends;
  public:
    Grid() {};
    Grid( int numOfStreets, int numOfAvenues, int numOfFriends){
      this->numOfStreets = numOfStreets; 
      this->numOfAvenues = numOfAvenues; 
      this->numOfFriends = numOfFriends; 
      friends = new Location[numOfFriends]; 
    }
    ~Grid() {delete[] friends;}

    Location meetingLocation(){
      //makes the biggest side the dimension
      int dimension = (numOfStreets > numOfAvenues ) ? numOfStreets : numOfAvenues;

      // Draw a grid 
      // Find the distance of every friend to every point on the grid
      // The best location will be the one that gives the minimum distance for every one 
      int length = (dimension + 1) * (dimension + 1);
      int *distances = new int[length];
      int minDistance = -1, distance = 0;
      Location bestLocation;
      size_t i = 0, j = 0, k = 0; //It is a type that may express the size of any object in bytes

    //initialize to zero
      for (i = 0; i < length; i++)
        distances[i] = 0;

      // Compute the distance for each friend to every location on the Grid
      for (i = 0; i < numOfFriends; i++ )
        for (j = 1; j <= dimension; j++ )
          for (k = 1; k <= dimension; k++ )
            distances[j * dimension + k ] += abs(friends[i].getStreet() - j) + abs(friends[i].getAvenue() - k);
            //width * row + col -> mapping a 2d into a 1d array;
      
      // Find the minimum distance
      std::pair<int, int> location;
      for (j = 1; j <= dimension; j++){
        for ( k = 1; k <= dimension; k++){
          if (minDistance == -1 || distances[ j * dimension + k ] < minDistance ){
            minDistance = distances[ j * dimension + k ];
            location = {j, k};
          } else if ( minDistance == distances[ j * dimension + k ] && std::make_pair<int, int>(j, k) < location)
            location = {j, k};
        }
      }
      delete[] distances;
      bestLocation = Location(location.first, location.second);
      return bestLocation;
    }

    friend std::istream &operator>>( std::istream &input, Grid& obj )
    {
      for (int i = 0; i < obj.numOfFriends; i++)
        input >> obj.friends[i];

      return input;
    }

    friend std::ostream &operator<<( std::ostream &out, const Grid& obj)
    {
      for ( size_t i = 0; i < obj.numOfFriends; i++)
          out << obj.friends[i] << std::endl;
      return out;
    }

};

int main()
{
  int testCases = 0, numOfStreets = 0, numOfAvenues = 0, numOfFriends = 0;
  Grid *city;

  std::cin >> testCases;
  testCases++;
  
  while(testCases--) {
    std::cin >> numOfStreets >> numOfAvenues >> numOfFriends;
    city = new Grid(numOfStreets, numOfAvenues, numOfFriends);
    std::cin >> *city;
    std::cout << city->meetingLocation() << std::endl;
    delete city;
  }

  return 0;
}
