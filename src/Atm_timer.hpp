#pragma once

#include <Automaton.h>

class Atm_timer : public Machine {
 public:
  Atm_timer( void ) : Machine(){};

  atm_timer_millis daytimer, mstimer;
  atm_counter daycounter, repcounter;
  uint16_t days;
  uint16_t repeat_cnt;
  atm_connector _ontimer, _onfinish;

  enum { IDLE, START, WAITD, WAITMS, TRIGGER, FINISH };
  enum { EVT_DAYCNT, EVT_DAYTIMER, EVT_MSTIMER, EVT_REPCNT, EVT_STOP, EVT_START, ELSE };
  enum { ACT_START, ACT_TRIGGER, ACT_WAITD, ACT_FINISH };

  Atm_timer& begin( uint32_t ms = 0, uint16_t repeats = 1 );
  Atm_timer& trace( Stream& stream );
  Atm_timer& onTimer( atm_cb_t callback, int idx = 0 );
  Atm_timer& onTimer( Machine& machine, int event = 0 );
  Atm_timer& onFinish( atm_cb_t callback, int idx = 0 );
  Atm_timer& onFinish( Machine& machine, int event = 0 );
  Atm_timer& interval_seconds( uint32_t v );
  Atm_timer& interval_millis( uint32_t v );
  Atm_timer& interval( uint32_t v );
  Atm_timer& repeat( uint16_t v );
  int event( int id );
  void action( int id );
};