#turnaj_test

class MyPlayer:
    COOPERATE = False
    DEFECT = True 

    def __init__(self, payoff_matrix, number_of_iterations=None):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations or 1
        self.my_last_move = None
        self.opponent_last_move = None
        
        # Zde můžeme provést analýzu matice odměn, pokud je tato analýza statická.
        self.zisk_svedcit1 = self.payoff_matrix[MyPlayer.COOPERATE][MyPlayer.COOPERATE][0]
        self.zisk_svedcit2 = self.payoff_matrix[MyPlayer.COOPERATE][MyPlayer.DEFECT][0]
        self.zisk_spolupracovat1 = self.payoff_matrix[MyPlayer.DEFECT][MyPlayer.COOPERATE][0]
        self.zisk_spolupracovat2 = self.payoff_matrix[MyPlayer.DEFECT][MyPlayer.DEFECT][0]
   
    def move(self):
        if (self.zisk_svedcit1 + self.zisk_svedcit2) / 2 > (self.zisk_spolupracovat1 + self.zisk_spolupracovat2) / 2:
            return MyPlayer.COOPERATE
        return MyPlayer.DEFECT
               
    def record_last_moves(self, my_last_move, opponent_last_move):
        self.my_last_move = my_last_move
        self.opponent_last_move = opponent_last_move

if __name__ == "__main__":
    hrac = MyPlayer( payoff_matrix=(((4,4),(1,6)) , ((6,1),(2,2))) )
    print(hrac.move())

#:"|}||||||||"