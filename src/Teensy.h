#define pb1 0
#define ldr_pin A10


Timer mytimer = Timer(1000);
Debouncer db1;
LDR ldr1;

void init() {
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(13, OUTPUT);
  db1.begin(pb1);
  mytimer.start();
}

Flasher led1(14, 100);
Flasher led2(15, 50);

void loop() {

  led1.OnTime = 200;
  led1.Update();
  led2.OnTime = 50;
  led2.Update();

  if (mytimer.done()) {
    mytimer.repeatReset();
  }

  if (mytimer.waiting()) {}

  if (db1.debounce()) {
    digitalWriteFast(1, !digitalReadFast(1));
  }

  Serial.println(ldr1.Read(ldr_pin));

}
