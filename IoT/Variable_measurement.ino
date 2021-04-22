#define ANALOG_IN_PIN A0
// Floats for ADC voltage, Input voltage, Current and Power
float adc_voltage = 0.0;
float in_voltage = 0.0;
float current = 0.0;
float power = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 1000.0;
float R2 = 330.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;

 
void setup(){
   // Setup Serial Monitor
   Serial.begin(9600);
   Serial.println("LABEL,t,voltage,current,power");
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)); 

   // Calculate current in mA
   current = in_voltage / (R1+R2);

   // Calculate power
   power = current*in_voltage;
   
   // Print results to Serial Monitor to 2 decimal places
   Serial.print("DATA,TIME,"); // PLX-DAQ command
   Serial.print(in_voltage,4);    //send the voltage to serial port
   Serial.print(", ");
   Serial.print(current,4);    //send the current to serial port
   Serial.print(", ");
   Serial.println(power,4);  //send the power to serial port
  
  // Short delay
  delay(1000);
}
