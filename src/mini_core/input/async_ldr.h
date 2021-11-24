class LDR {
  private:
    enum LdrStatus {
      LOW_LIGHT = 1,
        MID_LIGHT = 2,
        HIGH_LIGHT = 3,
    };
  int LdrStatus;
  int ldr_pin;
  int LdrReading;
  public:
    int Read(int ldr_pin) {
      LdrReading = analogRead(ldr_pin);
      if (LdrReading < 500) {
        LdrStatus = LOW_LIGHT;
      } else if (LdrReading > 500) {
        LdrStatus = MID_LIGHT;
      } else if (LdrReading > 800) {
        LdrStatus = HIGH_LIGHT;
      }
      return LdrStatus;
    }
};
