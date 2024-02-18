# node identity

nodes in our network have their own identity.

they are their own personality

we can chat with each node in context

nodes are uniquely identified by an id

## node

when i think of a node i need to think of a graph or a tree

i guess trees are just subcategories of graphs afterall

so just graphs

the most fundamental information about nodes is an id and a name

i also want to analyze with respect to time

so each node need a timestamp

also i want to know where each node comes from

i will call this origin and it is a bit arbitrary but generally describes where the node comes from

### schema

this leads to the following simple schema

```yaml
- id
- name
- timestamp
- origin
```

in cpp it would be simply constants like this for the root node:

```cpp
struct Node {
  String id;
  String name;
  String timestamp;
  String origin;
};

Node root = {
    "rootroot-1ba0-4d33-8f9f-b93563cc936f",
    "root",
    "REPLACEME",
    "m-c-frank/celium-experiments",
};

String nodeToString(Node node){
    return "id: " + node.id + ", name: " + node.name + ", timestamp: " + node.timestamp + ", origin: " + node.origin;
}
```