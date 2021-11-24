#define Timer_INDEFINITE -1
#define Timer_UNLIMITED -1



class Timer{
	public:
	Timer();
	Timer(unsigned long _t);    
	~Timer();            

	void init();          
	bool done();       
	bool repeat(int times);
	bool repeat(int times, unsigned long _t);
	bool repeat();
	void repeatReset();
	bool waiting();	
	bool started();	
	void start();			
	unsigned long stop();	
	unsigned long getElapsed();
	void restart();
	void reset();       
	void set(unsigned long t);
	unsigned long get();
	bool debounce(bool signal);
	int repetitions = Timer_UNLIMITED;

	private:

	struct myTimer{
		unsigned long time;
		unsigned long last;
		bool done;
		bool started;
	};

	struct myTimer _Timer;
	bool _waiting;
};

Timer::Timer(){
	this->_Timer.time = 1000;
}

Timer::Timer(unsigned long _t){
  this->_Timer.time = _t;
}

Timer::~Timer(){

}

void Timer::init(){
  this->_waiting = false;
}


bool Timer::repeat(int times){
	if(times != Timer_UNLIMITED){
		if(this->repetitions == Timer_UNLIMITED){
			this->repetitions = times;
		}
		if(this->repetitions == 0){
			return false;
		}

		if(this->repeat()){
			this->repetitions--;
			return true;
		}
		return false;
	}
	return this->repeat();
}


bool Timer::repeat(int times, unsigned long _t){
	this->_Timer.time = _t;
	return this->repeat(times);
}


bool Timer::repeat(){
  if(this->done()){
    this->reset();
    return true;
  }
	if(!this->_Timer.started){
		this->_Timer.last = millis();
		this->_Timer.started = true;
    this->_waiting = true;
  }
  return false;
}

void Timer::repeatReset(){
	this->repetitions = -1;
}

bool Timer::done(){
  if(!this->_Timer.started) return false;
  if( (millis()-this->_Timer.last) >= this->_Timer.time){
    this->_Timer.done = true;
    this->_waiting = false;
    return true;
  }
  return false;
}


void Timer::set(unsigned long t){
  this->_Timer.time = t;
}


unsigned long Timer::get(){
	return this->_Timer.time;
}


bool Timer::debounce(bool signal){
	if(this->done() && signal){
		this->start();
		return true;
	}
	return false;
}


void Timer::reset(){
  this->stop();
  this->_Timer.last = millis();
  this->_Timer.done = false;
}


void Timer::start(){
	this->reset();
  this->_Timer.started = true;
  this->_waiting = true;
}



unsigned long Timer::stop(){
  this->_Timer.started = false;
  this->_waiting = false;
  return this->getElapsed();
}


unsigned long Timer::getElapsed(){
  return millis()-this->_Timer.last;
}


void Timer::restart(){
	if(!this->done()){
		this->_Timer.started = true;
		this->_waiting = true;
	}
}


bool Timer::waiting(){
  return (this->_Timer.started && !this->done()) ? true : false;
}

bool Timer::started(){
	return this->_Timer.started;
}
