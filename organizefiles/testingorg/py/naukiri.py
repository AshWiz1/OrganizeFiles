#!/usr/bin/env python
# coding: utf-8

# In[107]:


import spacy
import pandas
with open("job_data.txt", "r",encoding="utf-8") as f:
    role = f.read()
jobs = role.split("---------------------------------------------------------------------------------------------------------------------------------------")
print(len(jobs))

#for i in jobs:
    #print("--->",repr(i))
    
rol = []
with open("tech_skills.txt", "r",encoding="utf-8") as f:
    role = f.readline()
    while role:
        role = f.readline()
        rol.append(role)
rol = [role.strip("\n") for role in rol]
rol = rol[0:-2]
#print(rol) 
    
#extracting roles->list from jobs list->list
roles = []
for i in jobs : 
    index = i.find("Role:")
    index_end = i.index('\n',index)
    if index >= 0 :
        roles.append(i[index+5:index_end])
print(len(jobs))


# In[103]:


skills = []
count = 0
for i in jobs:
    #print(count)
    count =count+1
    #print("->>>",count)
    str = ""
    inde = i.find("Keyskills")
    if inde >= 0:
        index_end = i.find("\n",inde)
        str =i[index_end+1:]
        str = " "+str+" "
        skills_list = "."
        for j in rol:
            if (" "+j+" ").lower() in str.lower():
                skills_list = "."+j+skills_list
        #print(str)
    skills.append(skills_list)
print(skills,"  ",len(skills))

