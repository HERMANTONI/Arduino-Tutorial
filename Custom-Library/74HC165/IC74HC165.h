/*Author: Hermantoni
**Learn Together
*/
uint8_t IC74hc165(uint8_t PL, uint8_t CP, uint8_t Q7, uint8_t CE){
  digitalWrite(PL,0); delayMicroseconds(5);
  digitalWrite(PL,1); delayMicroseconds(10);
  digitalWrite(CP,1); digitalWrite(CE,0);
  uint8_t bitData[]={1,2,4,8,16,32,64,128};
  uint8_t data=0;
  for (uint8_t hh=0; hh<8; hh++){
    delayMicroseconds(5); digitalWrite(CP,0);
    if (digitalRead(Q7) == 0){
      data=data+bitData[hh];
    }
    delayMicroseconds(5); digitalWrite(CP,1);
  }
  delayMicroseconds(5); digitalWrite(CP,0); digitalWrite(CE,1);
  return data;
}
