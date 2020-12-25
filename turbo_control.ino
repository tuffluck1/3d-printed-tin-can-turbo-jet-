#include <Servo.h>

Servo ESC; //servo library reference 

int n = 50; //lowrev
bool mf = false;            //motor functioning 
bool sf = false;            //spark functioning 

int rangemin = 50;          // the starting speed for the precheck 
int rangemax = 200;         //max motor spin for the precheck (must be divisible by increment)               
int increment = 10;         // increment that the motor speed increases at 
int launchTiming = 1;       //the time between fuel priming and spark ignition

bool deadswitch = false;    //deadswitch boolean for fail safe




void setup() {

  Serial.begin(9600);        //start the serial monitor,
  
  ESC.attach(2, 1000, 2000); //attach the pins,
  
  ESC.write(15);             //arm the esc
   
  Serial.println("1 = yes");//inform the user of navigation protocols 
  Serial.println("2 = no");
}


void precheck(){             //verify prelaunch functionality 
   
  Serial.println("enter anything to begin precheck");           //verify ready for precheck
  while (Serial.available() ==0); {}

  while (mf == false) {      //check turbocharger motor function                                        
    ESC.write(n);            //spin the motor at low speed to reduce risk of stall
    delay(2000);

    
    while (n < rangemax) {              //rev up to max  
       ESC.write(n);                  
       n = n + increment;
       delay(50);
      }
    while (n > rangemin) {             //rev down to minimum
       ESC.write(n);
       n = n - increment;
       delay(50);
      }
    
    ESC.write(0);
    Serial.println("functioning?");
    while (Serial.available() ==0){}
    int resp= Serial.parseInt();
    if (resp = 1){
      mf = true;
      }
  
  
  //spark check
  
  
    }
  }

void countdown(){            //slow turbo spin for given amount of time to give a window for human failure analysis and shutdown if anything is sketchy
  
  int timer = 10;                         //timer length
  bool cont = false;
  
  while (cont = false); {           //verify ready for countdown
    Serial.println("begin countdown?");  
    while (Serial.available() ==0){}
    int resp = Serial.parseInt();
    if (resp = 1){
      cont = true;
      }
    }
 
  ESC.write(n);                           //start the motor
  
  
  
  while (timer < 0, deadswitch = true){   //timer function 
    if (Serial.available() != 0){         //manual stop check 
      deadswitch = false;
    }
    Serial.println(timer);                //the actual timer part
    delay(1000);
    timer--;
    } 
  
}

void PrimeAndLaunch(){      //start max air flow, prime for combustion with fuel and launch fire
  
  while (n < rangemax) {              //rev up to max  
    ESC.write(n);                  
    n = n + increment;
    delay(10);
    }
  
  ESC.write(200);
  delay(launchTiming);
  }

void operating(){          //execute operating processes such as data recording and failsafes
  
  }

void loop() { 
  Serial.println("enter 1 to start sequence");
  while (Serial.available() ==0){}
  int resp = Serial.parseInt();
}
