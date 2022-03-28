#include "Car.h"

class Mercedes : public Car {
public:
    Mercedes() : Car(70, 8.5, 80.5, 110.6, 93.5, "Mercedes") {}
    ~Mercedes() {}
    virtual double timeNeeded(int length, Weather weather) override;
    virtual bool canFinish(int length) override;
};