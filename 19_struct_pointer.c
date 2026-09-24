#include <stdio.h>

struct Device
{
    int id;
    char name[50];
    int status;
};

int main(void)
{
    struct Device device = {101, "Sensor", 1};

    struct Device *ptr = &device;

    printf("Device ID: %d\n", ptr->id);
    printf("Device Name: %s\n", ptr->name);
    printf("Device Status: %d\n", ptr->status);

    ptr->status = 0;

    printf("\nAfter updating status:\n");
    printf("Device Status: %d\n", ptr->status);

    return 0;
}
