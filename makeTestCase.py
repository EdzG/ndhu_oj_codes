import random
n = random.randrange(5, 26)
print(n)
for i in range(15):
    pile1 = random.random() < 0.5
    pile2 = random.random() < 0.5
    onto = random.random() < 0.5
    
    instr = []
    instr.append("pile" if pile1 else "move")
    instr.append(str(random.randrange(0,n)))
    
    instr.append("onto" if onto else "over")
    instr.append("pile" if pile2 else "")
    instr.append(str(random.randrange(0,n)))
    
    print(" ".join(instr))
    
print("quit")