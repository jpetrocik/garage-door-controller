#include <Arduino.h>
#include "configuration.h"
#include "relay.h"

void operateDoor()
{
    digitalWrite(RELAY_PIN, RELAY_CLOSED);
    delay(1000);
    digitalWrite(RELAY_PIN, RELAY_OPEN);
}

void toogleRelay()
{
    RELAY_STATE currentRelayState = relayState();
    if (currentRelayState == RELAY_CLOSED)
    {
        openRelay();
    }
    else
    {
        closeRelay();
    }
}

void openRelay()
{
    RELAY_STATE currentRelayState = relayState();
    if (currentRelayState == RELAY_OPEN)
        return;

    operateDoor();
}

void closeRelay()
{
    RELAY_STATE currentRelayState = relayState();
    if (currentRelayState == RELAY_CLOSED)
        return;

    operateDoor();
}

RELAY_STATE relayState()
{
    return (RELAY_STATE)digitalRead(RELAY_PIN);
}
