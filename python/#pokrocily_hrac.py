#pokrocily_hrac
import random
class MyPlayer:

    trest_svedcit1 = 0
    trest_svedcit2 = 0
    trest_nesvedcit1 = 0
    trest_nesvedcit2 = 0

    """
    Toto je popisny retezec
    hrac si vypocita prumer trestu pokud by svedcil a pokud by nesvedcil
    zvoli taktiku, kde je prumer mensi tudiz vetsi pravdepodobnost nizkeho trestu
    """

    def __init__(self, payoff_matrix, number_of_iterations=None):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations or 10

    
        
    def move(self):
        
        trest_svedcit1 = self.payoff_matrix[0][0][0]
        trest_svedcit2 = self.payoff_matrix[0][1][0]
        trest_nesvedcit1 = self.payoff_matrix[1][0][0]
        trest_nesvedcit2 = self.payoff_matrix[1][1][0]
        """"
        print(trest_svedcit1)
        print(trest_svedcit2)
        print(trest_nesvedcit1)
        print(trest_nesvedcit2)
        """""
        if(trest_svedcit1 + trest_svedcit2)/2 < (trest_nesvedcit1 + trest_nesvedcit2)/2:
            return True
        return False
        
        
    def record_last_moves(self, my_last_move, opponent_last_move):
        self.my_last_move = my_last_move
        self.opponent_last_move = opponent_last_move

if __name__ == "__main__":
    hrac = MyPlayer( payoff_matrix=(((4,4),(1,6)) , ((6,1),(2,2))) )
    print(hrac.move())