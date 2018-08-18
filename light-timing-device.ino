// ================================================================
// ================================================================
// ==========                                            ==========
// ==========            LTD FINAL CODE v2.0             ==========
// ==========                                            ==========
// ================================================================
// ================================================================


// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

// ========== LED Matrix Setup ===========
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

//The pins defined here can be modified; the pins that aren't defined cannot.
#define OE   9
#define LAT A3
#define CLK 11
#define A   A0
#define B   A1
#define C   A2
#define D   8 //Don't actually plug this into pin 8; plug into GND instead.
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);
/* NOTES FOR LED MATRIX WIRING LAYOUT
 *  ==============           ==============
 *  == G1   R1  ==           == 25   24  ==
 *  == GND  B1  ==           == GND  26  ==
 *  == G2   R2  ==== k       == 28   27  ==== k
 *  == GND  B2  ==== e       == GND  29  ==== e
 *  == B    A   ==== y       == A1   A0  ==== y
 *  == D    C   ====         == GND   A2 ====
 *  == LAT  CLK ==           == A3   11  ==
 *  == GND  OE  ==           == GND  9   ==
 *  ==============           ==============
 *  LED MATRIX               ARDUINO
 *  
 *  NOTE: DO NOT ACTUALLY PLUG D INTO PIN 8, THE RF REMOTE WILL STOP WORKING 
 */

// ========== LED Matrix Setup ===========

// ========== Accelerometer Setup ===========
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 sensor1(0x68); //ADO to GND
MPU6050 sensor2(0x69); //ADO to 5V

int16_t ax1, ay1, az1;
int16_t gx1, gy1, gz1;
long ax1avg, ay1avg, az1avg;

int16_t ax2, ay2, az2;
int16_t gx2, gy2, gz2;
long ax2avg, ay2avg, az2avg;

const int sensitivity = 5000;

/* NOTES FOR ACCELEROMETER WIRING LAYOUT
 *  --see word document--
 */

// ========== Accelerometer Setup ===========

// ========== Wireless Button Setup ===========
#define remoteA A10 //D3
#define remoteB A11 //D2
#define remotePower A14 //5V
#define remoteGnd A15 //GND
// ========== Wireless Button Setup ===========

// ========== Wired Button Setup ===========
#define wiredPower 42 // USB red
#define button1 44    // USB green (data 1)
#define button2 46    // USB white (data 2)
#define wiredGnd 48   // USB black
// ========== Wired Button Setup ===========



// ========== Miscellaneous Setup ===========
bool started = false;
bool calibrated = false;
bool menu = true;
int mode = 0; // 0 = competition mode; 1 = practice mode
int buttonState = 0; // 0 = none pressed; 1 = button1; 2 = button2
int cnt = 0;
int avgcnt = 200;

int txtr = 0;
int txtg = 7;
int txtb = 7;

int dispDelay = 10;




// ================================================================
// ===                      ARDUINO SETUP                       ===
// ================================================================

