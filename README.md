Fairly self explanatory. It allows you to pick a class by number (1-12), generates stats, allows you to choose which roll goes to which
stat, then automatically calculates HP and saves, and writes it to ~/Characters/.

I used CMake, sorry if it doesn't work with something else, but at this point I've remade it like 8 times. For windows, you might need 
to change it so it adds "\Characters\" to the mkdir string instead of "/Characters/".
