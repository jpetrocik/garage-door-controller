#ifndef LIGHT_H
#define LIGHT_H

enum RELAY_STATE { RELAY_OPEN, RELAY_CLOSED};

void toogleRelay();
void openRelay();
void closeRelay();
RELAY_STATE relayState();

#endif