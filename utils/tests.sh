# Bad argument
echo "\e[1;33m### BAD ARGUMENT ###\e[0m"
./so_long
./so_long ''
./so_long 'assets/maps/map_first.ber' -1
./so_long 'assets/maps/map_first.ber' 5
./so_long 'assets/maps/map_first.ber' abcd
echo "\n"

# Map not closed
echo "\e[1;33m### MAP NOT CLOSED ###\e[0m"
./so_long 'assets/maps/tests/map_00_no_wall.ber' 2
./so_long 'assets/maps/tests/map_01_no_wall_up.ber' 2
./so_long 'assets/maps/tests/map_02_no_wall_down.ber' 2
./so_long 'assets/maps/tests/map_03_no_wall_left.ber' 2
./so_long 'assets/maps/tests/map_04_no_wall_right.ber' 2
echo "\n"

# Map not egal to 1 exit
echo "\e[1;33m### MAP NOT EGAL TO 1 EXIT ###\e[0m"
./so_long 'assets/maps/tests/map_05_no_exit.ber' 2
./so_long 'assets/maps/tests/map_06_two_exit.ber' 2
echo "\n"

# Map more than zero item
echo "\e[1;33m### MAP MORE THAN ZERO ITEM ###\e[0m"
./so_long 'assets/maps/tests/map_07_no_item.ber' 2
echo "\n"

# Map not egal to 1 player
echo "\e[1;33m### MAP NOT EGAL TO 1 PLAYER ###\e[0m"
./so_long 'assets/maps/tests/map_08_no_player.ber' 2
./so_long 'assets/maps/tests/map_09_two_player.ber' 2
echo "\n"

# Map is not rectangle
echo "\e[1;33m### MAP IS NOT RECTANGLE ###\e[0m"
./so_long 'assets/maps/tests/map_10_not_rectangle.ber' 2
echo "\n"

# map empty or lot of space
echo "\e[1;33m### MAP EMPTY OR LOT OF SPACE ###\e[0m"
./so_long 'assets/maps/tests/map_11_empty.ber' 2
./so_long 'assets/maps/tests/map_12_lot_of_space.ber' 2
echo "\n"

# invalid character in map
echo "\e[1;33m### INVALID CHARACTER IN MAP ###\e[0m"
./so_long 'assets/maps/tests/map_13_invalid_character.ber' 2
echo "\n"

# item not accessible
echo "\e[1;33m### ITEM NOT ACCESSIBLE ###\e[0m"
./so_long 'assets/maps/tests/map_14_item_not_accessible.ber' 2
echo "\n"

# map wrong width
echo "\e[1;33m### MAP WRONG WIDTH ###\e[0m"
./so_long 'assets/maps/tests/map_15_map_wrong_width.ber' 2
echo "\n"
