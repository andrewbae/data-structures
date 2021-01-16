# Single Linked List

## Features
* push
* pop
* delete

## Build
```
$ cmake -H. -Bbuild
$ ./run.sh #or cmake --build build
```

## Result
```
        node_info(node_head);
        printf("%p", node_pop(node_head, 0x2));
        node_delete(node_head, 0x3);
        node_info(node_head);

index: 0
fd: 0x7fefa1405840
addr: 0x7fefa1405820
data: fuck

index: 1
fd: 0x7fefa1405860
addr: 0x7fefa1405840
data: fuck

index: 2
fd: 0x7fefa1405880
addr: 0x7fefa1405860
data: fuck

index: 3
fd: 0x7fefa14058a0
addr: 0x7fefa1405880
data: fuck

index: 4
fd: 0x0
addr: 0x7fefa14058a0
data: fuck

0x7fefa1405860index: 0
fd: 0x7fefa1405840
addr: 0x7fefa1405820
data: fuck

index: 1
fd: 0x7fefa1405860
addr: 0x7fefa1405840
data: fuck

index: 2
fd: 0x7fefa1405880
addr: 0x7fefa1405860
data: fuck

index: 3
fd: 0x0
addr: 0x7fefa1405880
data:

```
