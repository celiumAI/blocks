# blocks

the first product demo of celium 

it physically lets you play with language models

its an esp8266 with an optional oled display that has its own personality

it has a mailbox and its own little code sandbox and access to information is distributed by managers

it is a completely embedded network with a soft access point providing certifiably encrypted traffic

## what it does

it will help understand how anything works.

and i will show how it helps to understand that using this product itself.

but you need to really just ask me if its not clear how exactly and we can go down to the fundamentals of physics if thats what it takes.

## how it works

imagine you have a d1 mini,

we will bodge some sort of asyncch webserver on that that does nothing but act as like physical nodes in a network

they are flashed with firmware that just makes api calls to a llm endpoint somewhere in the network via http

and stores basic information like its own identity

then we will use crewai as the actual logic and then give it a task and see what happens

the first task i need to give is to have a bunch of employees write the source code to a well defined feature with clearly defined inputs and outputs

all the source code for the program will be written as python scripts that i run in visualstudio code with the in file python interpreter using # %% for cells
 
i.e. we will generate each individual part of the code just from a desription.

but we will have lots of these python scripts which can be chained together and eventually be run by a top level build script.

just using python.

the frontend will be absolutely minimal html and js and css because everything is just a node and we can use the absolute fundamentals to make beautiful stuff

i imagine each of the d1 minis is like a physical component i can talk about and share and give to you

## directory tree
