#include <stdio.h>

typedef enum
{
    DEVICE_OFF,
    DEVICE_ON,
    DEVICE_ERROR
} DeviceStatus;

typedef struct
{
    int id;
    char name[50];
    DeviceStatus status;
} Device;

int main(void)
{
    Device device = {101, "Sensor", DEVICE_ON};

    printf("Device ID: %d\n", device.id);
    printf("Device Name: %s\n", device.name);

    if (device.status == DEVICE_ON)
    {
        printf("Device is ON.\n");
    }
    else if (device.status == DEVICE_OFF)
    {
        printf("Device is OFF.\n");
    }
    else
    {
        printf("Device has an error.\n");
    }

    return 0;
}
