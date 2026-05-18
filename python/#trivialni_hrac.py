#trivialni_hrac
import random
class MyPlayer:

    """
    Toto je popisny retezec
    """

    def __init__(self, payoff_matrix, number_of_iterations=None):
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations or 10

    
        
    def move(self):
        tah = random.randint(0,1)
        if tah == 0:
            return True
        elif tah == 1:
            return False
        
    def record_last_moves(self, my_last_move, opponent_last_move):
        self.my_last_move = my_last_move
        self.opponent_last_move = opponent_last_move