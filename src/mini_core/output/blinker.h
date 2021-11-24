class Flasher
{
    int ledPin;      
    int ledState;               
    unsigned long previousMillis;   

  public:
    unsigned long OnTime;     
    unsigned long OffTime;  
    Flasher(int pin, long off)
    {
      this->ledPin = pin;
      pinMode(this->ledPin, OUTPUT);

      
      this->OffTime = off;

      this->ledState = LOW;
      this->previousMillis = 0;
    }

    void Update()
    {
      unsigned long currentMillis = millis();

      if ((this->ledState == HIGH) && (currentMillis - this->previousMillis >= OnTime))
      {
        this->ledState = LOW; 
        this->previousMillis = currentMillis; 
        digitalWrite(this->ledPin, this->ledState);
      }
      else if ((this->ledState == LOW) && (currentMillis - this->previousMillis >= this->OffTime))
      {
        this->ledState = HIGH;
        this->previousMillis = currentMillis; 
        digitalWrite(this->ledPin, this->ledState);
      }
    }
};
