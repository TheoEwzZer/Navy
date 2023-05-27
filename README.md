# navy

You all know the very famous Battleship game. Well, I hope so.
You must code a terminal version of this game using signals.
The two players are ONLY allowed to communicate using the signals SIGUSER1 and SIGUSER.

The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions.

At the end of the game (when all the ships of a player have been hit), you must display whether “I won” (and return 0) or “Enemy won” (and return 1).

```text
∼/B-PSU-100> ./navy -h
USAGE
./navy [first_player_pid] navy_positions
DESCRIPTION
first_player_pid: only for the 2nd player. pid of the first player.
navy_positions: file representing the positions of the ships.
```

The file passed as parameter must contain lines formatted the following way:

LENGTH : FIRST_SQUARE : LAST_SQUARE

where LENGTH is the length of the ship, FIRST_SQUARE and LAST_SQUARE its first and last positions.
In this file, you must have 4 ships (of lengths 2,3,4 and 5).
If the navy file is invalid, you have to quit the program and consider it as an error.

```text
Authorized functions : open, close, read, write, lseek, malloc, free, getpid, kill, signal,
sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause, getline, fopen,
fclose, fseek, memset, memcpy
```

```text
You are allowed to use one (and only one) global variable, if you can justify it.
```

## EXAMPLE

```text
The display must be EXACTLY the same as the one below.
```

Here is an example game.

```text
∼/B-PSU-100> cat pos
2:C1:C
3:D4:F
4:B5:B
5:D7:H
```

```text
∼/B-PSU-100> cat pos
2:C4:D
3:H1:H
4:E6:H
5:B1:F
```

### CONNECTION

Player 1

```text
∼/B-PSU-100> ./navy pos
my_pid: 4242
waiting for enemy connection...

enemy connected
```

Player 2

```text
∼/B-PSU-100> ./navy 4242 pos
my_pid: 4250
successfully connected
```

### TURN #1

Player 1

```text
my positions:
|A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: Z
wrong position
attack: B
B6: missed
```

Player 2

```text
my positions:
|A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . . . . . . 3
3|. . . . . . . 3
4|. . 2 2 . . . .
5|. . . . . . . .
6|. . . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy’s attack...
B6: missed

attack: 4
wrong position
attack: C
C1: hit
```

### TURN #2

Player 1

```text
my positions:
|A B C D E F G H
-+---------------
1|. . x . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. o . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: C
C4: hit

waiting for enemy’s attack...
D1: missed
```

Player 2

```text
my positions:
|A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . . . . . . 3
3|. . . . . . . 3
4|. . . . . . . .
5|. . 2 2 . . . .
6|. o . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . x . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy’s attack...
C4: hit

attack: D
D1: missed
```

Etc.

### LAST TURN

Player 1

```text
attack: H
H6: hit

my positions:
|A B C D E F G H
-+---------------
1|o . x o . o . o
2|. . 2 . . o . .
3|. o . . o . . .
4|. . . x x o . .
5|. x o . . o o .
6|. o . . . . . .
7|o o . x x x 5 5
8|. o . o . o . o

enemy’s positions:
|A B C D E F G H
-+---------------
1|. x x x x o . x
2|. . . o . o . x
3|. o . . . . o x
4|. . x x o . . o
5|. . . . . o . .
6|. o . . x x x x
7|. . o . . . o .
8|. . . . . o . .

I won
```

Player 2

```text
waiting for enemy’s attack...
H6: hit

my positions:
|A B C D E F G H
-+---------------
1|. x x x x o . x
2|. . . o . o . x
3|. o . . . . o x
4|. . x x o . . o
5|. . . . . o . .
6|. o . . x x x x
7|. . o . . . o .
8|. . . . . o . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|o . x o . o . o
2|. . . . . o . .
3|. o . . o . . .
4|. . . x x o . .
5|. x o . . o o .
6|. o . . . . . .
7|o o . x x o . .
8|. o . o . o . o

Enemy won
```

## BONUS

```text
You have to make the mandatory part before adding bonus!
```

Here are some example of bonus:

- play against an AI,
- a nice interface, music,
- multiplayer mode with more than 2 players,
- customize game,
- networking,
- and whatever you feel like.

## FINAL MARK

### Mark: 23 / 23 (100.0%)

- cheater (1 / 1)
- basic signal (2 / 2)
- rigor (8 / 8)
- protocol (4 / 4)
- game (8 / 8)
