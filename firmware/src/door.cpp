#include <Arduino.h>
#include "configuration.h"
#include "door.h"

void operateDoor()
{
    digitalWrite(RELAY_PIN, RELAY_CLOSE);
    delay(1000);
    digitalWrite(RELAY_PIN, RELAY_OPEN);
}

void toogleDoor()
{
    DOOR_STATE currentDoorState = doorState();
    if (currentDoorState == DOOR_CLOSED)
    {
        openDoor();
    }
    else
    {
        closeDoor();
    }
}

void openDoor()
{
    DOOR_STATE currentDoorState = doorState();
    if (currentDoorState == DOOR_OPENED)
        return;

    operateDoor();
}

void closeDoor()
{
    DOOR_STATE currentDoorState = doorState();
    if (currentDoorState == DOOR_CLOSED)
        return;

    operateDoor();
}

DOOR_STATE doorState()
{
    return (DOOR_STATE)digitalRead(DOOR_STATUS_PIN);
}
