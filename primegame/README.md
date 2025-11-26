<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Requirements

## Table of Contents :

  - [0. Prime Game](#subparagraph0)

## Requirements
### General
* Allowed editors:vi,vim,emacs
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS usingpython3(version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly#!/usr/bin/python3
* AREADME.mdfile, at the root of the folder of the project, is mandatory
* Your code should use thePEP 8style (version 1.7.x)
* All your files must be executable

## Task
### 0. Prime Game <a name='subparagraph0'></a>

Maria and Ben are playing a game. Given a set of consecutive integers starting from <code>1</code> up to and including <code>n</code>, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

They play <code>x</code> rounds of the game, where <code>n</code> may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.

* Prototype: <code>def isWinner(x, nums)</code>
* where <code>x</code> is the number of rounds and <code>nums</code> is an array of <code>n</code>
* Return: name of the player that won the most rounds
* If the winner cannot be determined, return <code>None</code>
* You can assume <code>n</code> and <code>x</code> will not be larger than 10000
* You cannot import any packages in this task

Example:

* <code>x</code> = <code>3</code>, <code>nums</code> = <code>[4, 5, 1]</code>

First round: <code>4</code>

* Maria picks 2 and removes 2, 4, leaving 1, 3
* Ben picks 3 and removes 3, leaving 1
* Ben wins because there are no prime numbers left for Maria to choose

Second round: <code>5</code>

* Maria picks 2 and removes 2, 4, leaving 1, 3, 5
* Ben picks 3 and removes 3, leaving 1, 5
* Maria picks 5 and removes 5, leaving 1
* Maria wins because there are no prime numbers left for Ben to choose

Third round: <code>1</code>

* Ben wins because there are no prime numbers for Maria to choose

<strong>Result: Ben has the most wins</strong>

```
carrie@ubuntu:~/primegame$ cat main_0.py
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

carrie@ubuntu:~/primegame$
```

```
carrie@ubuntu:~/primegame$ ./main_0.py
Winner: Ben
carrie@ubuntu:~/primegame$
```

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
