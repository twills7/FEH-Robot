// Import all necessary libraries here
#include <FEHIO.h>
#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHBuzzer.h>
#include <FEHMotor.h>

#define SLEEP 1.0
#define DISTANCE_1 10.0
#define PI 3.1415

// Fill in the pin declarations

FEHMotor leftDrive(FEHMotor::Motor1,9.0);
FEHMotor rightDrive(FEHMotor::Motor0,9.0);
DigitalInputPin frontRight(FEHIO::P1_0);
DigitalInputPin frontLeft(FEHIO::P1_3);
DigitalInputPin backRight(FEHIO::P1_1);
DigitalInputPin backLeft(FEHIO::P1_2);
DigitalEncoder right_encoder(FEHIO::P1_0);
DigitalEncoder left_encoder(FEHIO::P1_1);

static void driveForward(int power, float distance){
    float shaft = (distance * 2 * 2.5 * PI) / 318;
    rightDrive.SetPercent(power);
    leftDrive.SetPercent(power);
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();
    while (right_encoder.Counts() < shaft || left_encoder.Counts() < shaft){
        if (right_encoder.Counts() > shaft){
            rightDrive.Stop();
        }
        if (left_encoder.Counts() > shaft){
            leftDrive.Stop();
        }
    }
}
int main() {
    
}