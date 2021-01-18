import os


os.system('.\data2.exe')
os.system('.\sol.exe')
os.system('.\compare.exe')

f = open("output.txt", "r")
g = open("output2.txt", "r")

tmp = f.read()
tmp2 = g.read()

ln = tmp.split('\n')[0].split(' ')
ln2 = tmp2.split('\n')[0].split(' ')

print(ln)
print(ln2)
same = True
if(len(ln) == len(ln2)):
    for i in range(0, len(ln)):
        if(int(ln[i]) != int(ln2[i])):
            same = False
else:
    same = False
if same == False:
    print("not the same")
else:
    print("the same")
f.close()
g.close()