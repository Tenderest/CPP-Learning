// tvfm.h -- Tv and Remote classes using a friend member
#ifndef TVFM_H_
#define TVFM_H_

class Tv; // forward declaration 向前声明，前置声明

class Remote
{
public:
	enum State{Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};
private:
	int mode; // controls TV or DVD 控制电视或DVD
public:
	Remote (int m = TV) : mode(m) {}
	bool volup (Tv & t);
	bool voldown (Tv & t);
	void onoff (Tv & t);
	void chanup (Tv & t);
	void chandown (Tv & t);
	void set_mode (Tv & t); 
	void set_input (Tv & t);
        void set_chan (Tv & t, int c);
};




class Tv
{
public:
        friend void Remote::set_chan (Tv & t, int c);
	enum State{Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv (int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff () {state = (state == On) ? Off : On;}
	bool ison () const {return state == On;}
	bool volup ();
	bool voldown ();
	void chanup ();
	void chandown ();
	void set_mode () {mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input () {input = (input == TV) ? DVD : TV;}
	void settings () const; // display all settings 显示所有设置
private:
	int state;      // on or off 开或关
	int volume;     // assumed to be digitized 假设是数字化的
	int maxchannel; // maximum number of channels 最大通道数
	int channel;    // current channel setting 当前频道设置
	int mode;       // broadcast or cable 广播或有线
	int input;      // TV or DVD 电视或DVD
};


// Remote methods as inline functions Remote方法作为内联函数
inline bool Remote::volup (Tv & t) {return t.volup();}
inline bool Remote::voldown (Tv & t) {return t.voldown();}
inline void Remote::onoff (Tv & t) {t.onoff();}
inline void Remote::chanup (Tv & t) {t.chanup();}
inline void Remote::chandown (Tv & t) {t.chandown();}
inline void Remote::set_mode (Tv & t) {t.set_mode();}
inline void Remote::set_input (Tv & t) {t.set_input();}
inline void Remote::set_chan (Tv & t, int c) {t.channel = c;}


#endif
