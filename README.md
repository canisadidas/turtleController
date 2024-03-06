# turtleController

turtleController is arduino based controller for terrariums and aquaterrariums

## Setting

Set relay ports if using different

    #define UVrelay 4
    #define IKrelay 5

Time and date will set automatically
    
Set working period

    #define uvOnHour 7
    #define uvOffHour 13
    #define ikOnHour 7
    #define ikOffHour 21

## List of components

| id |       name      | pcs |
|:--:|:---------------:|:---:|
| 1  | Arduino Nano v3 | 1   |
| 2  | DS3231          | 1   |
| 3  | KY-019          | 2   |
| 4  | Power unit 5V   | 1   |

## Scheme

![scheme](./schemas/Schematic_turtleController_2022-12-10.png)
