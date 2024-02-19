# authentication

authentication will be done with a hardcoded token

this node owns its private key and eventually this will be handled better.

we will implement it as a simple hardcoded string

```cpp
const char* PRIVATE_KEY="THIS_NODE_PRIVATE_KEY";
```

## using python script

if you use the python script to write the cpp file

you need to define the actual private key in the .env

for now this will be disabled.