void setup() {
  // ========== Serial Monitor Setup ===========
  Serial.begin(38400);
  Serial.println("Initializing Setup...");
  // ========== Serial Monitor Setup ===========
  
  // ========== LED Matrix Setup ===========
  Serial.println("  Initializing LED Matrix Setup...");
  matrix.begin(); // Initialize matrix
 // matrix.fillRect(0, 8, 64, 16, matrix.Color333(0, 0, 7)); //print BLUE screen
  //matrix.swapBuffers(false);
  Serial.println("  LED Matrix Setup Complete");
  // ========== LED Matrix Setup ===========

  // ========== Accelerometer Setup ===========
  Serial.println("  Initializing Accelerometer Setup...");
  Wire.begin(); //join I2C bus
  Serial.println("    Initializing I2C devices...");
  sensor1.initialize();
  sensor2.initialize();
  Serial.println("    Testing device connections...");
  Serial.println(sensor1.testConnection() ? "    MPU6050 #1 connection successful" : "    MPU6050 #1 connection failed");
  Serial.println(sensor2.testConnection() ? "    MPU6050 #2 connection successful" : "    MPU6050 #2 connection failed");
  Serial.println("  Accelerometer Setup Complete");
  // ========== Accelerometer Setup ===========

  // ========== Wired Button Setup ===========
  Serial.println("  Initializing Wired Button Setup...");
  pinMode(wiredPower, OUTPUT);
  pinMode(wiredGnd, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  digitalWrite(wiredPower, HIGH);
  digitalWrite(wiredGnd, LOW); 
  Serial.println("  Wired Button Setup Complete");
  // ========== Wired Button Setup ===========

  // ========== Wireless Button Setup ===========
  Serial.println("  Initializing Wireless Button Setup...");
  pinMode(remotePower, OUTPUT);
  pinMode(remoteGnd, OUTPUT);
  pinMode(remoteA, INPUT);
  pinMode(remoteB, INPUT);
  digitalWrite(remotePower, HIGH);
  digitalWrite(remoteGnd, LOW); 
  Serial.println("  Wireless Button Setup Complete");
  // ========== Wireless Button Setup ===========

  // ========== Random Setup ==========
  Serial.println("  Initializing Random Number Setup...");
  randomSeed(analogRead(A10));
  Serial.println("  Random Number Setup Complete");
  // ========== Random Setup ==========
  
  Serial.println("Setup Complete");

  matrix.fillScreen(0);
  matrix.swapBuffers(false);
  // ========== Record Initial Accelerometer Values ==========
}

// ================================================================
// ===                       AFTER SETUP                        ===
// ================================================================

void loop() {
  // ============================================
  // ===              MENU STATE              ===
  // ============================================
  if (menu == true){
    matrix.fillScreen(0);
    matrix.setTextWrap(false);

    switch(mode) {
      case 0: printMode('C'); break;
      case 1: printMode('P'); break;
    }
    matrix.swapBuffers(false);

    // Check Button Click for Mode Toggle or Menu Exit
    buttonState = readButtons();
    switch(buttonState) {
      case 0: break; //no button pressed
      case 1: mode == 0 ? mode = 1 : mode = 0; break; //red or A pressed
      case 2: menu = false; break; //green or B pressed
    }

    //reset button click
    buttonState = 0;
  }

  // ===============================================
  // ===              STANDBY STATE              ===
  // ===============================================
  else if (menu == false && started == false) {
    matrix.fillScreen(0);
    matrix.swapBuffers(false);
        
    //check 2nd Button, if clicked, start
    buttonState = readButtons();
    switch(buttonState) {
      case 0: break; //no button pressed
      case 1: break; //red or A pressed
      case 2: started = true; break; //green or B pressed
    }
    //reset button click
    buttonState = 0;
    
  }

  
  // =============================================
  // ===              THROW STATE              ===
  // =============================================
  else if (menu == false && started == true) {

    // ==================================================
    // ===              COMPETITION MODE              ===
    // ==================================================
    if (mode == 0) { // Competition Mode
      
      int delaytime = random(0000, 3000);
      bool roundOver = false;

  
      matrix.fillScreen(matrix.Color333(7, 3, 0));      // Fill screen with amber
      matrix.swapBuffers(false);
      calibrate(); //Calibrate accelerometers
      delay(delaytime);
     
      matrix.fillScreen(matrix.Color333(0, 7, 0));      // Fill screen with green
      matrix.swapBuffers(false);
      
      unsigned long starttime = millis();
      unsigned int p1time = 0;
      unsigned int p2time = 0;
      unsigned int roundtime = 0;
      bool p1done = false;
      bool p2done = false;
      bool reset = false;
  
  
      // ========== Waiting for Knife to Hit ===========
      while (roundOver == false) {
        // Reading values from accelerometers
        sensor1.getAcceleration(&ax1, &ay1, &az1);
        sensor2.getAcceleration(&ax2, &ay2, &az2);
  
        // Calculate difference between current accelerometer reading and average value calculated during setup
        int ax1Diff = ax1 - ax1avg;
        int ay1Diff = ay1 - ay1avg;
        int az1Diff = az1 - az1avg;
  
        int ax2Diff = ax2 - ax2avg;
        int ay2Diff = ay2 - ay2avg;
        int az2Diff = az2 - az2avg;
        
        roundtime = millis()-starttime;
        /*Serial.println("Round Time: \t");
        Serial.print (roundtime);
        
        Serial.print("MPU1:\t");
        Serial.print(ax1Diff); Serial.print("\t");
        Serial.print(ay1Diff); Serial.print("\t");
        Serial.print(az1Diff); Serial.print("\t\t\t");
    
        Serial.print("MPU2:\t");
        Serial.print(ax2Diff); Serial.print("\t");
        Serial.print(ay2Diff); Serial.print("\t");
        Serial.println(az2Diff);*/
  
        if ((abs(ax1Diff) > sensitivity || abs(ay1Diff) > sensitivity || abs(az1Diff) > sensitivity) && p1done == false) {
          p1time = roundtime;
          p1done = true;
        }
        if ((abs(ax2Diff) > sensitivity || abs(ay2Diff) > sensitivity || abs(az2Diff) > sensitivity) && p2done == false) {
          p2time = roundtime;
          p2done = true;
        }
  
        if (p1done == true && p2done == true){
          roundOver = true;
          reset = false;
          matrix.fillScreen(matrix.Color333(0, 0, 0));
          matrix.swapBuffers(false);
          /*Serial.println("\n\n\n");
          Serial.println(p1time);
          Serial.println(p2time);*/
          cnt = 0;
          delay(1000);
        }
        else if (roundtime >= 10000){
          p1done == true ? p1time = p1time : p1time = 9999;
          p2done == true ? p2time = p2time : p2time = 9999;
          roundOver = true;
          reset = false;
          matrix.fillScreen(matrix.Color333(0, 0, 0));
          matrix.swapBuffers(false);
          /*Serial.println("\n\n\n");
          Serial.println("p1time:");
          Serial.println(p1time);
          Serial.println("p2time:");
          Serial.println(p2time);*/
          cnt = 0;
          delay(1000);
        }
      }
      
      // ========== After Knife Hits ===========
      while (roundOver == true && reset == false) { 
        cnt = cnt + 1;
        //Serial.println(cnt);
        if (cnt < dispDelay) {
          if (p1time < p2time) {
            // Fill main display with green, slave display with red
            matrix.fillRect(0, 0, 32, 32, matrix.Color333(7, 0, 0));
            matrix.fillRect(32, 0, 32, 32, matrix.Color333(0, 7, 0));
          }
          else if (p2time < p1time) {
            // Fill main display with red, slave display with green
            matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 7, 0));
            matrix.fillRect(32, 0, 32, 32, matrix.Color333(7, 0, 0));
          }
          else {
            matrix.fillScreen(matrix.Color333(0, 7, 7));
          }
        }
        else {
            matrix.fillScreen(0);
            printTime(p1time, 33, 9);
            printTime(p2time, 1, 8);
        }
        matrix.swapBuffers(false);
        buttonState = readButtons();
        switch(buttonState) {
          case 0: break; //no button pressed
          case 1: break; //red or A pressed
          case 2: 
            reset = true;
            started = false;
            roundOver = false;
            cnt = 0;
            break;
        }
        buttonState = 0;
      }
    }

    // =================================================
    // ===               PRACTICE MODE               ===
    // =================================================
    if (mode == 1) {
      int delaytime = random(1000, 4000);
      bool roundOver = false;
  
      matrix.fillScreen(matrix.Color333(7, 3, 0));      // Fill screen with amber
      matrix.swapBuffers(false);
      calibrate(); //Calibrate accelerometers
      delay(delaytime);
     
      matrix.fillScreen(matrix.Color333(0, 7, 0));      // Fill screen with green
      matrix.swapBuffers(false);
      
      unsigned int starttime = millis();
      unsigned int p1time = 0;
      unsigned int roundtime = 0;
      bool p1done = false;
      bool reset = false;
  
  
      // ========== Waiting for Knife to Hit ===========
      while (roundOver == false) {
        // Reading values from accelerometers
        sensor1.getAcceleration(&ax1, &ay1, &az1);
  
        // Calculate difference between current accelerometer reading and average value calculated during setup
        int ax1Diff = ax1 - ax1avg;
        int ay1Diff = ay1 - ay1avg;
        int az1Diff = az1 - az1avg;

        roundtime = millis()-starttime;
        /*Serial.println("Round Time: \t");
        Serial.print (roundtime);
        
        Serial.print("MPU1:\t");
        Serial.print(ax1Diff); Serial.print("\t");
        Serial.print(ay1Diff); Serial.print("\t");
        Serial.print(az1Diff); Serial.print("\t\t\t");*/

  
        if ((abs(ax1Diff) > sensitivity || abs(ay1Diff) > sensitivity || abs(az1Diff) > sensitivity) && p1done == false) {
          p1time = roundtime;
          p1done = true;
        }
  
        if (p1done == true){
          roundOver = true;
          reset = false;
          matrix.fillScreen(matrix.Color333(0, 0, 0));
          matrix.swapBuffers(false);
          /*Serial.println("\n\n\n");
          Serial.println(p1time);*/
          cnt = 0;
          delay(1000);
          Serial.println(millis());
        }
        else if (roundtime >= 10000){
          p1time = 9999;
          roundOver = true;
          reset = false;
          matrix.fillScreen(matrix.Color333(0, 0, 0));
          matrix.swapBuffers(false);
          /*Serial.println("\n\n\n");
          Serial.println("p1time:");
          Serial.println(p1time);*/
          cnt = 0;
          delay(1000);
        }
      }
      
      // ========== After Knife Hits ===========
      while (roundOver == true && reset == false) { 
        cnt = cnt + 1;
        //Serial.println(cnt);
        matrix.fillScreen(0);
        printTime(p1time, 33, 9);
        matrix.swapBuffers(false);
        buttonState = readButtons();
        switch(buttonState) {
          case 0: break; //no button pressed
          case 1: break; //red or A pressed
          case 2: 
            reset = true;
            roundOver = false;
            break;
        }
        /*if (cnt > 10 * dispDelay) {      <- this allows auto reset
          reset = true;
          roundOver = false;
          Serial.println(millis());
        }*/
        buttonState = 0;
      }
    }
  }
}

