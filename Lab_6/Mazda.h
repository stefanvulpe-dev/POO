#include "Car.h"

class Mazda : public Car {
public:
    Mazda() : Car(65, 9.5, 78.5, 101.6, 80.4, "Mazda") {}
    ~Mazda() {}
    virtual double timeNeeded(int length, Weather weather) override;
    virtual bool canFinish(int length) override;
};