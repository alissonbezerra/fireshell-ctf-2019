## leakless

## Description

Who does need a leak nowadays?

## Flag

	F#{y3ah!!_y0u_d1d_1t!_C0ngr4tz}

## Instructions to build the image

* compile the `leakless` binary;  
```
$ cd pwn/leakless/src
$ make leakless
```

* copy the binary to the `docker` directory
```
$ cp leakless ../docker
```


* build the container
```
$ cd ../docker
$ docker build -t leakless .
```
