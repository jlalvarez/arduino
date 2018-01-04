const int a = 2; 
const int b = 3; 
const int c = 4; 
const int d = 5; 
const int e = 6; 
const int f = 7; 
const int g = 8; 

const int btn_inc = 9; 
const int btn_dec = 10;
  
const int t_antirebote = 10; 
 
int count = 0; // The count 
int state_btn_inc; 
int state_btn_last_inc=0; 
int state_btn_dec; 
int state_btn_last_dec=0; 
 
 
// Function antirebote 
 
boolean antirebote(int pin){ 
  int counter = 0; 
  boolean state; 
  boolean last_state; 
 
  do{ 
    state = digitalRead(pin); 
    if(state != last_state){ 
      counter = 0; 
      last_state = state; 
    } else { 
      counter = counter + 1; 
    } 
    delay(1); 
  }while(counter < t_antirebote); 
 
  return state; 
} 


void setup(){
  Serial.begin(9600);
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  
  pinMode(btn_inc, INPUT); // Increment button 
  pinMode(btn_dec, INPUT); // Decrement button 
}
 
void showNumber(int n){ 
  switch(n){ 
    case 0: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, LOW); 
          digitalWrite(f, LOW); 
          digitalWrite(g, HIGH); 
          break; 
 
    case 1: 
          digitalWrite(a, HIGH); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, HIGH); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, HIGH); 
          digitalWrite(g, HIGH); 
          break; 
 
    case 2: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, HIGH); 
          digitalWrite(d, LOW); 
          digitalWrite(e, LOW); 
          digitalWrite(f, HIGH); 
          digitalWrite(g, LOW); 
          break; 
 
    case 3: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, HIGH); 
          digitalWrite(g, LOW); 
          break; 
          
    case 4: 
          digitalWrite(a, HIGH); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, HIGH); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, LOW); 
          digitalWrite(g, LOW); 
          break; 
          
    case 5: 
          digitalWrite(a, LOW); 
          digitalWrite(b, HIGH); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, LOW); 
          digitalWrite(g, LOW); 
          break; 
 
    case 6: 
          digitalWrite(a, LOW); 
          digitalWrite(b, HIGH); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, LOW); 
          digitalWrite(f, LOW); 
          digitalWrite(g, LOW); 
          break; 
 
    case 7: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, HIGH); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, HIGH); 
          digitalWrite(g, HIGH); 
          break; 
 
    case 8: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, LOW); 
          digitalWrite(f, LOW); 
          digitalWrite(g, LOW); 
          break; 
 
    case 9: 
          digitalWrite(a, LOW); 
          digitalWrite(b, LOW); 
          digitalWrite(c, LOW); 
          digitalWrite(d, LOW); 
          digitalWrite(e, HIGH); 
          digitalWrite(f, LOW); 
          digitalWrite(g, LOW); 
          break; 
    } 
  } 


void loop() {

// antirebote code for up button
 state_btn_inc = digitalRead(btn_inc); //read the button state
 if(state_btn_inc != state_btn_last_inc){ // If you have change on last state
   if(antirebote(btn_inc)){ // Check if is press and is true,
     count++; // Up the count.
     if(count > 9){ 
       count = 9;
     }
   }
 }
  state_btn_last_inc = state_btn_inc; // Save the state of button

// antirebote code for down button
  state_btn_dec = digitalRead(btn_dec); //read the button state 
  if(state_btn_dec != state_btn_last_dec){ // If you have change on last state
    if(antirebote(btn_dec)){ // Check if is press and is true,
      count--; // Up the count.
      if(count < 0){ 
        count = 0;
      }
    }
  }
  state_btn_last_dec = state_btn_dec; // Save the state of button

  showNumber(count); //show the display
  

}

/*
void loop()
{
  
  for(int i=0; i<=9; i++) {
    showNumber(i);
    delay(1000);
  }
}
*/