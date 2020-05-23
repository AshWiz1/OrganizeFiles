import os
from os.path import isfile,join,splitext
import shutil
import sys

#shutil.move("C:\\Users\\ashrith\\Desktop\\pythonproje\\MEFA-Notes.pdf","C:\\Users\\ashrith\\Desktop\\pythonproje\\testomg\\MEFA-Notes.pdf")

path = "C:/Users/ashrith/Desktop/pythonproje/organizefiles/testingorg/"
lis = os.listdir(path)


files = [x for x in lis if(isfile(join(path,x)))]
dirs = [x for x  in lis if(not isfile(join(path,x)))]
mapp = {}

#print(files)
#print(dirs)

for str in files:
    temp1,temp2 = splitext(str)
    if temp2[1:] not in dirs :    
        #print(temp2[1:],"\n")
        try: 
            os.mkdir(join(path,temp2[1:]))
        except FileExistsError : 
            continue
        dirs.append(temp2[1:])
    if mapp.get(temp2[1:]) == None : 
        mapp[temp2[1:]] = []
    mapp[temp2[1:]].append(str)

#print(files)
#print(dirs)

for folder_name,list_of_files in mapp.items():
    for file in list_of_files :
        shutil.move(path+file, path+folder_name + "/" + file)





