#ifndef DOOR_H
#define DOOR_H

enum DOOR_STATE { DOOR_OPENED, DOOR_CLOSED};

void toogleDoor();
void openDoor();
void closeDoor();
DOOR_STATE doorState();

#endif