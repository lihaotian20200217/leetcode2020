/*
    LeetCode 1603
*/

class ParkingSystem {
public:
    int b = 0, m = 0, s = 0;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1)
        {
            if (b) b--;
            else return false;
        }
        else if (carType == 2)
        {
            if (m) m--;
            else return false;
        }
        else 
        {
            if (s) s--;
            else return false;
        }
        return true;
    }
};
