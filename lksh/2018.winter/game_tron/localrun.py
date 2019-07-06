#!/usr/bin/python3

import os, os.path
import json
import subprocess, shutil
import traceback
import sys

import enum

def check(b, msg):
    if not b:
        print(msg)
        sys.exit(1)

class Player(enum.IntEnum):
    RED = 0
    BLUE = 1
    NOBODY = -1

    def other(self):
        return Player(1 - self.value)

class Game:
    # field is 2d array of bool
    def __init__(self, field, px, py, qx, qy):
        self._turn = Player.RED
        self._win_player = Player.NOBODY
        self._board = field

        self._dim = (len(field), len(field[0]))
        
        self._red = (px, py)
        self._blue = (qx, qy)

        if not self.pos_valid(px, py):
            raise ValueError("px, py are not valid")
        if not self.pos_valid(qx, qy):
            raise ValueError("qx, qy are not valid")

        if (px, py) == (qx, qy):
            raise ValueError("positions of both players are equal")
        
        self._board[px][py] = True
        self._board[qx][qy] = True
        self._colorboard = [['N' for i in range(self._dim[0])] for j in range(self._dim[1])]

    def turn(self):
        return self._turn

    def pos_valid(self, x, y):
        return 0 <= x < self._dim[0] and 0 <= y < self._dim[1] and not self._board[x][y] == True

    def get_moves(self):
        dr = [(-1, 0), (+1, 0), (0, -1), (0, +1)]
                
        (x, y) = (self._red if self._turn == Player.RED else self._blue)

        for (dx, dy) in dr:
            if self.pos_valid(x + dx, y + dy):
                yield (x + dx, y + dy)
    
    def has_move(self):
        for _ in self.get_moves():
            return True
        return False
        
    def check_move(self, nx, ny):
        for (a, b) in self.get_moves():
            if (a, b) == (nx, ny):
                return True
        return False

    def move(self, nx, ny):
        if not self.check_move(nx, ny):
            self.declare_lose()
            raise ValueError("Bad move")

        self._colorboard[nx][ny] = ('R' if self._turn == Player.RED else 'B')
        self._board[nx][ny] = True
        if self._turn == Player.RED:
            self._red = (nx, ny)
        else:
            self._blue = (nx, ny)

        self._turn = self._turn.other()

    def declare_lose(self):
        self._win_player = self._turn.other()
        self._turn == Player.NOBODY

    def winner(self):
        return Player(self._win_player)

    def describe(self, who):
        ret = "{} {}\n".format(self._dim[0], self._dim[1])
        
        for i in range(self._dim[0]):
            line = ""
            for j in range(self._dim[1]):
                player = Player.NOBODY
                
                if self._red == (i, j):
                    player = Player.RED
                if self._blue == (i, j):
                    player = Player.BLUE

                if player == who:
                    line = line + "+"
                elif player == who.other():
                    line = line + 'x'
                elif self._board[i][j] == True:
                    line = line + "#"
                else:
                    line = line + "."
            ret = ret + line + "\n"

        return ret

    def describe_nice(self):
        field = ""
        for i in range(self._dim[0]):
            line = ""
            for j in range(self._dim[1]):
                if self._board[i][j] == True:
                    line = line + self._colorboard[i][j]
                elif (i, j) == self._red:
                    line = line + "1"
                elif (i, j) == self._blue:
                    line = line + "2"
                else:
                    line = line + "."
            field = field + line
        return {"dim": self._dim, "field": field}
    
def main():
    verbose = False
    if len(sys.argv) >= 2 and sys.argv[1] == "--verbose":
        verbose = True
        sys.argv = sys.argv[:1] + sys.argv[2:]
    
    check(len(sys.argv) == 3, "usage: " + sys.argv[0] + " [--verbose] player1 player2")

    pp = [None, None]
    
    if sys.argv[1] != "-":
        pp[0] = subprocess.Popen(sys.argv[1], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

    if sys.argv[2] != "-":
        pp[1] = subprocess.Popen(sys.argv[2], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

    # 10x10 empty field
    game = Game([[False for i in range(10)] for j in range(10)], 0, 0, 9, 9)
    while True:
        if game.winner() != Player.NOBODY:
            break

        if not game.has_move():
            game.declare_lose()
            break
        
        field = game.describe(game.turn())

        if verbose:
            print("Now playing: {}".format(game.turn().name))
            print("Field before")
            print(field, end="")

        def read_move(pps):
            if pps == None:
                (a, b) = (-1, -1)
                while not game.check_move(a, b):
                    mv = input("Enter your move (WASD): ").strip()
                    if not mv in ["W", "A", "S", "D"]:
                        continue
                    
                    (dx, dy) = {"W": (-1, 0), "A": (0, -1), "S": (+1, 0), "D": (0, +1)}[mv]

                    (x, y) = game._red if game.turn() == Player.RED else game._blue

                    (a, b) = (x + dx, y + dy)
                return (a, b)
            else:
                pps.stdin.write(field)
                pps.stdin.flush()
                return map(int, pps.stdout.readline().strip().split())

        (a, b) = read_move(pp[game.turn()])
        
        if verbose:
            print ("Moving to {} {}".format(str(a), str(b)))
        
        try:
            game.move(a, b)
        except:
            print("Epic fail, it was a bad move")

    print(game.describe(Player.RED))
    print("Game over")
    print("Congratulations to {}".format(game.winner().name))
    
    for i in range(2):
        if pp[i] != None:
            try:
                pp[i].kill()
            except:
                pass    
    

if __name__ == "__main__":
    main()
