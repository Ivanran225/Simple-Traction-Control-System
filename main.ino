#include <iostream>

class TractionControlSystem {
public:
    TractionControlSystem(double targetWheelSpeed, double maxSlip) 
        : targetWheelSpeed(targetWheelSpeed), maxSlip(maxSlip) {
        currentEnginePower = 0.0;
    }

    void setVehicleSpeed(double vehicleSpeed) {
        this->vehicleSpeed = vehicleSpeed;
    }

    void setWheelSpeed(double wheelSpeed) {
        this->wheelSpeed = wheelSpeed;
    }

    void update() {
        // Calculate the wheel slip
        double slip = (targetWheelSpeed - wheelSpeed) / targetWheelSpeed;

        // Adjust the engine power or apply the brakes to control slip
        if (slip > maxSlip) {
            // Too much slip, reduce engine power or apply brakes
            currentEnginePower -= 10.0; // Adjust this value based on your vehicle characteristics
            if (currentEnginePower < 0.0) {
                currentEnginePower = 0.0;
            }
        } else {
            // Acceptable slip, increase engine power
            currentEnginePower += 5.0; // Adjust this value based on your vehicle characteristics
            if (currentEnginePower > 100.0) {
                currentEnginePower = 100.0;
            }
        }

        // Output the current engine power
        std::cout << "Current Engine Power: " << currentEnginePower << "%" << std::endl;
    }

private:
    double targetWheelSpeed;
    double maxSlip;
    double vehicleSpeed;
    double wheelSpeed;
    double currentEnginePower;
};

int main() {
    TractionControlSystem tractionControl(100.0, 0.1); // Target wheel speed and max allowable slip

    // Simulate vehicle and wheel speed updates
    for (int time = 0; time < 10; time++) {
        double vehicleSpeed = 50.0; // Simulated vehicle speed (in km/h)
        double wheelSpeed = 48.0;   // Simulated wheel speed (in km/h)

        tractionControl.setVehicleSpeed(vehicleSpeed);
        tractionControl.setWheelSpeed(wheelSpeed);
        tractionControl.update();
    }

    return 0;
}
