class Debouncer
{
  private:
    uint8_t btn;
    uint16_t state;
  public:
    void begin(uint8_t button) {
      this->btn = button;
      this->state = 0;
      pinMode(this->btn, INPUT_PULLUP);
    }
    bool debounce() {
      this->state = (this->state << 1) | digitalRead(this->btn) | 0xfe00;
      return (this->state == 0xff00);
    }
};