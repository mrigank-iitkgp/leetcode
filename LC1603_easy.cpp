/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/design-parking-system/
*/


class ParkingSystem {
public:
    vector < vector < int > > parkingLot;
    vector < int > sz;
    ParkingSystem(int big, int medium, int small) 
    {
        parkingLot.resize(3);
        sz.resize(3);
        sz[0] = big;
        sz[1] = medium;
        sz[2] = small;
    }
    
    bool addCar(int carType) 
    {
        if(parkingLot[carType - 1].size() >= sz[carType - 1])
            return false;
        parkingLot[carType - 1].push_back(1);
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
