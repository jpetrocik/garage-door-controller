#ifndef DOOR_H
#define DOOR_H

enum DOOR_STATE { DOOR_CLOSED, DOOR_OPENED};

void toogleDoor();
void openDoor();
void closeDoor();
DOOR_STATE doorState();

#endif