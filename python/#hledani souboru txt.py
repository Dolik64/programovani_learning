#hledani souboru txt

from pathlib import Path
import readline

filename = Path("~/Users/jirka/Documents/zasilkovna.txt")

lines=[]

#seznam = []

for line in filename:
     lines.append(line.strip())


print(lines)


#Lines = filename.readlines()

#Lines = filename.read()

#print(Lines)

#print(filename.name)