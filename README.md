> Epitech Project 2021/2022 <br>
> B2 - Unix System Programming<br>
> B-PSU-200

# Navy
#### You sunk my battleship!

### Coding Style
- style mark: 1<br>
- style major: 0
- style minor: 1
- style info: 0
<br>

### Note : 72.1%
- 01: 1/1
- 02: 2/2
- 02: 6/8 - 2 crash
- 03: 6/8 - 2 crash
- 04: 4/4
- 05: 4/4
- 06: 4/8
- 07: 4/8

### Coverage: 0%
<br>

### Content
**binary name**: navy<br>
**language**: C<br>
**build tool**: via Makefile, including re, all, clean, fclean rules
<br>

### Authorized Functions
open, close, read, write, lseek, malloc, free, getpid, kill, signal, sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause, getline, fopen, fclose
<br>
**Any unspecified functions are de facto banned**

### Goal
You all know the very famous Battleship game. Well, I hope so.
You must code a terminal version of this game.
The two players are ONLY allowed to comunicate using the signals SIGUSER1 and SIGUSER2.
The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions.
At the end of the game (when all the ships of a player have
been hit), you must display whether “I won” (and return 0) or
“Enemy won” (and return 1).
<br>
```sh
∼/B-PSU-200> ./navy -h
USAGE
    ./navy [first_player_pid] navy_positions
DESCRIPTION
    first_player_pid: only for the 2nd player. pid of the first player.
    navy_positions: file representing the positions of the ships.
```
The file passed as parameter must contain lines formatted the following way:<br>
LENGTH : FIRST_SQUARE : LAST_SQUARE<br>
where LENGTH is the length of the ship, FIRST_SQUARE and LAST_SQUARE its first and last positions.<br>
In this file, you must have 4 ships (of lengths 2,3,4 and 5).<br>
If the navy file is invalid, you have to quit the program and consider it as an error.


<br><br>

>- **Student:** Adrien VERMERSCH / Edouard CHHANG
>-  **Email:** adrien.vermersch@epitech.eu / edouard.chhang@epitech.eu
>- **Year:** 2021
>- **Promotion:** 2026
>- **Campus:** Bordeaux

Code rédigé selon la norme Epitech (promo 2026).<br><br>
Recopier ce repo revient au vol de code.<br>
Autrement dit, -42<br><br>
