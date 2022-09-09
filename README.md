# so_long

## Table of Contents
- [Description](#Description)
- [Start && End](#Start-&&-End)
- [Rules](#Rules)
- [Mapfile feature](#Mapfile-feature)

## <a name="Description"></a>Description
This is a small 2D game for MAC OS in which the main goal of the player is to collect all the items and escape through the exit. The project was coded to get familiar with the mlx library and UI in general.<br />
External functions:
- open, close, read, write,
malloc, free, perror,
strerror, exit
- All functions of the math
library
- All functions of the MiniLibX
- ft_printf and any equivalent
I coded <br />
Bonus part:<br />
- The player lose when they touch an enemy patrol.
- Added some sprite animation.
- The movement count displayed directly on screen instead of writing it in the shell.

![](https://user-images.githubusercontent.com/89844627/170445885-a2af5b67-64a5-4f65-abef-c4c3026609e4.jpg)
![so_long_bonus](https://user-images.githubusercontent.com/89844627/170444402-987c1f16-1408-491f-9ec9-afba105f1ef8.jpg)


## <a name="Start-&&-End"></a>Start && End
To compile the program, run the following command:
```
cd so_long && make
./so_long maps/map.ber
```
The program takes as parameter a map description file which ends with the `.ber` extension.<br />
Clicking on the cross on the window’s frame or pressing ESC closes the window and quit the program in a clean way.

## <a name="Rules"></a>Rules
- The `W`, `A`, `S`, `D` keys are used to control the main character.
- The player can't escape until all items are not collected.
- At every move, the current number of movements will be displayed in the shell.

## <a name="Mapfile-feature"></a>Mapfile feature
You can create yout own map. For this you should follow this instructions:
- Your file format still must be `.ber`.
- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map must contain at least 1 exit, 1 collectible, and 1 starting position.
- The map can be composed of only these 5 characters:<br />
  0 for an empty space,<br />
  1 for a wall,<br />
  C for a collectible,<br />
  E for a map exit,<br />
  P for the player’s starting position.<br />
- The map must be rectangular.
- The map must be surrounded by walls.<br />

In folder [maps](https://github.com/urycherd/so_long/tree/master/maps) you can find some examples of maps.
