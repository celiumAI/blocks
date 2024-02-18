# authentication

authentication will be done with a hardcoded token

this token is a private key and we will have our central certificate authority set up aswell.

we will implement it as a simple hardcoded string

```cpp
const char* AUTH_TOKEN="super secret root key";
```