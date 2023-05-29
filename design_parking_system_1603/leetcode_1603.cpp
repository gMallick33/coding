class ParkingSystem {
public:
    int bigCap, mediumCap, smallCap;
    int bigCurr, mediumCurr, smallCurr;
    ParkingSystem(int big, int medium, int small) {
        bigCap = big;
        mediumCap = medium;
        smallCap = small;
        bigCurr = mediumCurr = smallCurr = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bigCap == bigCurr) return false;
            else {
                bigCurr++;
                return true;
            }
        }

        if(carType == 2){
            if(mediumCap == mediumCurr) return false;
            else {
                mediumCurr++;
                return true;
            }
        }

        else{
            if(smallCap == smallCurr) return false;
            else {
                smallCurr++;
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */